#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "../../kvadratka/headers/kvadr_func.h"

int test_mode_enabled = 0;

// Test generator for Kvadratka
// by Sovus_tartar, 2022

// x^2 + bx + c = 0
// b = -x1 - x2
// c = x1 * x2
// The Viet's Theorem

int main()
{
    int N, i, successful_read;
    N = 0;
    i = 0;
    successful_read = 0;


    successful_read = scanf("%d", &N);

    srand(time(NULL));

    printf("%d\n", N);

    for (i = 0; i < N; i++)
    {
        double x1, x2, a, b, c;
        
        x1 = NAN;
        x2 = NAN;
        a = 0;
        b = 0;
        c = 0;

        while ((is_equal((x1 = (double)(rand() % 100)), 0)) 
        || (is_equal((x2 = (double)(rand() % 100)), 0)) 
        || (is_equal(x1, x2)));

        while (is_equal((a = (double)(rand() % 100)), 0));

        b = a * (-x1 - x2);
        c = a * x1 * x2;

        printf("%lf %lf %lf 2 %lf %lf\n", a, b, c, x1, x2);
    }

    return 0;
}