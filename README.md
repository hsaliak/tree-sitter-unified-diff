# tree-sitter-unified-diff

Tree-sitter grammar for parsing unified diff files

## Repository layout

- Grammar: `grammar.js`
- Generated parser artifacts: `src/parser.c`, `src/grammar.json`, `src/node-types.json`
- Tree-sitter runtime headers (vendored): `src/tree_sitter/*.h`
- Corpus tests: `test/corpus/unified_diff.txt`
- Highlight queries: `queries/highlights.scm`
- Tree-sitter config: `tree-sitter.json`

## Prerequisites

- Node.js + npm
- Tree-sitter CLI

Install CLI (if needed):

```bash
npm install -g tree-sitter-cli
```

or use npx without global install:

```bash
npx tree-sitter generate
```

## Development workflow

Install dependencies (optional but recommended for script-based usage):

```bash
npm install
```

Generate parser artifacts:

```bash
npm run generate
# or: tree-sitter generate
```

Run grammar corpus tests:

```bash
npm test
# or: tree-sitter test
```

## What this grammar parses

- preamble lines before file patches
- file headers:
  - `--- <path>`
  - `+++ <path>`
- hunk headers:
  - `@@ -start[,count] +start[,count] @@[ section]`
- hunk body lines:
  - context (` `)
  - additions (`+`)
  - deletions (`-`)
  - note (`\ No newline at end of file`)
- multiple file patches in one document

## Using this grammar

This repository is a standard Tree-sitter grammar package. Typical consumption paths:

```bash
npm pack
```

Then use the packaged grammar from your Tree-sitter binding/tooling environment (Node, Rust, Python, etc.) as configured by `tree-sitter.json`.

For parser development:

```bash
tree-sitter parse path/to/file.diff
```
