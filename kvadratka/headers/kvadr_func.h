#pragma once

/// The accuracy of double numbers comparison
extern const double EPSILON;

/// Indicates if the "-t" flag enabled. For debug purposes
extern int test_mode_enabled;

/**
 * @brief Square equation coefficients
 *
 * @details This structure contains the coefficients of equation \f$ ax^2 + bx + c = 0 \f$
 * All coefficients must be finite
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
 * @details This structure contains solve s of equation \f$ ax^2 + bx + c = 0 \f$.
 * Should be initialized using init_eq_solves function.
 * Rules: if num_of_sol = INF_SOLUTIONS or NO_SOLUTIONS, then x1 and x2 must be NAN
 * if num_of_sol = 1, x1 must be finite, x2 must be nan
 * if num_of_sol = 2, x1 and x2 must be finite  
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
 * @param coef The structure of coefficients
 * @return int -1 if input error, 0 otherwise
 */
int input_coefficients(sq_eq_coef *coef);

/**
 * @brief This function solves square equation
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
 * This function allows user to solve square equations with messages on the screen
 * @return int 0 if all is ok, -1 otherwise
 */
int solve_for_user();

/**
 * @brief Input solves function
 * This function is used to put solves from stdin to structure
 * @warning It was used only for unit tests, may be unsafe!
 * @param solve the structure of solves pointer
 * @return int 0 if OK, -1 otherwise
 */
int input_solves(eq_solve *solve);

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

/**
 * @brief eq_solve type initializer
 * @return initialized variable
 */
eq_solve init_eq_solves();

/**
 * @brief sq_eq_coef type initializer
 * @return initialized variable
 */
sq_eq_coef init_sq_eq_coef();

/**
* @brief Checks coeefficients using isfinite()
* @return 0 if it is OK, 1 otherwise
*/
int check_coefficients(double a, double b, double c);
/**
* @brief Checks solves structure if it is correct format
* @return 0 if it is OK, 1 otherwise
*/
int check_solves(const eq_solve *solves);