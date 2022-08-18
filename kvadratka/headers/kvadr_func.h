#pragma once

/// The accuracy of double numbers comparison
extern const double EPSILON;

/// Indicates if the "-t" flag enabled. For debug purposes
extern int test_mode_enabled;

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
 * @brief Number of solutions
 * @param INIT_VALUE    -2
 * @param INF_SOLUTIONS -1
 * @param NO_SOLUTIONS   0
 * @param ONE_SOLUTION   1
 * @param TWO_SOLUTIONS  2
 */
enum num_of_solutions
{
    INIT_VALUE    = -2,
    INF_SOLUTIONS = -1,
    NO_SOLUTIONS  = 0,
    ONE_SOLUTION  = 1,
    TWO_SOLUTIONS = 2
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
int is_equal(const double num1, const double num2);

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
int solve_square_equation(const sq_eq_coef *coefficients, eq_solve *solves);

/**
 * @brief This function solves linear equations.
 *
 * @param coefficients structure of coefficients to read
 * @param solves the pointer to the structure of solves to write. The root will be written to x1 field and the num_of_sol field is 1
 * @return int 0 if all is OK, -1 otherwise
 */
int solve_linear_equation(const sq_eq_coef *coefficients, eq_solve *solves);

/**
 * @brief Print solves
 * This function prints solves to the screen
 * @param solves the structure of solves to print
 * @return int 0 if all is OK, -1 otherwise
 */
int print_solves(const eq_solve *solves);

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
int is_equal_solves(const eq_solve *solve1, const eq_solve *solve2);

/**
 * @brief Print coefficients
 * This function prints to the screen coefficients of square equation \f$ ax^2 + bx + c = 0 /f$
 * @param coefficients
 */
void print_coefficients(const sq_eq_coef *coefficients);

/**
 * @brief Clean buffer
 * This function cleans stdin
 * @return 0
 */
int clean_buffer();

/**
 * @brief Check buffer
 * This function checks if there is something in stdin buffer but space symbols TILL THE END OF LINE.
 * @return 1 if there are symbol except space symbol, else 0
 */
int check_buffer();

void init_eq_solves(eq_solve *A);

void init_sq_eq_coef(sq_eq_coef *A);