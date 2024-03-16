import ctypes
import os

""" Wrapper for C library.
    Iterative implementation of
        - factorial
        - gcd 
        - diofantic eq.
"""
lib_path = os.path.dirname(os.path.abspath(__file__)) + "/func_loop.so"

lib_c_functions = ctypes.CDLL(lib_path)

factorial = lib_c_functions.factorial

""" int factorial(int n) """
factorial.argtypes = [ctypes.c_int]
factorial.restype = ctypes.c_int

gcd = lib_c_functions.gcd

""" int gcd(int a, int b) """
gcd.argtypes = [ctypes.c_int, ctypes.c_int]
gcd.restype = ctypes.c_int


class Solution(ctypes.Structure):
    _fields_ = [ ("x", ctypes.c_int), ("y", ctypes.c_int)]

diofantic_eq = lib_c_functions.diofantic_eq

""" Solution diofantic_eq(int a, int b) """
diofantic_eq.argtypes = [ctypes.c_int, ctypes.c_int]
diofantic_eq.restype = Solution
