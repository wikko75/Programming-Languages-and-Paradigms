#include <stdio.h>
#include "func.h"

int main()
{
    printf("Factorial test: %d\n\n", factorial(5));

    printf("GCD test: %d\n\n", gcd(12, 4));

    struct Solution solution_rec = diofantic_eq(1914, 899);
    printf("Diofantic eq. test: { %d, %d }\n\n", solution_rec.x, solution_rec.y);
        
    return 0;
}