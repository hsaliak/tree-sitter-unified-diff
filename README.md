# Unified Diff Parser (C23)

This repository now includes a C23 unified diff parser implementation plus tests
and an example program.

## What is implemented

- Unified diff parser library:
  - Header: `include/unified_diff_parser.h`
  - Source: `src/unified_diff_parser.c`
- Tests (ctest): `tests/unified_diff_tests.c`
- Example program: `examples/unified_diff_example.c`
- Specification:
  - Parse-tree spec: `docs/unified_diff_tree_spec.md`
  - API notes: `docs/unified_diff_parser_api.md`

Current parser API returns aggregate parse counters (not yet a full AST object).

## Build

```bash
cmake -S . -B build
cmake --build build
```

Build outputs include:

- `main`
- `unified_diff_tests`
- `unified_diff_example`

## Run tests (ctest)

```bash
ctest --test-dir build --output-on-failure
```

## Run tests with ASan

```bash
cmake -S . -B build-asan -DUSE_ASAN=ON
cmake --build build-asan
ctest --test-dir build-asan --output-on-failure
```

## Run the example parser program

```bash
./build/unified_diff_example
```

Expected output shape (example):

```text
Unified diff parse summary
--------------------------
source_file_nodes: 1
total_lines:       9
preamble_lines:    1
file_patches:      1
from_file_lines:   1
to_file_lines:     1
hunks:             1
context_lines:     1
addition_lines:    2
deletion_lines:    1
note_lines:        1
error_lines:       0
```

## API Quick Start

```c
#include "unified_diff_parser.h"
#include <string.h>

udiff_parse_result result;
udiff_parse_status st = udiff_parse_text(diff, strlen(diff), &result);
if (st == UDIFF_PARSE_OK) {
    // inspect result counters
}
```

For full API details, see `docs/unified_diff_parser_api.md`.
