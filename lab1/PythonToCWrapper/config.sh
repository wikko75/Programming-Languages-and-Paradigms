#!/bin/bash
gcc -o test_wrapper.out test.c python_wrapper.c -I /usr/include/python3.11 -L /usr/lib/python3.11/config-3.11-x86_64-linux-gnu -lpython3.11