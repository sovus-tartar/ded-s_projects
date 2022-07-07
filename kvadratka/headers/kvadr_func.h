#pragma once

typedef struct sq_eq_coef_t
{
    double a;
    double b;
    double c;
} sq_eq_coef;

typedef struct eq_solve_t
{
    int num_of_sol;
    double x1;
    double x2;
} eq_solve;

enum error_codes
{
    ERR = -1,
    OK = 0
};

void print_descr();
int is_equal(double num1, double num2);
int input_k(sq_eq_coef *coef);
int solve(sq_eq_coef coef, eq_solve *solves);
int print_solves(eq_solve solves);