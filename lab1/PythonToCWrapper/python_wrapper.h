#ifndef PYTHON_WRAPPER_HPP
#define PYTHON_WRAPPER_HPP


int init_wrapper();

int factorial(int n);

int gcd(int a, int b);

struct Solution
{
    int x;
    int y;
};

struct Solution diofantic_eq(int a, int b);

void finalize_wrapper();


#endif