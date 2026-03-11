#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 16
#define LARGE_STATE_COUNT 4
#define SYMBOL_COUNT 17
#define ALIAS_COUNT 0
#define TOKEN_COUNT 10
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 1

enum ts_symbol_identifiers {
  anon_sym_LF = 1,
  sym_from_file_line = 2,
  sym_to_file_line = 3,
  sym_hunk_header = 4,
  sym_context_line = 5,
  sym_addition_line = 6,
  sym_deletion_line = 7,
  sym_note_line = 8,
  sym_preamble_line = 9,
  sym_source_file = 10,
  sym_file_patch = 11,
  sym_hunk = 12,
  sym_blank_line = 13,
  aux_sym_source_file_repeat1 = 14,
  aux_sym_file_patch_repeat1 = 15,
  aux_sym_hunk_repeat1 = 16,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_LF] = "\n",
  [sym_from_file_line] = "from_file_line",
  [sym_to_file_line] = "to_file_line",
  [sym_hunk_header] = "hunk_header",
  [sym_context_line] = "context_line",
  [sym_addition_line] = "addition_line",
  [sym_deletion_line] = "deletion_line",
  [sym_note_line] = "note_line",
  [sym_preamble_line] = "preamble_line",
  [sym_source_file] = "source_file",
  [sym_file_patch] = "file_patch",
  [sym_hunk] = "hunk",
  [sym_blank_line] = "blank_line",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_file_patch_repeat1] = "file_patch_repeat1",
  [aux_sym_hunk_repeat1] = "hunk_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_LF] = anon_sym_LF,
  [sym_from_file_line] = sym_from_file_line,
  [sym_to_file_line] = sym_to_file_line,
  [sym_hunk_header] = sym_hunk_header,
  [sym_context_line] = sym_context_line,
  [sym_addition_line] = sym_addition_line,
  [sym_deletion_line] = sym_deletion_line,
  [sym_note_line] = sym_note_line,
  [sym_preamble_line] = sym_preamble_line,
  [sym_source_file] = sym_source_file,
  [sym_file_patch] = sym_file_patch,
  [sym_hunk] = sym_hunk,
  [sym_blank_line] = sym_blank_line,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_file_patch_repeat1] = aux_sym_file_patch_repeat1,
  [aux_sym_hunk_repeat1] = aux_sym_hunk_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_LF] = {
    .visible = true,
    .named = false,
  },
  [sym_from_file_line] = {
    .visible = true,
    .named = true,
  },
  [sym_to_file_line] = {
    .visible = true,
    .named = true,
  },
  [sym_hunk_header] = {
    .visible = true,
    .named = true,
  },
  [sym_context_line] = {
    .visible = true,
    .named = true,
  },
  [sym_addition_line] = {
    .visible = true,
    .named = true,
  },
  [sym_deletion_line] = {
    .visible = true,
    .named = true,
  },
  [sym_note_line] = {
    .visible = true,
    .named = true,
  },
  [sym_preamble_line] = {
    .visible = true,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym_file_patch] = {
    .visible = true,
    .named = true,
  },
  [sym_hunk] = {
    .visible = true,
    .named = true,
  },
  [sym_blank_line] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_file_patch_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_hunk_repeat1] = {
    .visible = false,
    .named = false,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(90);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == ' ') ADVANCE(1);
      if (lookahead == '+') ADVANCE(3);
      if (lookahead == '-') ADVANCE(7);
      if (lookahead == '@') ADVANCE(27);
      if (lookahead == '\\') ADVANCE(10);
      if (lookahead != 0) ADVANCE(53);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(95);
      if (lookahead != 0) ADVANCE(1);
      END_STATE();
    case 2:
      if (lookahead == '\n') ADVANCE(96);
      if (lookahead == ' ') ADVANCE(93);
      if (lookahead != 0) ADVANCE(5);
      END_STATE();
    case 3:
      if (lookahead == '\n') ADVANCE(96);
      if (lookahead == '+') ADVANCE(4);
      if (lookahead != 0) ADVANCE(5);
      END_STATE();
    case 4:
      if (lookahead == '\n') ADVANCE(96);
      if (lookahead == '+') ADVANCE(2);
      if (lookahead != 0) ADVANCE(5);
      END_STATE();
    case 5:
      if (lookahead == '\n') ADVANCE(96);
      if (lookahead != 0) ADVANCE(5);
      END_STATE();
    case 6:
      if (lookahead == '\n') ADVANCE(97);
      if (lookahead == ' ') ADVANCE(92);
      if (lookahead != 0) ADVANCE(9);
      END_STATE();
    case 7:
      if (lookahead == '\n') ADVANCE(97);
      if (lookahead == '-') ADVANCE(8);
      if (lookahead != 0) ADVANCE(9);
      END_STATE();
    case 8:
      if (lookahead == '\n') ADVANCE(97);
      if (lookahead == '-') ADVANCE(6);
      if (lookahead != 0) ADVANCE(9);
      END_STATE();
    case 9:
      if (lookahead == '\n') ADVANCE(97);
      if (lookahead != 0) ADVANCE(9);
      END_STATE();
    case 10:
      if (lookahead == '\n') ADVANCE(99);
      if (lookahead == ' ') ADVANCE(29);
      if (lookahead != 0) ADVANCE(53);
      END_STATE();
    case 11:
      if (lookahead == '\n') ADVANCE(99);
      if (lookahead == ' ') ADVANCE(92);
      if (lookahead != 0) ADVANCE(53);
      END_STATE();
    case 12:
      if (lookahead == '\n') ADVANCE(99);
      if (lookahead == ' ') ADVANCE(42);
      if (lookahead != 0) ADVANCE(53);
      END_STATE();
    case 13:
      if (lookahead == '\n') ADVANCE(99);
      if (lookahead == ' ') ADVANCE(30);
      if (lookahead != 0) ADVANCE(53);
      END_STATE();
    case 14:
      if (lookahead == '\n') ADVANCE(99);
      if (lookahead == ' ') ADVANCE(28);
      if (lookahead == ',') ADVANCE(52);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(14);
      if (lookahead != 0) ADVANCE(53);
      END_STATE();
    case 15:
      if (lookahead == '\n') ADVANCE(99);
      if (lookahead == ' ') ADVANCE(28);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(15);
      if (lookahead != 0) ADVANCE(53);
      END_STATE();
    case 16:
      if (lookahead == '\n') ADVANCE(99);
      if (lookahead == ' ') ADVANCE(45);
      if (lookahead != 0) ADVANCE(53);
      END_STATE();
    case 17:
      if (lookahead == '\n') ADVANCE(99);
      if (lookahead == ' ') ADVANCE(36);
      if (lookahead != 0) ADVANCE(53);
      END_STATE();
    case 18:
      if (lookahead == '\n') ADVANCE(99);
      if (lookahead == ' ') ADVANCE(22);
      if (lookahead == ',') ADVANCE(50);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(18);
      if (lookahead != 0) ADVANCE(53);
      END_STATE();
    case 19:
      if (lookahead == '\n') ADVANCE(99);
      if (lookahead == ' ') ADVANCE(22);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(19);
      if (lookahead != 0) ADVANCE(53);
      END_STATE();
    case 20:
      if (lookahead == '\n') ADVANCE(99);
      if (lookahead == ' ') ADVANCE(23);
      if (lookahead != 0) ADVANCE(53);
      END_STATE();
    case 21:
      if (lookahead == '\n') ADVANCE(99);
      if (lookahead == ' ') ADVANCE(33);
      if (lookahead != 0) ADVANCE(53);
      END_STATE();
    case 22:
      if (lookahead == '\n') ADVANCE(99);
      if (lookahead == '+') ADVANCE(51);
      if (lookahead != 0) ADVANCE(53);
      END_STATE();
    case 23:
      if (lookahead == '\n') ADVANCE(99);
      if (lookahead == '-') ADVANCE(49);
      if (lookahead != 0) ADVANCE(53);
      END_STATE();
    case 24:
      if (lookahead == '\n') ADVANCE(99);
      if (lookahead == '-') ADVANCE(25);
      if (lookahead != 0) ADVANCE(53);
      END_STATE();
    case 25:
      if (lookahead == '\n') ADVANCE(99);
      if (lookahead == '-') ADVANCE(11);
      if (lookahead != 0) ADVANCE(53);
      END_STATE();
    case 26:
      if (lookahead == '\n') ADVANCE(99);
      if (lookahead == '@') ADVANCE(94);
      if (lookahead != 0) ADVANCE(53);
      END_STATE();
    case 27:
      if (lookahead == '\n') ADVANCE(99);
      if (lookahead == '@') ADVANCE(20);
      if (lookahead != 0) ADVANCE(53);
      END_STATE();
    case 28:
      if (lookahead == '\n') ADVANCE(99);
      if (lookahead == '@') ADVANCE(26);
      if (lookahead != 0) ADVANCE(53);
      END_STATE();
    case 29:
      if (lookahead == '\n') ADVANCE(99);
      if (lookahead == 'N') ADVANCE(46);
      if (lookahead != 0) ADVANCE(53);
      END_STATE();
    case 30:
      if (lookahead == '\n') ADVANCE(99);
      if (lookahead == 'a') ADVANCE(47);
      if (lookahead != 0) ADVANCE(53);
      END_STATE();
    case 31:
      if (lookahead == '\n') ADVANCE(99);
      if (lookahead == 'd') ADVANCE(16);
      if (lookahead != 0) ADVANCE(53);
      END_STATE();
    case 32:
      if (lookahead == '\n') ADVANCE(99);
      if (lookahead == 'e') ADVANCE(48);
      if (lookahead != 0) ADVANCE(53);
      END_STATE();
    case 33:
      if (lookahead == '\n') ADVANCE(99);
      if (lookahead == 'e') ADVANCE(43);
      if (lookahead != 0) ADVANCE(53);
      END_STATE();
    case 34:
      if (lookahead == '\n') ADVANCE(99);
      if (lookahead == 'e') ADVANCE(55);
      if (lookahead != 0) ADVANCE(53);
      END_STATE();
    case 35:
      if (lookahead == '\n') ADVANCE(99);
      if (lookahead == 'e') ADVANCE(13);
      if (lookahead != 0) ADVANCE(53);
      END_STATE();
    case 36:
      if (lookahead == '\n') ADVANCE(99);
      if (lookahead == 'f') ADVANCE(38);
      if (lookahead != 0) ADVANCE(53);
      END_STATE();
    case 37:
      if (lookahead == '\n') ADVANCE(99);
      if (lookahead == 'f') ADVANCE(17);
      if (lookahead != 0) ADVANCE(53);
      END_STATE();
    case 38:
      if (lookahead == '\n') ADVANCE(99);
      if (lookahead == 'i') ADVANCE(41);
      if (lookahead != 0) ADVANCE(53);
      END_STATE();
    case 39:
      if (lookahead == '\n') ADVANCE(99);
      if (lookahead == 'i') ADVANCE(44);
      if (lookahead != 0) ADVANCE(53);
      END_STATE();
    case 40:
      if (lookahead == '\n') ADVANCE(99);
      if (lookahead == 'l') ADVANCE(39);
      if (lookahead != 0) ADVANCE(53);
      END_STATE();
    case 41:
      if (lookahead == '\n') ADVANCE(99);
      if (lookahead == 'l') ADVANCE(34);
      if (lookahead != 0) ADVANCE(53);
      END_STATE();
    case 42:
      if (lookahead == '\n') ADVANCE(99);
      if (lookahead == 'n') ADVANCE(32);
      if (lookahead != 0) ADVANCE(53);
      END_STATE();
    case 43:
      if (lookahead == '\n') ADVANCE(99);
      if (lookahead == 'n') ADVANCE(31);
      if (lookahead != 0) ADVANCE(53);
      END_STATE();
    case 44:
      if (lookahead == '\n') ADVANCE(99);
      if (lookahead == 'n') ADVANCE(35);
      if (lookahead != 0) ADVANCE(53);
      END_STATE();
    case 45:
      if (lookahead == '\n') ADVANCE(99);
      if (lookahead == 'o') ADVANCE(37);
      if (lookahead != 0) ADVANCE(53);
      END_STATE();
    case 46:
      if (lookahead == '\n') ADVANCE(99);
      if (lookahead == 'o') ADVANCE(12);
      if (lookahead != 0) ADVANCE(53);
      END_STATE();
    case 47:
      if (lookahead == '\n') ADVANCE(99);
      if (lookahead == 't') ADVANCE(21);
      if (lookahead != 0) ADVANCE(53);
      END_STATE();
    case 48:
      if (lookahead == '\n') ADVANCE(99);
      if (lookahead == 'w') ADVANCE(40);
      if (lookahead != 0) ADVANCE(53);
      END_STATE();
    case 49:
      if (lookahead == '\n') ADVANCE(99);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(18);
      if (lookahead != 0) ADVANCE(53);
      END_STATE();
    case 50:
      if (lookahead == '\n') ADVANCE(99);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(19);
      if (lookahead != 0) ADVANCE(53);
      END_STATE();
    case 51:
      if (lookahead == '\n') ADVANCE(99);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(14);
      if (lookahead != 0) ADVANCE(53);
      END_STATE();
    case 52:
      if (lookahead == '\n') ADVANCE(99);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(15);
      if (lookahead != 0) ADVANCE(53);
      END_STATE();
    case 53:
      if (lookahead == '\n') ADVANCE(99);
      if (lookahead != 0) ADVANCE(53);
      END_STATE();
    case 54:
      if (lookahead == '\n') ADVANCE(98);
      END_STATE();
    case 55:
      if (lookahead == '\n') ADVANCE(98);
      if (lookahead != 0) ADVANCE(53);
      END_STATE();
    case 56:
      if (lookahead == ' ') ADVANCE(1);
      if (lookahead == '+') ADVANCE(5);
      if (lookahead == '-') ADVANCE(9);
      if (lookahead == '\\') ADVANCE(58);
      END_STATE();
    case 57:
      if (lookahead == ' ') ADVANCE(93);
      END_STATE();
    case 58:
      if (lookahead == ' ') ADVANCE(67);
      END_STATE();
    case 59:
      if (lookahead == ' ') ADVANCE(80);
      END_STATE();
    case 60:
      if (lookahead == ' ') ADVANCE(68);
      END_STATE();
    case 61:
      if (lookahead == ' ') ADVANCE(83);
      END_STATE();
    case 62:
      if (lookahead == ' ') ADVANCE(74);
      END_STATE();
    case 63:
      if (lookahead == ' ') ADVANCE(72);
      END_STATE();
    case 64:
      if (lookahead == '+') ADVANCE(65);
      END_STATE();
    case 65:
      if (lookahead == '+') ADVANCE(57);
      END_STATE();
    case 66:
      if (lookahead == '+') ADVANCE(64);
      END_STATE();
    case 67:
      if (lookahead == 'N') ADVANCE(84);
      END_STATE();
    case 68:
      if (lookahead == 'a') ADVANCE(85);
      END_STATE();
    case 69:
      if (lookahead == 'd') ADVANCE(61);
      END_STATE();
    case 70:
      if (lookahead == 'e') ADVANCE(86);
      END_STATE();
    case 71:
      if (lookahead == 'e') ADVANCE(54);
      END_STATE();
    case 72:
      if (lookahead == 'e') ADVANCE(81);
      END_STATE();
    case 73:
      if (lookahead == 'e') ADVANCE(60);
      END_STATE();
    case 74:
      if (lookahead == 'f') ADVANCE(76);
      END_STATE();
    case 75:
      if (lookahead == 'f') ADVANCE(62);
      END_STATE();
    case 76:
      if (lookahead == 'i') ADVANCE(79);
      END_STATE();
    case 77:
      if (lookahead == 'i') ADVANCE(82);
      END_STATE();
    case 78:
      if (lookahead == 'l') ADVANCE(77);
      END_STATE();
    case 79:
      if (lookahead == 'l') ADVANCE(71);
      END_STATE();
    case 80:
      if (lookahead == 'n') ADVANCE(70);
      END_STATE();
    case 81:
      if (lookahead == 'n') ADVANCE(69);
      END_STATE();
    case 82:
      if (lookahead == 'n') ADVANCE(73);
      END_STATE();
    case 83:
      if (lookahead == 'o') ADVANCE(75);
      END_STATE();
    case 84:
      if (lookahead == 'o') ADVANCE(59);
      END_STATE();
    case 85:
      if (lookahead == 't') ADVANCE(63);
      END_STATE();
    case 86:
      if (lookahead == 'w') ADVANCE(78);
      END_STATE();
    case 87:
      if (eof) ADVANCE(90);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == ' ') ADVANCE(1);
      if (lookahead == '+') ADVANCE(5);
      if (lookahead == '-') ADVANCE(7);
      if (lookahead == '@') ADVANCE(27);
      if (lookahead == '\\') ADVANCE(10);
      if (lookahead != 0) ADVANCE(53);
      END_STATE();
    case 88:
      if (eof) ADVANCE(90);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '-') ADVANCE(24);
      if (lookahead == '@') ADVANCE(27);
      if (lookahead != 0) ADVANCE(53);
      END_STATE();
    case 89:
      if (eof) ADVANCE(90);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '-') ADVANCE(24);
      if (lookahead != 0) ADVANCE(53);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(anon_sym_LF);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(sym_from_file_line);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(92);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(sym_to_file_line);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(93);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(sym_hunk_header);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(94);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(sym_context_line);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(sym_addition_line);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(sym_deletion_line);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(sym_note_line);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(sym_preamble_line);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 89},
  [2] = {.lex_state = 87},
  [3] = {.lex_state = 87},
  [4] = {.lex_state = 89},
  [5] = {.lex_state = 89},
  [6] = {.lex_state = 88},
  [7] = {.lex_state = 88},
  [8] = {.lex_state = 56},
  [9] = {.lex_state = 89},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 66},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_LF] = ACTIONS(1),
    [sym_from_file_line] = ACTIONS(1),
    [sym_to_file_line] = ACTIONS(1),
    [sym_hunk_header] = ACTIONS(1),
    [sym_context_line] = ACTIONS(1),
    [sym_addition_line] = ACTIONS(1),
    [sym_deletion_line] = ACTIONS(1),
    [sym_note_line] = ACTIONS(1),
    [sym_preamble_line] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(12),
    [sym_file_patch] = STATE(4),
    [sym_blank_line] = STATE(4),
    [aux_sym_source_file_repeat1] = STATE(4),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_LF] = ACTIONS(5),
    [sym_from_file_line] = ACTIONS(7),
    [sym_preamble_line] = ACTIONS(9),
  },
  [2] = {
    [aux_sym_hunk_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(11),
    [anon_sym_LF] = ACTIONS(11),
    [sym_from_file_line] = ACTIONS(11),
    [sym_hunk_header] = ACTIONS(11),
    [sym_context_line] = ACTIONS(13),
    [sym_addition_line] = ACTIONS(13),
    [sym_deletion_line] = ACTIONS(15),
    [sym_note_line] = ACTIONS(13),
    [sym_preamble_line] = ACTIONS(17),
  },
  [3] = {
    [aux_sym_hunk_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(19),
    [anon_sym_LF] = ACTIONS(19),
    [sym_from_file_line] = ACTIONS(19),
    [sym_hunk_header] = ACTIONS(19),
    [sym_context_line] = ACTIONS(21),
    [sym_addition_line] = ACTIONS(21),
    [sym_deletion_line] = ACTIONS(24),
    [sym_note_line] = ACTIONS(21),
    [sym_preamble_line] = ACTIONS(27),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 5,
    ACTIONS(5), 1,
      anon_sym_LF,
    ACTIONS(7), 1,
      sym_from_file_line,
    ACTIONS(29), 1,
      ts_builtin_sym_end,
    ACTIONS(31), 1,
      sym_preamble_line,
    STATE(5), 3,
      sym_file_patch,
      sym_blank_line,
      aux_sym_source_file_repeat1,
  [18] = 5,
    ACTIONS(33), 1,
      ts_builtin_sym_end,
    ACTIONS(35), 1,
      anon_sym_LF,
    ACTIONS(38), 1,
      sym_from_file_line,
    ACTIONS(41), 1,
      sym_preamble_line,
    STATE(5), 3,
      sym_file_patch,
      sym_blank_line,
      aux_sym_source_file_repeat1,
  [36] = 4,
    ACTIONS(46), 1,
      sym_hunk_header,
    ACTIONS(48), 1,
      sym_preamble_line,
    STATE(7), 2,
      sym_hunk,
      aux_sym_file_patch_repeat1,
    ACTIONS(44), 3,
      ts_builtin_sym_end,
      anon_sym_LF,
      sym_from_file_line,
  [52] = 4,
    ACTIONS(52), 1,
      sym_hunk_header,
    ACTIONS(55), 1,
      sym_preamble_line,
    STATE(7), 2,
      sym_hunk,
      aux_sym_file_patch_repeat1,
    ACTIONS(50), 3,
      ts_builtin_sym_end,
      anon_sym_LF,
      sym_from_file_line,
  [68] = 2,
    STATE(2), 1,
      aux_sym_hunk_repeat1,
    ACTIONS(57), 4,
      sym_context_line,
      sym_addition_line,
      sym_deletion_line,
      sym_note_line,
  [78] = 2,
    ACTIONS(61), 1,
      sym_preamble_line,
    ACTIONS(59), 3,
      ts_builtin_sym_end,
      anon_sym_LF,
      sym_from_file_line,
  [87] = 2,
    ACTIONS(46), 1,
      sym_hunk_header,
    STATE(6), 2,
      sym_hunk,
      aux_sym_file_patch_repeat1,
  [95] = 1,
    ACTIONS(63), 1,
      anon_sym_LF,
  [99] = 1,
    ACTIONS(65), 1,
      ts_builtin_sym_end,
  [103] = 1,
    ACTIONS(67), 1,
      sym_to_file_line,
  [107] = 1,
    ACTIONS(69), 1,
      anon_sym_LF,
  [111] = 1,
    ACTIONS(71), 1,
      anon_sym_LF,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(4)] = 0,
  [SMALL_STATE(5)] = 18,
  [SMALL_STATE(6)] = 36,
  [SMALL_STATE(7)] = 52,
  [SMALL_STATE(8)] = 68,
  [SMALL_STATE(9)] = 78,
  [SMALL_STATE(10)] = 87,
  [SMALL_STATE(11)] = 95,
  [SMALL_STATE(12)] = 99,
  [SMALL_STATE(13)] = 103,
  [SMALL_STATE(14)] = 107,
  [SMALL_STATE(15)] = 111,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(4),
  [11] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_hunk, 3, 0, 0),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [17] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_hunk, 3, 0, 0),
  [19] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_hunk_repeat1, 2, 0, 0),
  [21] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_hunk_repeat1, 2, 0, 0), SHIFT_REPEAT(3),
  [24] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_hunk_repeat1, 2, 0, 0), SHIFT_REPEAT(3),
  [27] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_hunk_repeat1, 2, 0, 0),
  [29] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [31] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [33] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [35] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(9),
  [38] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(11),
  [41] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(5),
  [44] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_file_patch, 5, 0, 0),
  [46] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [48] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_file_patch, 5, 0, 0),
  [50] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_file_patch_repeat1, 2, 0, 0),
  [52] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_file_patch_repeat1, 2, 0, 0), SHIFT_REPEAT(15),
  [55] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_file_patch_repeat1, 2, 0, 0),
  [57] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [59] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_blank_line, 1, 0, 0),
  [61] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_blank_line, 1, 0, 0),
  [63] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [65] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [67] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [69] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [71] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_unified_diff(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
