import Galois as gl

if __name__ == "__main__":

    gl.Galois.print_info()
    
    order = 1234577

    a = gl.Galois(15, order)
    b = gl.Galois(1234576, order)

    print("\nInitial values:")
    print(f"a = {a }\nb = {b}\n")

    print(f"a + b = {a + b}")
    print(f"1234578 + b = {gl.Galois(1234578, order) + b}")
    print(f"a + 4 = {a + gl.Galois(4, order)}")

    print(f"a - b = {a - b}")
    print(f"a * b = {a * b}")
    
    print(f"a = {a}")
    print(f"~a = {~a}")
    print(f"Check: a * ~a = {a * ~a}")
    
    print(f"a / b = {a / b}")
    print(f"Check: a / b * b = {a / b * b}")

    print(f"\nIs a equal to b? {a == b}")
    print(f"Is a not equal to b? {a != b}")
    print(f"Is a less than b? {a < b}")
    print(f"Is a less than or equal to b? {a <= b}")
    print(f"Is a greater than b? {a > b}")
    print(f"Is a greater than or equal to b? {a >= b}")


    print("\nEnd values:")
    print(f"a = {a}\nb = {b}\n")