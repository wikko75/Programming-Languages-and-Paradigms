from typing import NamedTuple


def factorial(n: int) -> int:
    """Iterative factorial calculation."""
    result = 1
    while n > 1:
        result *= n
        n -= 1
    return result


def gcd(a: int, b: int) -> int:
    """Iterative greatest common divisor calculation."""
    while b != 0:
        a, b = b, a % b
    return a


class Solution(NamedTuple):
    """Represents a solution to a Diophantine equation."""
    x: int
    y: int


def diofantic_eq(a: int, b: int) -> Solution:
    """Iterative solution for Diophantine equation."""
    solution = Solution(0, 1)
    u = 1
    v = 0
    while a != 0:
        q = b // a
        r = b % a
        m = solution.x - u * q
        n = solution.y - v * q
        b = a
        a = r
        solution = Solution(u, v)
        u = m
        v = n
    return solution