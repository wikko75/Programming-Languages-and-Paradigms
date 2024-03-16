#ifndef ADA_WRAPPER_1_H
#define ADA_WRAPPER_1_H

struct Solution
{
    int x;
    int y;
};

extern int factorial(int n);

extern int gcd(int a, int b);

extern struct Solution diofantic_eq(int a, int b);

#endif