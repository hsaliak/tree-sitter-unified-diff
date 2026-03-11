
#include "unified_diff_parser.h"

#include <stdio.h>
#include <string.h>

static int assert_eq_size(const char *name, size_t actual, size_t expected) {
    if (actual != expected) {
        fprintf(stderr, "assert failed: %s expected=%zu actual=%zu\n", name, expected, actual);
        return 1;
}

    return 0;
}

static int test_one_file_one_hunk(void) {
    static const char *input =
        "--- a.txt\n"
        "+++ b.txt\n"
        "@@ -1 +1,2 @@\n"
        " line1\n"
        "+line2\n";

    udiff_parse_result result;
    if (udiff_parse_text(input, strlen(input), &result) != UDIFF_PARSE_OK) {
        return 1;
    }

    return assert_eq_size("file_patches", result.file_patches, 1) |
           assert_eq_size("hunks", result.hunks, 1) |
           assert_eq_size("context_lines", result.context_lines, 1) |
           assert_eq_size("addition_lines", result.addition_lines, 1) |
           assert_eq_size("error_lines", result.error_lines, 0);
}

static int test_multiple_hunks(void) {
    static const char *input =
        "--- a.txt\n"
        "+++ b.txt\n"
        "@@ -1 +1 @@\n"
        "-a\n"
        "+A\n"
        "@@ -3 +3 @@\n"
        "-c\n"
        "+C\n";

    udiff_parse_result result;
    if (udiff_parse_text(input, strlen(input), &result) != UDIFF_PARSE_OK) {
        return 1;
    }

    return assert_eq_size("hunks", result.hunks, 2) |
           assert_eq_size("deletion_lines", result.deletion_lines, 2) |
           assert_eq_size("addition_lines", result.addition_lines, 2);
}

static int test_multiple_file_patches(void) {
    static const char *input =
        "--- a.txt\n"
        "+++ b.txt\n"
        "@@ -1 +1 @@\n"
        "-a\n"
        "+A\n"
        "--- c.txt\n"
        "+++ d.txt\n"
        "@@ -1 +1 @@\n"
        "-x\n"
        "+X\n";

    udiff_parse_result result;
    if (udiff_parse_text(input, strlen(input), &result) != UDIFF_PARSE_OK) {
        return 1;
    }
    return assert_eq_size("file_patches", result.file_patches, 2) |
           assert_eq_size("from_file_lines", result.from_file_lines, 2) |
           assert_eq_size("to_file_lines", result.to_file_lines, 2);
}

static int test_note_and_preamble(void) {
    static const char *input =
        "diff --git a/a.txt b/b.txt\n"
        "--- a.txt\n"
        "+++ b.txt\n"
        "@@ -1 +1 @@ section\n"
        "-a\n"
        "+b\n"
        "\\ No newline at end of file\n";

    udiff_parse_result result;
    if (udiff_parse_text(input, strlen(input), &result) != UDIFF_PARSE_OK) {
        return 1;
    }
    return assert_eq_size("preamble_lines", result.preamble_lines, 1) |
           assert_eq_size("note_lines", result.note_lines, 1) |
           assert_eq_size("hunks", result.hunks, 1);
}

static int test_invalid_hunk_classified_error(void) {
    static const char *input =
        "--- a.txt\n"
        "+++ b.txt\n"
        "@@ bad @@\n";

    udiff_parse_result result;
    if (udiff_parse_text(input, strlen(input), &result) != UDIFF_PARSE_OK) {
        return 1;
    }
    return assert_eq_size("hunks", result.hunks, 0) |
           assert_eq_size("error_lines", result.error_lines, 1);
}

int main(void) {
    int failures = 0;

    failures += test_one_file_one_hunk();
    failures += test_multiple_hunks();
    failures += test_multiple_file_patches();
    failures += test_note_and_preamble();
    failures += test_invalid_hunk_classified_error();

    if (failures != 0) {
        fprintf(stderr, "unified_diff_tests: %d failing assertions\n", failures);
        return 1;
    }

    printf("unified_diff_tests: ok\n");
    return 0;
}
