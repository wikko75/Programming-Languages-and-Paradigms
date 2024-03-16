from typing import NamedTuple


def factorial_tail_rec(n: int, accu: int = 1) -> int:
    """Tail-recursive factorial calculation."""
    if n == 1:
        return accu
    return factorial_tail_rec(n - 1, n * accu)


def factorial(n: int) -> int:
    """Recursive factorial calculation."""
    return factorial_tail_rec(n, 1)


def gcd(a: int, b: int) -> int:
    """Recursive greatest common divisor calculation."""
    if b == 0:
        return a
    return gcd(b, a % b)


class Solution(NamedTuple):
    """Represents a solution to a Diophantine equation."""
    x: int
    y: int


def diofantic_eq(a: int, b: int) -> Solution:
    """Recursive solution for Diophantine equation."""
    if b == 0:
        return Solution(1, 0)
    prev_solution = diofantic_eq(b, a % b)
    return Solution(prev_solution.y, prev_solution.x - prev_solution.y * (a // b))