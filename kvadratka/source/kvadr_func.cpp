#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include "../headers/kvadr_func.h"

const double EPSILON = 0.000001;
extern int test_mode_enabled;

void print_description()
{
    printf("Square equations solver by Sovus_tartar, 2022\n");
}

int is_equal(const double num1, const double num2)
{
    return (fabs(num1 - num2) < EPSILON);
}

int check_coefficients(double a, double b, double c)
{
    return !(isfinite(a) && isfinite(b) && isfinite(c));
}

int clean_buffer()
{
    char c = 0;

    while (((c = getchar()) != '\n') && (c != EOF))
        continue;
    return 0;
}

int check_buffer()
{
    char c = 0;

    while (((c = getchar()) != '\n') && (c != EOF))
    {
        if (!isspace(c))
            return 1;
    }

    return 0;
}

int input_coefficients(sq_eq_coef *coefficients)
{
    int successful_read;
    
    successful_read = 0;
    

    if (test_mode_enabled == 0)
    {
        printf("Enter coefficients in ax^2 + bx + c = 0, devided by spaces:\n");
    }

    double a, b, c;

    a = NAN;
    b = NAN;
    c = NAN;

    successful_read = scanf("%lf%lf%lf", &a, &b, &c);

    int attempts = 1;

    if (test_mode_enabled == 0)
    {

        while ((successful_read != 3) || check_coefficients(a, b, c) || check_buffer())
        {
            attempts += 1;
            fprintf(stderr, "Input error, please, try again\n");
            clean_buffer();

            if (attempts <= 3)
                successful_read = scanf("%lf%lf%lf", &a, &b, &c);
            else
            {
                errno = EIO;
                perror("input coefficients");
                return EIO;
            }
        }
    }

    coefficients->a = a;
    coefficients->b = b;
    coefficients->c = c;

    return 0;
}

int solve_square_equation(const sq_eq_coef *coefficients, eq_solve *solves)
{
    double a, b, c;
    a = coefficients->a;
    b = coefficients->b;
    c = coefficients->c;
    

    if (check_coefficients(coefficients->a, coefficients->b, coefficients->c))
    {
        errno = EDOM;
        perror("solve_square_equation");
        return errno;
    }

    if (is_equal(a, 0))
        return solve_linear_equation(coefficients, solves);

    if (is_equal(b, 0) && is_equal(c, 0)) {
        solves->num_of_sol = INF_SOLUTIONS;
        return 0;
    }    

    if (is_equal(b, 0) && !is_equal(c, 0)) {
        solves->num_of_sol = NO_SOLUTIONS;
        return 0;
    }

    double discriminant = b * b - 4 * a * c;

    if (is_equal(discriminant, 0))
    {
        solves->num_of_sol = 1;
        solves->x1 = -b / (2 * a);
        return 0;
    }
    else if (discriminant < 0)
    {
        solves->num_of_sol = 0;
        return 0;
    }
    else
    {
        double discr_sqrt = sqrt(discriminant);

        solves->num_of_sol = 2;
        solves->x1 = (-b - discr_sqrt) / (2 * a);
        solves->x2 = (-b + discr_sqrt) / (2 * a);

        return 0;
    }
}

int solve_linear_equation(const sq_eq_coef *coefficients, eq_solve *solves)
{
    double a, b, c;

    a = coefficients->a;
    b = coefficients->b;
    c = coefficients->c;

    if (check_coefficients(a, b, c))
    {
        errno = EDOM;
        perror("solve_linear_equation");
        return errno;
    }

    if (!is_equal(a, 0))
    {
        fprintf(stderr, "Not linear equation\n");
        errno = EDOM;
        perror("solve_linear_equation");
        return EDOM;
    }
    else if (is_equal(b, 0)) 
    {
        if (is_equal(c, 0)) 
        {
            solves->num_of_sol = INF_SOLUTIONS;
            return 0;
        } 
        else 
        {
            solves->num_of_sol = NO_SOLUTIONS;
            return 0;
        }
    } 

    solves->num_of_sol = ONE_SOLUTION;
    solves->x1 = -c/b;

    return 0;
}

int check_solves(const eq_solve *solves)
{   
    switch (solves->num_of_sol)
    {
    case INIT_VALUE:
        return -1;
    case INF_SOLUTIONS:
        return !(isnan(solves->x1) && isnan(solves->x2));
    case NO_SOLUTIONS:
        return !(isnan(solves->x1) && isnan(solves->x2));
    case ONE_SOLUTION:
        return !(isfinite(solves->x1) && isnan(solves->x2));
    case TWO_SOLUTIONS:
        return !(isfinite(solves->x1) && isfinite(solves->x2));
    default:
        return -1;
    }
}

int print_solves(const eq_solve *solves)
{
    if (check_solves(solves))
    {
        errno = EINVAL;
        printf("solve: %d %lf %lf\n", solves->num_of_sol, solves->x1, solves->x2);
        perror("print_solves");
        return errno;
    }

    switch (solves->num_of_sol)
    {
    case INF_SOLUTIONS:
        printf("All x are solves\n");
        return 0;
    case NO_SOLUTIONS:
        printf("No solutions\n");
        return 0;
    case ONE_SOLUTION:
        printf("x = %lf\n", solves->x1);
        return 0;
    case TWO_SOLUTIONS:
        printf("x1 = %lf\nx2 = %lf\n", solves->x1, solves->x2);
        return 0;
    default:
        fprintf(stderr, "The number of solutions is unknown %d\n", solves->num_of_sol);
        errno = EINVAL;
        perror("print_solves");
        return errno;
    }
}

void init_sq_eq_coef(sq_eq_coef *A)
{
    A->a = NAN;
    A->b = NAN;
    A->c = NAN;
}

void init_eq_solves(eq_solve *A)
{
    A->num_of_sol = INIT_VALUE;
    A->x1 = NAN;
    A->x2 = NAN;
}

int solve_for_user()
{
    eq_solve solves;
    sq_eq_coef coefficients;
    int err_code;
    err_code = 0;
    init_sq_eq_coef(&coefficients);
    init_eq_solves(&solves);

    input_coefficients(&coefficients);
    solve_square_equation(&coefficients, &solves);
    print_solves(&solves);

    if (errno != 0)
        perror("solve_for_user");

    return err_code;
}