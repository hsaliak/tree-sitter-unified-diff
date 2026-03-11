# tree-sitter-unified-diff

Tree-sitter grammar for parsing unified diff files.

This project is now **tree-sitter-first**:

- Grammar: `grammar.js`
- Generated parser: `src/parser.c`, `src/grammar.json`, `src/node-types.json`
- Corpus tests: `test/corpus/unified_diff.txt`
- Highlight queries: `queries/highlights.scm`
- Tree-sitter config: `tree-sitter.json`

## Primary workflow (tree-sitter)

### Prerequisites

- `tree-sitter` CLI installed (`tree-sitter --version`)

### Generate parser artifacts

```bash
tree-sitter generate
```

### Run grammar tests

```bash
tree-sitter test
```

## Grammar coverage (current)

- Preamble lines before file patches
- File headers:
  - `--- <path>`
  - `+++ <path>`
- Hunk headers:
  - `@@ -start[,count] +start[,count] @@[ section]`
- Hunk body lines:
  - context (` `)
  - additions (`+`)
  - deletions (`-`)
  - note (`\ No newline at end of file`)
- Multiple file patches in one document

## Repository notes

The repository still contains a standalone C parser library under:

- `include/unified_diff_parser.h`
- `src/unified_diff_parser.c`

That C parser is retained as auxiliary/reference code. The project objective is
the tree-sitter grammar and corpus-based validation.

## Optional C build/test flow (legacy helper)

```bash
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

ASan variant:

```bash
cmake -S . -B build-asan -DUSE_ASAN=ON
cmake --build build-asan
ctest --test-dir build-asan --output-on-failure
```
