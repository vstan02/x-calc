#include "core/test.h"
#include "app_tests.h"

void test_app(int argc, const char** argv) {
    test_token();
    test_text();
    test_lexer();
//    test_parser();
}