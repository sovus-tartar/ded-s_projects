
#include "../headers/kvadr_func.h"
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>

/// Accuracy of floating point numbers comparison
const double epsilon = 0.00001; 

void print_description()
{
    printf("Square equations solver by Sovus_tartar, 2022\n");
}

int is_equal(double num1, double num2)
{
    return (fabs(num1 - num2) < epsilon);
}

int check_coefficients(double a, double b, double c) {
    return (isfinite(a) && isfinite(b) && isfinite(c));
}

int input_coefficients(sq_eq_coef *coefficients)
{
    int successful_read;
    double a, b, c;

    a = NAN;
    b = NAN;
    c = NAN;

    printf("Enter coefficients in ax^2 + bx + c = 0, devided by spaces:\n");

    successful_read = scanf("%lf%lf%lf", &a, &b, &c);

    if (successful_read != 3)
    {
        fprintf(stderr, "The function input_coefficients read %d coefficients of 3\n", successful_read);
        return ERR;
    }

    if (!check_coefficients(a, b, c)) {
        fprintf(stderr, "The function input_coefficients read incorrect coefficients\n");
        return ERR;
    }

    coefficients->a = a;
    coefficients->b = b;
    coefficients->c = c;

    return OK;
}

int solve_square_equation(sq_eq_coef coefficients, eq_solve *solves)
{
    double a, b, c, discriminant;
    a = coefficients.a;
    b = coefficients.b;
    c = coefficients.c;

    if ((is_equal(a, 0)) && (is_equal(b, 0)) && (is_equal(c, 0)))
    {
        solves->num_of_sol = -1;
        return OK;
    }

    if ((is_equal(a, 0)) && (is_equal(b, 0)) && (!is_equal(c, 0)))
    {
        solves->num_of_sol = 0;
        return OK;
    }

    if (is_equal(a, 0)) {
        solve_linear_equation(coefficients, solves);
        return OK;
    }

    discriminant = b * b - 4 * a * c;

    if (is_equal(discriminant, 0))
    {
        solves->num_of_sol = 1;
        solves->x1 = -b / (2 * a);
        return OK;
    }
    else if (discriminant < 0)
    {
        solves->num_of_sol = 0;
        return OK;
    }
    else
    {
        double discr_sqrt;
        discr_sqrt = sqrt(discriminant);
        solves->num_of_sol = 2;
        solves->x1 = (-b - discr_sqrt) / (2 * a);
        solves->x2 = (-b + discr_sqrt) / (2 * a);
        return OK;
    }

    fprintf(stderr, "Uknown error in function solve_square_equation\n, aborting...");
    return ERR;
}

int solve_linear_equation(sq_eq_coef coefficients, eq_solve *solves) {
    double a, b, c;

    a = coefficients.a;
    assert(is_equal(a, 0));

    b = coefficients.b;
    c = coefficients.c;

    solves -> num_of_sol = 1;
    solves -> x1 = -c / b;

    return OK;
}

int print_solves(eq_solve solves)
{

    switch (solves.num_of_sol)
    {
    case -1:
        printf("All x are solves\n");
        return OK;
    case 0:
        printf("No solutions\n");
        return OK;
    case 1:
        printf("x = %lf\n", solves.x1);
        return OK;
    case 2:
        printf("x1 = %lf\nx2 = %lf\n", solves.x1, solves.x2);
        return OK;
    }

    fprintf(stderr, "The number of solutions is unknown %d\n", solves.num_of_sol);
    return ERR;
}

int user_interface()
{
    eq_solve solves;
    sq_eq_coef coefficients;
    int err_code;

    err_code = input_coefficients(&coefficients);
    if (err_code == ERR)
    {
        fprintf(stderr, "The function input_coefficients returned %d, aborting...\n", err_code);
        abort();
    }

    err_code = solve_square_equation(coefficients, &solves);
    if (err_code == ERR)
    {
        fprintf(stderr, "The function solve_square_equation returned %d, aborting...\n", err_code);
        abort();
    }

    err_code = print_solves(solves);
    if (err_code == ERR)
    {
        fprintf(stderr, "The function print_solves returned %d, aborting...\n", err_code);
        abort();
    }

    return OK;
}