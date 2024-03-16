import functions_c.iterative as c_iterative
import functions_c.recursive as c_recursive

def init() -> None:
    print("Test of wrapper for C library\n")


if __name__ == '__main__':
    init()
    print("Iterative approach:")
    solution = c_iterative.diofantic_eq(1914, 899)
    print(f"Factorial:    { c_iterative.factorial(5) }")
    print(f"GCD:          { c_iterative.gcd(12, 4) }")
    print(f"Diofantic_eg: [ X = { solution.x }, Y = { solution.y } ]\n")

    print("Recursive approach:")
    solution = c_recursive.diofantic_eq(1914, 899)
    print(f"Factorial:    { c_recursive.factorial(5) }")
    print(f"GCD:          { c_recursive.gcd(12, 4) }")
    print(f"Diofantic_eg: [ X = { solution.x }, Y = { solution.y } ]\n")