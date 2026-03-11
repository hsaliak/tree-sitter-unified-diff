
#include "unified_diff_parser.h"

#include <stdio.h>
#include <string.h>

int main(void) {
    static const char *example_diff =
        "diff --git a/hello.txt b/hello.txt\n"
        "--- a/hello.txt\n"
        "+++ b/hello.txt\n"
        "@@ -1,2 +1,3 @@ greeting\n"
        " hello\n"
        "-world\n"
        "+there\n"
        "+!\n"
        "\\ No newline at end of file\n";

    udiff_parse_result result;
    udiff_parse_status status =
        udiff_parse_text(example_diff, strlen(example_diff), &result);

    if (status != UDIFF_PARSE_OK) {
        fprintf(stderr, "parse failed with status=%d\n", (int)status);
        return 1;
    }

    printf("Unified diff parse summary\n");
    printf("--------------------------\n");
    printf("source_file_nodes: %zu\n", result.source_file_nodes);
    printf("total_lines:       %zu\n", result.total_lines);
    printf("preamble_lines:    %zu\n", result.preamble_lines);
    printf("file_patches:      %zu\n", result.file_patches);
    printf("from_file_lines:   %zu\n", result.from_file_lines);
    printf("to_file_lines:     %zu\n", result.to_file_lines);
    printf("hunks:             %zu\n", result.hunks);
    printf("context_lines:     %zu\n", result.context_lines);
    printf("addition_lines:    %zu\n", result.addition_lines);
    printf("deletion_lines:    %zu\n", result.deletion_lines);
    printf("note_lines:        %zu\n", result.note_lines);
    printf("error_lines:       %zu\n", result.error_lines);

    return 0;
}
