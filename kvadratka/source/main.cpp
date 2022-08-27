#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <errno.h>

#include "../headers/kvadr_func.h"
#include "../headers/test.h"
int test_mode_enabled = 0;

int main(int argc, char *argv[])
{

    print_description();

    if (argc == 1)
    {
        solve_for_user();
        if (errno != 0)
            perror("main");
        return errno;
    }

    if ((argc == 2) && (!strcmp(argv[1], "-t")))
    {
        test_mode_enabled = 1;
        unit_test();
        return 0;
    }

    if (argc > 2)
    {
        fprintf(stderr, "Too many arguments\n");
        errno = E2BIG;
        perror("main");
        return errno;
    }

    if (strcmp("-t", argv[1]))
    {
        fprintf(stderr, "Unknown argument  \"%s\"\n", argv[1]);
        errno = EINVAL;
        perror("main");
        return errno;
    }

    return errno;
}