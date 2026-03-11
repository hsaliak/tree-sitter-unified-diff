
#include "unified_diff_parser.h"

#include <string.h>

typedef enum {
    PARSER_STATE_PREAMBLE = 0,
    PARSER_STATE_EXPECT_TO_FILE,
    PARSER_STATE_EXPECT_HUNK_OR_FROM,
    PARSER_STATE_IN_HUNK,
} parser_state;

static bool starts_with(const char *line, size_t len, const char *prefix) {
    size_t prefix_len = strlen(prefix);
    return len >= prefix_len && strncmp(line, prefix, prefix_len) == 0;
}

static bool is_range_number(const char *text, size_t len, size_t *consumed) {
    size_t i = 0;
    if (len == 0 || text[0] < '0' || text[0] > '9') {
        return false;
    }
    while (i < len && text[i] >= '0' && text[i] <= '9') {
        i++;
    }
    if (i < len && text[i] == ',') {
        size_t j = i + 1;
        if (j >= len || text[j] < '0' || text[j] > '9') {
            return false;
        }
        while (j < len && text[j] >= '0' && text[j] <= '9') {
            j++;
        }
        i = j;
    }
    *consumed = i;
    return true;
}

static bool is_hunk_header(const char *line, size_t len) {
    if (!starts_with(line, len, "@@ -")) {
        return false;
    }

    size_t i = 4; // after "@@ -"
    size_t consumed = 0;
    if (!is_range_number(line + i, len - i, &consumed)) {
        return false;
    }
    i += consumed;

    if (i >= len || line[i] != ' ') {
        return false;
    }
    i++;

    if (i >= len || line[i] != '+') {
        return false;
    }
    i++;

    if (!is_range_number(line + i, len - i, &consumed)) {
        return false;
    }
    i += consumed;

    if (i + 3 > len) {
        return false;
    }

    return strncmp(line + i, " @@", 3) == 0;
}

static bool next_line_is_to_file_header(
    const char *input,
    size_t input_len,
    size_t current_line_end
) {
    if (current_line_end >= input_len || input[current_line_end] != '\n') {
        return false;
    }

    size_t next_start = current_line_end + 1;
    size_t next_end = next_start;
    while (next_end < input_len && input[next_end] != '\n') {
        next_end++;
    }
    return starts_with(input + next_start, next_end - next_start, "+++ ");
}

void udiff_parse_result_init(udiff_parse_result *result) {
    if (result == NULL) {
        return;
    }
    memset(result, 0, sizeof(*result));
}

udiff_parse_status udiff_parse_text(
    const char *input,
    size_t input_len,
    udiff_parse_result *out_result
) {
    if (input == NULL || out_result == NULL) {
        return UDIFF_PARSE_INVALID_ARGUMENT;
    }

    udiff_parse_result_init(out_result);
    out_result->source_file_nodes = 1;

    parser_state state = PARSER_STATE_PREAMBLE;
    size_t line_start = 0;

    while (line_start < input_len) {
        size_t line_end = line_start;
        while (line_end < input_len && input[line_end] != '\n') {
            line_end++;
        }

        const char *line = input + line_start;
        size_t line_len = line_end - line_start;
        out_result->total_lines++;

        bool consumed_newline = (line_end < input_len && input[line_end] == '\n');

        switch (state) {
            case PARSER_STATE_PREAMBLE:
                if (starts_with(line, line_len, "--- ")) {
                    out_result->from_file_lines++;
                    out_result->file_patches++;
                    state = PARSER_STATE_EXPECT_TO_FILE;
                } else {
                    out_result->preamble_lines++;
                }
                break;
            case PARSER_STATE_EXPECT_TO_FILE:
                if (starts_with(line, line_len, "+++ ")) {
                    out_result->to_file_lines++;
                    state = PARSER_STATE_EXPECT_HUNK_OR_FROM;
                } else {
                    out_result->error_lines++;
                }
                break;
            case PARSER_STATE_EXPECT_HUNK_OR_FROM:
                if (is_hunk_header(line, line_len)) {
                    out_result->hunks++;
                    state = PARSER_STATE_IN_HUNK;
                } else if (starts_with(line, line_len, "--- ")) {
                    out_result->from_file_lines++;
                    out_result->file_patches++;
                    state = PARSER_STATE_EXPECT_TO_FILE;
                } else {
                    out_result->error_lines++;
                }
                break;
            case PARSER_STATE_IN_HUNK:
                if (is_hunk_header(line, line_len)) {
                    out_result->hunks++;
                } else if (
                    starts_with(line, line_len, "--- ") &&
                    next_line_is_to_file_header(input, input_len, line_end)
                ) {
                    out_result->from_file_lines++;
                    out_result->file_patches++;
                    state = PARSER_STATE_EXPECT_TO_FILE;
                } else if (line_len > 0 && line[0] == ' ') {
                    out_result->context_lines++;
                } else if (line_len > 0 && line[0] == '+') {
                    out_result->addition_lines++;
                } else if (line_len > 0 && line[0] == '-') {
                    out_result->deletion_lines++;
                } else if (starts_with(line, line_len, "\\ No newline at end of file")) {
                    out_result->note_lines++;
                } else {
                    out_result->error_lines++;
                }
                break;
        }

        line_start = consumed_newline ? (line_end + 1) : line_end;
    }

    return UDIFF_PARSE_OK;
}
