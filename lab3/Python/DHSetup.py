import sys
import os
import random
import math

sys.path.insert( 0, os.path.abspath(__file__ + "/../../../lab2/Python/") )
import Galois as field


class DHSetup:
    def __init__(self, field_order : int, field_class : field.Galois):
        self.field_class = field_class
        self.m_order : int = field_order

        self.m_generator : field_class = None

        generator : field_class = self._choose_generator()
        if generator is None:
            print("Generator could not be found!")
            return
        self.m_generator = generator

    def get_generator(self):
        return self.m_generator

    def power(self, a, b : int):
        res : self.field_class = self._field_instace(1)
        while b > 0:
            if b & 1:
                res = res * a
            b = b // 2
            a *= a
        return res

    def _is_prime(self, n) -> bool:
        if n < 2:
            return False
        a = 2
        while a * a <= n:
            if n % a == 0:
                return False
            a += 1
        return True

    def _prime_divisors(self, p : int) -> list[int]:
        divisors = []
        for i in range(2, int(math.sqrt(p)) + 1):
            if p % i == 0 and self._is_prime(i):
                divisors.append(i)
                while p % i == 0:
                    p //= i
        if p > 1:
            divisors.append(p)
        return divisors

    def _choose_generator(self):
        generator : self.field_class= None
        safety_counter = 0
        divisors = self._prime_divisors(self.m_order - 1)
        print(divisors)
        while True:
            generator = self._field_instace(random.randint(1, self.m_order - 1))

            is_generator_predicate_satisfied = all(self.power(generator, (self.m_order - 1) // elem) != self._field_instace(1) for elem in divisors)

            if is_generator_predicate_satisfied:
                return generator

            safety_counter += 1
            if safety_counter > 2 * (self.m_order - 2):
                break

        return None
    
    def _field_instace(self, value : int):
        return self.field_class(value, self.m_order)





if __name__ == "__main__":
    print("Running DHSetup module")