#include <gtk/gtk.h>

#include "core/test.h"

int main(int argc, char** argv) {
    g_test_init(&argc, &argv, NULL);
    test_app_run(argc, argv);
    return g_test_run();
}
