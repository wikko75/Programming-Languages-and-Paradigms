#include "func.h"
#include <stdio.h>

/**
 * 
 * File contains iterative implementation of functions computing factorial, GCD and diofantic eq.
 * 
**/

int factorial(int n)
{
    printf("FACTORIAL - LOOP VERSION\n");
    int result = 1;

    while (n != 1)
    {
        result *= n; 
        --n;
    }

    return result;
}


int gcd(int a, int b)
{
    printf("GCD - LOOP VERSION\n");

    int temp = 0;

    while(b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}


struct Solution diofantic_eq(int a, int b)
{
    printf("DIOF EQ - LOOP VERSION\n");
    struct Solution solution = {0, 1};
    int u = 1;
    int v = 0;

    while (a != 0) 
    {
        int q = b / a;
        int r = b % a;

        int m = solution.x - u * q;
        int n = solution.y - v * q;

        b = a;
        a = r;
        solution.x = u;
        solution.y = v;
        u = m;
        v = n;
    }

    return solution;
}