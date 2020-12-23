/* xCalc - A fast and simple to use calculator
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

#include <malloc.h>

#include "core/private.h"
#include "token.h"

PRIVATE_DATA {
    TokenType type;
    double payload;
};

void token_init(Token* self, TokenType type, double payload) {
    PRIVATE_INIT(self);
    PRIVATE(self)->payload = payload;
    PRIVATE(self)->type = type;
}

Token* token_create(TokenType type, double payload) {
    Token* self = (Token*) malloc(sizeof(Token));
    token_init(self, type, payload);
    return self;
}

void token_reset(Token* self) {
    PRIVATE_RESET(self);
}

void token_destroy(Token* self) {
    if (self) {
        token_reset(self);
        free(self);
    }
}
