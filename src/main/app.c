#include <stdio.h>
#include "gsi/gsi.h"

int main (int argc, const char** argv) {
    GSI gsi;
    gsi_init(&gsi);

    printf("Hello to g-social-interactive\n");

    gsi_clear(&gsi);

    return 0;
}