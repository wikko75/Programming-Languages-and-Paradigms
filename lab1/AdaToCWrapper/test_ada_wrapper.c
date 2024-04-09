#include <stdio.h>
#include "ada_wrapper.h"


int main()
{
    printf("Factorial test: %d\n\n", factorial(5));
    printf("GCD test: %d\n\n", gcd(12, 4));

    struct Solution solution = diofantic_eq(1914, 899);
    printf("Diofantic eq. test: { %d, %d }\n\n", solution.x, solution.y);

    return 0;
}