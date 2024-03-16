#include "func.h"
#include <stdio.h>

/**
 * 
 * File contains recursion implementation of functions computing factorial, GCD and diofantic eq.
 * 
**/

int factorial_tail_rec(int n, int accu)
{
    if (n == 1)
    {
        return accu;
    }

    return factorial_tail_rec(n-1, n * accu);
}


int factorial(int n)
{
    printf("FACTORIAL - REC VERSION\n");
    return factorial_tail_rec(n, 1);
}


int gcd(int a, int b)
{
    if (b == 0)
    {
        printf("GCD - REC VERSION\n");
        return a;
    }

    return gcd(b, a % b);
}


struct Solution diofantic_eq(int a, int b)
{   
    if (b == 0)
    {
        printf("DIOF EQ - REC VERSION\n");
        struct Solution solution = {1, 0};
        return solution;
    }

    struct Solution prevSolution = diofantic_eq(b, a % b);

    int x = prevSolution.y;
    int y = prevSolution.x - prevSolution.y * (a / b);

    struct Solution solution = {x, y};

    return solution;
}