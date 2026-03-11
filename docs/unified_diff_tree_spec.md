
# Unified Diff Parse Tree 

## 1. Purpose

This document defines the specification for parsing GNU-style
**unified diff** text into a stable concrete syntax tree suitable for
highlighting and structural tooling.

Source basis:

1. Tree-sitter grammar-writing guidance (intuitive CST, LR(1)-friendly design,
   precedence/conflict discipline).
2. GNU diffutils unified format and detailed unified hunk semantics.

## 2. Authoritative Format Anchors

The parser must recognize these mandatory anchors:

1. File header lines:
   - `--- ...`
   - `+++ ...`
2. Hunk header line:
   - `@@ -old_range +new_range @@` with optional trailing section text.
3. Hunk body prefixes:
   - space (` `): context
   - plus (`+`): addition
   - minus (`-`): deletion
4. Marker line:
   - `\ No newline at end of file`

Range semantics from GNU detailed unified format:

- single-line range may appear as just `start`
- multi-line range appears as `start,count`

## 3. Input Model

- Treat input as UTF-8 bytes split by `\n`.
- Parser is line-based.
- Every physical input line must appear in output either as a recognized node
  or a recoverable error node.

## 4. Grammar Contract (Structural)

### 4.1 Root

- `source_file`
  - `preamble_line*`
  - `file_patch+`

`preamble_line` captures non-core lines before the first recognized file patch.

### 4.2 File Patch

- `file_patch`
  - `from_file_line`
  - `to_file_line`
  - `hunk+`

### 4.3 Hunk

- `hunk`
  - `hunk_header`
    - `old_range`
      - `old_start`
      - `old_count?`
    - `new_range`
      - `new_start`
      - `new_count?`
    - `section_text?`
  - `hunk_line*`

## 4.4 Hunk Line Variants

- `context_line`
- `addition_line`
- `deletion_line`
- `note_line`
- `error_line` (recovery)

## 5. Lexical/Parsing Rules

1. `from_file_line` must begin with literal `--- `.
2. `to_file_line` must begin with literal `+++ `.
3. `hunk_header` must begin with literal `@@ ` and include a second ` @@`
   delimiter region.
4. Old/new ranges use unsigned decimal integers.
5. Optional counts are introduced by comma: `start,count`.
6. Any payload after `--- ` / `+++ ` is opaque text in v1 (path + optional
   metadata such as timestamps).

## 6. Error Handling / Recovery

Strict core constraints:

- A `file_patch` requires `---` followed by `+++` before any hunks.
- A `hunk` requires a syntactically valid `hunk_header`.

Recovery policy:

- Before first file patch, unknown lines -> `preamble_line`.
- Within hunk bodies, non-matching lines -> `error_line`.
- Recovery must preserve input ordering and avoid line drops.

## 7. Highlighting Mapping (Query-Agnostic)

Stable node-class intent:

- `from_file_line`, `to_file_line`: file header style
- `hunk_header`: hunk header style
- `addition_line`: added text style
- `deletion_line`: removed text style
- `context_line`: neutral/context style
- `note_line`: meta/warning style

Capture names are implementation-defined, but node names above are the contract.
