import math

class OrderMismatchException(Exception):
    def __init__(self, caused_by : str) -> None:
        super().__init__(f"{caused_by} called on object with different field order")


class Galois:

    def __init__(self, value : int, order):
        if not self._is_prime(order): 
            raise Exception("Field order must be a prime number")
        self.order = order
        if value is not None:
            self.value = value % order if value >= 0 else (order + value)


    def __add__(self, other):
        if not self._check_order(other):
            raise OrderMismatchException("__add__")
        new_value = (self.value + other.value) % self.order
        return Galois(new_value, self.order)
    

    def __sub__(self, other):
        if not self._check_order(other):
            raise OrderMismatchException("__sub__")
        value = self.value - other.value
        if value < 0:
            value = (self.order + self.value)
        return Galois(value, self.order)


    def __mul__(self, other):
        if not self._check_order(other):
            raise OrderMismatchException("__mul__")
        value = (self.value * other.value) % self.order
        return Galois(value, self.order)


    def __truediv__(self, other):
        if not self._check_order(other):
            raise OrderMismatchException("__truediv__")
        return self.__mul__(other.__invert__())


    def __invert__(self):
        return Galois(self._diofantic_eq(self.value), self.order)


    def __eq__(self, other):
        if not self._check_order(other):
            raise OrderMismatchException("__eq__")
        return self.value == other.value


    def __ne__(self, other):
        if not self._check_order(other):
            raise OrderMismatchException("__ne__")        
        return not self.__eq__(other)


    def __lt__(self, other):
        if not self._check_order(other):
            raise OrderMismatchException("__lt__")       
        return self.value < other.value


    def __le__(self, other):
        if not self._check_order(other):
            raise OrderMismatchException("__le__")      
        return not self.__gt__(other)


    def __gt__(self, other):
        if not self._check_order(other):
            raise OrderMismatchException("__gt__")       
        return self.value > other.value


    def __ge__(self, other):
        if not self._check_order(other):
            raise OrderMismatchException("__ge__")     
        return not self.__lt__(other)


    def _check_order(self, other) -> bool:
        return self.order == other.order


    def __str__(self) -> str:
        return str(self.value)


    def __repr__(self):
        try:
            value_str = str(self.value)
        except AttributeError:
            value_str = "None"
        return f"Galois [value: {value_str}, order: {self.order}]"
    
    
    @staticmethod
    def print_info():
        print("\n=============\n"
              "Galois\n"
              "Properties:\n"
            #   f"Default order: {Galois.get_order()}\n"
              "=============\n")


    def _is_prime(self, n : int) -> bool:
            if n < 2:
                return False
            for a in range(2, int(math.sqrt(n)) + 1):
                if n % a == 0:
                    return False
            return True
    
    def get_order(self):
        return self.order
    

    def _diofantic_eq(self, a : int) -> int:
        ''' 
        Helper function that computes inverse of a (~a)\n 
        Brief:
            a*x + b*y = GCD(a,b)\n
            We want to get an inverse (x) of a: a * x == 1\n
            b - field order (prime number)\n
            GCD(a, b) == 1\n
            Since elem. of field order does not exist in a field (= 0), b*y == 0\n
            a*x == 1\n
            and so x == inverse of a
        '''

        b = self.order
        solution = 0
        u = 1

        while a != 0:
            q = b // a
            r = b % a

            m = solution - u * q

            b = a
            a = r
            solution = u
            u = m

        return solution



if __name__ == "__main__":
    print("Running Galois module")