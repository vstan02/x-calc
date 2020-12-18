/**
 * xCalc - A fast and simple to use calculator
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

#include "token.h"

#define PRIVATE(object) ((PRIVATE_DATA*) MODULE_PRIVATE(token, object))

PRIVATE_DATA {
    TokenType type;
    double payload;
};

TokenType token_get_type(Token* self) {
    return PRIVATE(self)->type;
}

double token_get_payload(Token* self) {
    return PRIVATE(self)->payload;
}

MODULE_SET_CONSTRUCTOR(token, Token, MODULE_INIT_PARAMS(type, payload), TokenType type, double payload) {
    MODULE_INIT_PRIVATE(token, self);
    PRIVATE(self)->type = type;
    PRIVATE(self)->payload = payload;
}

MODULE_SET_DESTRUCTOR(token, Token) {
    free(PRIVATE(self));
}
