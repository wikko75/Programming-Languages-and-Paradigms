import functions_iterative
import functions_recursive


def test() -> None:
    print("Recursive approach:\n")
    print(f"Factorial {functions_recursive.factorial(5)}")
    print(f"GCD: {functions_recursive.gcd(12, 4)}")
    solution = functions_recursive.diofantic_eq(1914, 899)
    print(f"Diofantic_eq: [ X = {solution.x}, Y = {solution.y}]\n")

    print("Iterative approach:\n")
    print(f"Factorial {functions_iterative.factorial(5)}")
    print(f"GCD: {functions_iterative.gcd(12, 4)}")
    solution = functions_iterative.diofantic_eq(1914, 899)
    print(f"Diofantic_eq: [X = {solution.x}, Y = {solution.y}]\n")



if __name__ == '__main__':
    test()