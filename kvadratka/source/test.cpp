#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <errno.h>
#include "../headers/kvadr_func.h"

void print_coefficients(const sq_eq_coef *coefficients) {
    printf("a = %lf b = %lf c = %lf\n", coefficients->a, coefficients->b, coefficients->c);
}

int is_equal_solves(const eq_solve *solve1, const eq_solve *solve2) {
    if (solve1->num_of_sol == solve2->num_of_sol) {
        if (solve1->num_of_sol == 1) {
            if (solve1->x1 == solve2->x1)
                return 1;
        }
        if (solve1->num_of_sol == -1) {
            return 1;
        }
    
        if (((is_equal(solve1->x1, solve2->x1)) && (is_equal(solve1->x2, solve2->x2))) ||
            ((is_equal(solve1->x1, solve2->x2)) && (is_equal(solve1->x2, solve2->x1)))) 
            return 1;
    } 

    return 0;
}

int input_solves(eq_solve *solve) {
    int i, num_of_sol, successfull_read;
    double x1, x2;
    x1 = NAN;
    x2 = NAN;
    i = 0; 
    num_of_sol = 0;

    successfull_read = scanf("%d", &num_of_sol);
    assert(successfull_read);
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
        default:
            return EDOM;
    }
    return 0;
}

int unit_test()
{
    int err_count, i, n, input_err;
    err_count = 0;
    input_err = 0;

    input_err = scanf("%d", &n);
    if (!(input_err&&(n > 0))) {
        errno = EIO;
        perror("unit_test");
        return EIO;
    }

    for (i = 0; i < n; i++)
    {
        sq_eq_coef coefficients;
        eq_solve expected_solve, got_solve;

        input_coefficients(&coefficients);
        input_solves(&expected_solve);
        solve_square_equation(&coefficients, &got_solve);

        print_coefficients(&coefficients);
        if (is_equal_solves(&expected_solve, &got_solve)) {
            printf("OK\n");
        } else {
            err_count += 1;
            printf("ERROR, expected:\n");
            print_solves(&expected_solve);
            printf("Recieved:\n");
            print_solves(&got_solve);
        }

        printf("-----------------------------------------------------------\n");
    }

    if (err_count == 0)
    {
        printf("Tests passed, 0 errors\n");
    } else {
        printf("Tests not passed, %d error(s)\n", err_count);
    }
    
    return 0;
}