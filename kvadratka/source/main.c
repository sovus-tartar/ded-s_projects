
#include "../headers/kvadr_func.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
/* ax^2 + bx + c = 0 */

int main(int argc, char *argv[])
{

    print_description();

    if (argc == 1)
    {
        return user_interface();
    }

    if ((argc == 2) && (!strcmp(argv[1], "-t"))) {
        unit_test();
        return OK;
    }

    if (argc > 2) {
        fprintf(stderr, "Too many arguments, aborting...\n");
        abort();
    }

    if (strcmp("-t", argv[1])) {
        fprintf(stderr, "Unknown argument  \"%s\", aborting...\n", argv[1]);
        abort();
    }
    
}