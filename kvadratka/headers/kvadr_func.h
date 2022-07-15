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

void print_description();
int is_equal(double num1, double num2);
int input_coefficients(sq_eq_coef *coef);
int solve_square_equation(sq_eq_coef coefficients, eq_solve *solves);
int solve_linear_equation(sq_eq_coef coefficients, eq_solve *solves);
int print_solves(eq_solve solves);
int user_interface();

int unit_test();
int input_solves(eq_solve *solve);
int is_equal_solves(eq_solve solve1, eq_solve solve2);
void print_coefficients(sq_eq_coef coefficients);