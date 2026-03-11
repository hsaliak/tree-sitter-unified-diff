
#ifndef UNIFIED_DIFF_PARSER_H
#define UNIFIED_DIFF_PARSER_H

#include <stdbool.h>
#include <stddef.h>

typedef struct {
    size_t source_file_nodes;
    size_t preamble_lines;
    size_t file_patches;
    size_t from_file_lines;
    size_t to_file_lines;
    size_t hunks;
    size_t context_lines;
    size_t addition_lines;
    size_t deletion_lines;
    size_t note_lines;
    size_t error_lines;
    size_t total_lines;
} udiff_parse_result;

typedef enum {
    UDIFF_PARSE_OK = 0,
    UDIFF_PARSE_INVALID_ARGUMENT = 1,
} udiff_parse_status;

void udiff_parse_result_init(udiff_parse_result *result);

udiff_parse_status udiff_parse_text(
    const char *input,
    size_t input_len,
    udiff_parse_result *out_result
);

#endif
