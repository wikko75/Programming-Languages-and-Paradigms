#!/bin/bash

gcc -c test_ada_wrapper.c
gnat compile functions_loop_c_api.adb
gnat bind -n functions_loop_c_api.ali
gnat link -o test_ada_wrapper.out functions_loop_c_api.ali test_ada_wrapper.o -v

# well I shouldn't, but ...
rm *.ali *.o  