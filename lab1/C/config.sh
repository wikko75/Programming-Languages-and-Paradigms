gcc -o func_test.out func_test.c  -Llib -l:func_iterative.a  

# or direct compilation of lib file
# gcc -o func_test.out  func_test.c func_iterative.c