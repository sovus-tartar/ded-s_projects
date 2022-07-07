#include "../headers/kvadr_func.h"
#include <stdio.h>
#include <assert.h>
#include <math.h>

double epsilon = 0.00001;

void print_descr()
{
    printf("Square equations solver by Sovus_tartar, 2022\n");
}

int is_equal(double num1, double num2)
{
    return (fabs(num1 - num2) < epsilon);
}

int input_k(sq_eq_coef *coef)
{
    int succ_read;
    int ch;
    double a, b, c;
#ifndef TEST
    printf("Enter coefficients in ax^2 + bx + c = 0, devided by spaces:\n");
#endif
    succ_read = scanf("%lf%lf%lf", &a, &b, &c);

    if (succ_read != 3)
    {
        fprintf(stderr, "The function input_k read %d coefficients of 3\n", succ_read);
        return ERR;
    }

    coef->a = a;
    coef->b = b;
    coef->c = c;
#ifdef TEST
    printf("Equation: %.2lf*x^2 + (%.2lf)*x + (%.2lf) = 0\n", a, b, c);
#endif
    return OK;
}

int solve(sq_eq_coef coef, eq_solve *solves)
{
    double a, b, c, discr;
    a = coef.a;
    b = coef.b;
    c = coef.c;

    if ((a == 0) && (b == 0) && (c == 0))
    {
        solves->num_of_sol = -1;
        return OK;
    }

    if ((a == 0) && (b == 0) && (c != 0))
    {
        solves->num_of_sol = 0;
        return OK;
    }

    discr = b * b - 4 * a * c;

    if (is_equal(discr, 0))
    {
        solves->num_of_sol = 1;
        solves->x1 = -b / (2 * a);
        return OK;
    }
    else if (discr < 0)
    {
        solves->num_of_sol = 0;
        return OK;
    }
    else
    {
        double discr_sqrt;
        discr_sqrt = sqrt(discr);
        solves->num_of_sol = 2;
        solves->x1 = (-b - discr_sqrt) / (2 * a);
        solves->x2 = (-b + discr_sqrt) / (2 * a);
        return OK;
    }

    fprintf(stderr, "Uknown error in function solve\n, aborting...");
    return ERR;
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