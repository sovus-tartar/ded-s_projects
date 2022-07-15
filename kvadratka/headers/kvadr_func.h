
#pragma once

/**
 * @brief Square equation coefficients
 * 
 * @details This structure contains the coefficients of equation \f$ ax^2 + bx + c = 0 \f$
 * 
 * @param a a coefficient
 * @param b b coefficient
 * @param c c coefficient
 */
typedef struct sq_eq_coef_t
{
    double a;
    double b;
    double c;
} sq_eq_coef;

/**
 * @brief Square equation solves
 * 
 * @details This structure contains solve s of equation \f$ ax^2 + bx + c = 0 \f$. 
 * If num_of_sol = -1 it means that all x are solutions. If num_of_sol = 1, the root should be in x1 field
 * 
 * @param num_of_sol number of solutions
 * @param x1 first root
 * @param x2 second root
 */
typedef struct eq_solve_t
{
    int num_of_sol;
    double x1;
    double x2;
} eq_solve;

/**
 * @brief Error codes 
 * @param ERR -1
 * @param OK 0
 */

enum error_codes
{
    ERR = -1,
    OK = 0
};
/**
 * @brief Print description
 * This function prints information about the program
 */
void print_description();
/**
 * @brief Comparison floating-point numbers
 * 
 * @param num1, num2 - floating point numbers
 * @return int 1 if equal, 0 if not equal
 */
int is_equal(double num1, double num2);
/**
 * @brief Imput coefficient function
 * This function allows save input of coefficients of square equation with user messages.
 * 
 * @param coef The structure of coefficients
 * @return int -1 if input error, 0 otherwise
 */
int input_coefficients(sq_eq_coef *coef);
/**
 * @brief This function solves square equation
 * 
 * @param coefficients structure of coefficients to read
 * @param solves the pointer to the structure of solves to write
 * @return int 0 if all is OK, -1 otherwise
 */
int solve_square_equation(sq_eq_coef coefficients, eq_solve *solves);
/**
 * @brief This function solves linear equations.
 * 
 * @param coefficients structure of coefficients to read
 * @param solves the pointer to the structure of solves to write. The root will be written to x1 field and the num_of_sol field is 1
 * @return int 0 if all is OK, -1 otherwise
 */
int solve_linear_equation(sq_eq_coef coefficients, eq_solve *solves);
/**
 * @brief Print solves
 * This function prints solves to the screen
 * @param solves the structure of solves to print
 * @return int 0 if all is OK, -1 otherwise
 */
int print_solves(eq_solve solves);
/**
 * @brief User interface
 * 
 * This function allows user to solve square equations with messages on the screen
 * 
 * @return int 0 if all is ok, -1 otherwise
 */
int user_interface();
/**
 * @brief Unit test function
 * 
 * @return int 0 if all is ok, -1 otherwise
 */
int unit_test();
/**
 * @brief Input solves function
 * This function is used to put solves from stdin to structure
 * @warning It was used only for unit tests, may be unsafe!
 * @param solve the structure of solves pointer
 * @return int 0 if OK, -1 otherwise
 */
int input_solves(eq_solve *solve);
/**
 * @brief Is equal solves
 * This function compares solves of equation
 * @warning It was used only for unit tests, may be unsafe!
 * @param solve1, solve2 solves
 * @return int 1 if equal, 0 otherwise
 */
int is_equal_solves(eq_solve solve1, eq_solve solve2);
/**
 * @brief Print coefficients
 * This function prints to the screen coefficients of square equation \f$ ax^2 + bx + c = 0 /f$
 * @param coefficients 
 */
void print_coefficients(sq_eq_coef coefficients);
