/* Lexer test - Tests for math expression lexical analyzer
 * Copyright (C) 2020 Stan Vlad <vstan02@protonmail.com>
 *
 * This file is part of xCalc.
 *
 * xCalc is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */

#include <glib.h>

#include "tests/app_tests.h"
#include "lexer.h"

static void test_lexer_get_next(void);

extern void add_lexer_tests(void) {
    g_test_add_func(TEST_LEXER_PATH "/next", test_lexer_get_next);
}

static void verify_next_token_type(lexer_t* lexer, token_type_t type) {
    status_t status = STATUS_SUCCESS;
    token_t token = lexer_next(lexer, &status);
    g_assert_cmpint(status, ==, STATUS_SUCCESS);
    g_assert_cmpint(token.type, ==, type);
}

static void test_lexer_get_next(void) {
    lexer_t lexer;
    lexer_init(&lexer, "3 * (+2)");
    verify_next_token_type(&lexer, TOKEN_NUMBER);
    verify_next_token_type(&lexer, TOKEN_STAR);
    verify_next_token_type(&lexer, TOKEN_LPAREN);
    verify_next_token_type(&lexer, TOKEN_PLUS);
    verify_next_token_type(&lexer, TOKEN_NUMBER);
    verify_next_token_type(&lexer, TOKEN_RPAREN);
    verify_next_token_type(&lexer, TOKEN_END);
    verify_next_token_type(&lexer, TOKEN_END);
}
