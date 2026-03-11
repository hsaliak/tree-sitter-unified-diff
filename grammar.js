
module.exports = grammar({
  name: "unified_diff",

  extras: ($) => [],

  rules: {
    source_file: ($) =>
      repeat(choice(prec(2, $.file_patch), $.preamble_line, $.blank_line)),

    file_patch: ($) =>
      seq($.from_file_line, "\n", $.to_file_line, "\n", repeat1($.hunk)),

    hunk: ($) =>
      seq(
        $.hunk_header,
        "\n",
        repeat1(
          choice($.context_line, $.addition_line, $.deletion_line, $.note_line),
        ),
      ),

    from_file_line: (_$) => token(prec(3, /--- [^\n]*/)),
    to_file_line: (_$) => token(prec(3, /\+\+\+ [^\n]*/)),
    hunk_header: (_$) =>
      token(prec(3, /@@ -[0-9]+(,[0-9]+)? \+[0-9]+(,[0-9]+)? @@[^\n]*/)),

    context_line: (_$) => token(prec(2, seq(" ", /[^\n]*/, "\n"))),
    addition_line: (_$) => token(prec(2, seq("+", /[^\n]*/, "\n"))),
    deletion_line: (_$) => token(prec(2, seq("-", /[^\n]*/, "\n"))),
    note_line: (_$) => token(prec(2, seq("\\ No newline at end of file", "\n"))),

    preamble_line: (_$) => token(prec(1, seq(/[^\n]+/, "\n"))),
    blank_line: (_$) => "\n",
  },
});