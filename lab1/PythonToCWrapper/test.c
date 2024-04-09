#include <stdio.h>
#include "python_wrapper.h"


int main()
{
    if(init_wrapper() != 0)
    {
        printf("Initializing failed!\n");
        return 0;
    }

    int factorial_res = factorial(5);

    printf("Factorial: %d\n", factorial_res);

    printf("GCD: %d\n", gcd(12,4));

    struct Solution solution = diofantic_eq(1914, 899);

    printf("Diofantic_eq: [ X = %d, Y = %d ]\n", solution.x, solution.y);

    finalize_wrapper();
    
    return 0;
}