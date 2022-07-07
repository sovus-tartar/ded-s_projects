#include "../headers/kvadr_func.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
/* ax^2 + bx + c = 0 */

int main()
{

    double a, b, c;
    eq_solve solves;
    sq_eq_coef coef;
    int err_code;

#ifdef TEST
    int num_of_tests, i;
#endif

#ifndef TEST
    print_descr();
#endif

#ifdef TEST
    assert(scanf("%d", &num_of_tests));
    for (i = 0; i < num_of_tests; i++)
    {
#endif

        err_code = input_k(&coef);
        if (err_code == ERR)
        {
            fprintf(stderr, "The function input_k returned %d, aborting...\n", err_code);
            abort();
        }

        err_code = solve(coef, &solves);
        if (err_code == ERR)
        {
            fprintf(stderr, "The function solve returned %d, aborting...\n", err_code);
            abort();
        }

        err_code = print_solves(solves);
        if (err_code == ERR)
        {
            fprintf(stderr, "The function print_solves returned %d, aborting...\n", err_code);
            abort();
        }

#ifdef TEST
    }
#endif

    return OK;
}