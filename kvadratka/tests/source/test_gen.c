#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>
#include "../../headers/kvadr_func.h"
// Test generator for Kvadratka
// by Sovus_tartar, 2022

// x^2 + bx + c = 0
// b = -x1 - x2
// c = x1 * x2
// The Viet's Theorem

int main()
{
    int N, i;

    assert(scanf("%d", &N));

    srand(time(NULL));

    printf("%d\n", N);

    for (i = 0; i < N; i++)
    {
        double x1, x2, a, b, c;

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