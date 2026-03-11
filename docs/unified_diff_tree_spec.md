
# Unified Diff Parse Tree Specification (v1.0, C23-Oriented)

## 1. Purpose

This document defines an implementation-ready specification for parsing GNU-style
**unified diff** text into a stable concrete syntax tree suitable for
highlighting and structural tooling.

Source basis:

1. Tree-sitter grammar-writing guidance (intuitive CST, LR(1)-friendly design,
   precedence/conflict discipline).
2. GNU diffutils unified format and detailed unified hunk semantics.

This repository is C23-oriented; this spec does **not** require JavaScript
sources.

## 2. Scope and Constraints

- Input: text diff in unified format.
- Output: typed parse tree with stable node names.
- Parser style: line-oriented, lossless preservation of source lines.
- Non-goal in v1: full semantic validation of hunk counts against body lines.

## 3. Authoritative Format Anchors

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

## 4. Input Model

- Treat input as UTF-8 bytes split by `\n`.
- Parser is line-based.
- Every physical input line must appear in output either as a recognized node
  or a recoverable error node.

## 5. Grammar Contract (Structural)

### 5.1 Root

- `source_file`
  - `preamble_line*`
  - `file_patch+`

`preamble_line` captures non-core lines before the first recognized file patch.

### 5.2 File Patch

- `file_patch`
  - `from_file_line`
  - `to_file_line`
  - `hunk+`

### 5.3 Hunk

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

### 5.4 Hunk Line Variants

- `context_line`
- `addition_line`
- `deletion_line`
- `note_line`
- `error_line` (recovery)

## 6. Lexical/Parsing Rules

1. `from_file_line` must begin with literal `--- `.
2. `to_file_line` must begin with literal `+++ `.
3. `hunk_header` must begin with literal `@@ ` and include a second ` @@`
   delimiter region.
4. Old/new ranges use unsigned decimal integers.
5. Optional counts are introduced by comma: `start,count`.
6. Any payload after `--- ` / `+++ ` is opaque text in v1 (path + optional
   metadata such as timestamps).

## 7. Error Handling / Recovery

Strict core constraints:

- A `file_patch` requires `---` followed by `+++` before any hunks.
- A `hunk` requires a syntactically valid `hunk_header`.

Recovery policy:

- Before first file patch, unknown lines -> `preamble_line`.
- Within hunk bodies, non-matching lines -> `error_line`.
- Recovery must preserve input ordering and avoid line drops.

## 8. Highlighting Mapping (Query-Agnostic)

Stable node-class intent:

- `from_file_line`, `to_file_line`: file header style
- `hunk_header`: hunk header style
- `addition_line`: added text style
- `deletion_line`: removed text style
- `context_line`: neutral/context style
- `note_line`: meta/warning style

Capture names are implementation-defined, but node names above are the contract.

## 9. Compliance Tests (Minimum)

Required fixtures:

1. One file patch, one hunk.
2. One file patch, multiple hunks.
3. Multiple file patches in one document.
4. Hunk headers with omitted counts (`-N +M`).
5. Hunk header with trailing section text.
6. `\ No newline at end of file` marker in hunk body.
7. Leading preamble lines before first `---`.

Pass criteria:

- Valid fixtures parse without fatal failure.
- Tree shape matches Sections 5 and 6.
- Hunk body line classification is exact.

## 10. Non-Goals (v1)

- Typed parsing of git extended headers (`diff --git`, `index`, mode/rename,
  similarity, etc.).
- Cross-checking whether body line totals exactly match declared counts.
- Path unescaping/canonicalization beyond raw payload retention.

## 11. Versioning and Compatibility

- Spec version: `1.0`.
- Backward compatibility rule: existing node names in Sections 5 and 8 are
  stable for all `1.x` revisions.
- Future additions should be optional nodes/fields, not renames/removals.
