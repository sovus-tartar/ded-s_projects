#include "../headers/kvadr_func.h"
#include <stdio.h>
#include <assert.h>


void print_coefficients(sq_eq_coef coefficients) {
    printf("a = %lf b = %lf c = %lf\n", coefficients.a, coefficients.b, coefficients.c);
}

int is_equal_solves(eq_solve solve1, eq_solve solve2) {
    if (solve1.num_of_sol == solve2.num_of_sol) {
        if (solve1.num_of_sol == 1) {
            if (solve1.x1 == solve2.x1)
                return 1;
        }
        if (solve1.num_of_sol == -1) {
            return 1;
        }

        if (((is_equal(solve1.x1, solve2.x1)) && (is_equal(solve1.x2, solve2.x2))) ||
            ((is_equal(solve1.x1, solve2.x2)) && (is_equal(solve1.x2, solve2.x1)))) 
            return 1;
    } 

    return 0;
}

int input_solves(eq_solve *solve) {
    int i, num_of_sol;
    double x1, x2;

    assert(scanf("%d", &num_of_sol));
    assert(num_of_sol < 3);
    
    solve -> num_of_sol = num_of_sol;

    switch(num_of_sol){
        case 0:
            break;
        case 1:
            assert(scanf("%lf", &x1));
            solve -> x1 = x1;
            break;
        case 2:
            assert(scanf("%lf%lf", &x1, &x2) == 2);
            solve -> x1 = x1;
            solve -> x2 = x2;
            break;
    }

    return OK;
}

int unit_test()
{
    int err_count, i, n;
    err_count = 0;
    assert(scanf("%d", &n));

    for (i = 0; i < n; i++)
    {
        sq_eq_coef coefficients;
        eq_solve expected_solve, got_solve;

        input_coefficients(&coefficients);
        input_solves(&expected_solve);
        solve_square_equation(coefficients, &got_solve);

        print_coefficients(coefficients);
        if (is_equal_solves(expected_solve, got_solve)) {
            printf("OK\n");
        } else {
            err_count += 1;
            printf("ERROR, expected:\n");
            print_solves(expected_solve);
            printf("Recieved:\n");
            print_solves(got_solve);
        }

        printf("-----------------------------------------------------------\n");
    }

    if (err_count == 0)
    {
        printf("Tests passed, 0 errors\n");
    } else {
        printf("Tests not passed, %d error(s)\n", err_count);
    }
    
    return OK;
}