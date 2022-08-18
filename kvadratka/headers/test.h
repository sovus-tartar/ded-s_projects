#pragma once

#include "kvadr_func.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

/**
 * @brief Unit test function
 * Unit test interface. Prints debug information
 * @return int 0 if all is ok, -1 otherwise
 */
int unit_test();

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
 * @brief This function is for input solves from stdin to eq_solve.
 * Format: n x1 x2
 * n - number of solutions(-1 < n < 3)
 * x1 - first root (if exists)
 * x2 - second root (if exists)
 */ 
int input_solves(eq_solve *solve);