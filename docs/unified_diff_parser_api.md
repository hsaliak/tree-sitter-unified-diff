
# Unified Diff Parser API

This project includes a simple C23 unified diff parser in:

- Header: `include/unified_diff_parser.h`
- Implementation: `src/unified_diff_parser.c`

Current API returns a structural summary (line and section counts), which is
useful for validation and integration while the full AST model evolves.

## Public Types

### `udiff_parse_result`

Holds aggregate counters produced by parsing:

- `source_file_nodes`
- `preamble_lines`
- `file_patches`
- `from_file_lines`
- `to_file_lines`
- `hunks`
- `context_lines`
- `addition_lines`
- `deletion_lines`
- `note_lines`
- `error_lines`
- `total_lines`

### `udiff_parse_status`

- `UDIFF_PARSE_OK`
- `UDIFF_PARSE_INVALID_ARGUMENT`

## Functions

### `void udiff_parse_result_init(udiff_parse_result *result)`

Initializes a result structure to zero. Safe no-op for `NULL` pointer.

### `udiff_parse_status udiff_parse_text(const char *input, size_t input_len, udiff_parse_result *out_result)`

Parses unified diff text.

Inputs:

- `input`: pointer to diff bytes (UTF-8 text)
- `input_len`: number of bytes to parse
- `out_result`: output struct to receive summary counters

Returns:

- `UDIFF_PARSE_OK` on success
- `UDIFF_PARSE_INVALID_ARGUMENT` if `input == NULL` or `out_result == NULL`

## Recognized Syntax (v1)

- File headers: `--- ...` and `+++ ...`
- Hunk headers: `@@ -old[,count] +new[,count] @@` (optional trailing section)
- Hunk body lines:
  - `' '` context
  - `'+'` addition
  - `'-'` deletion
  - `\ No newline at end of file` note

Non-matching lines are classified as `error_lines` according to parser state.

## Example Program

See `examples/unified_diff_example.c`.

Build and run:

```bash
cmake -S . -B build
cmake --build build
./build/unified_diff_example
```

## Testing

Normal test run:

```bash
ctest --test-dir build --output-on-failure
```

ASan run:

```bash
cmake -S . -B build-asan -DUSE_ASAN=ON
cmake --build build-asan
ctest --test-dir build-asan --output-on-failure
```
