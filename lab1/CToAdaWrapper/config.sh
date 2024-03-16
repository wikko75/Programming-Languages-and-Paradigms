#!/bin/bash

gcc -c func_recursion.c
gnat make -c test_c_wrapper.adb -v
gnat bind test_c_wrapper.ali -v
gnat link -o test_c_wrapper.out test_c_wrapper.ali func_recursion.o -v


# or (only lib provided)
# gnat make -c test_c_wrapper.adb -v
# gnat bind test_c_wrapper.ali -v
# gnat link -o test_c_wrapper test_c_wrapper.ali lib/func_recursion.a -v