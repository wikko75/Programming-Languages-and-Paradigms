#include <stdio.h>
#include "python_wrapper.h"
// #include <Python.h>


// static PyObject* p_module = NULL;


int main()
{
//     Py_Initialize();

//     // Add current path to python module search paths
//     PyObject *sys = PyImport_ImportModule("sys");
//     PyObject *path = PyObject_GetAttrString(sys, "path");
//     PyList_Append(path, PyUnicode_FromString("."));


//     p_module = PyImport_ImportModule("func");

//     if (p_module)
//     {
//         PyObject* pFunc = PyObject_GetAttrString(p_module, "factorial");

//         if (pFunc && PyCallable_Check(pFunc))
//         {
//             // Przygotowanie argumentu dla funkcji
//             PyObject* pArgs = PyTuple_New(1);
//             PyTuple_SetItem(pArgs, 0, PyLong_FromLong(5)); // Przekazanie argumentu 5

//             // Wywołanie funkcji 'factorial' z przekazanym argumentem
//             PyObject* pResult = PyObject_CallObject(pFunc, pArgs);

//             if (pResult != NULL)
//             {
//                 // Wyświetlenie wyniku
//                 printf("Result: %ld\n", PyLong_AsLong(pResult));
//                 Py_DECREF(pResult);
//             }
//             else
//             {
//                 PyErr_Print();
//             }
//         }
//         else
//         {
//             if (PyErr_Occurred())
//                 PyErr_Print();
//             fprintf(stderr, "Cant find function\n");
//         }

//         Py_XDECREF(pFunc);
//         Py_DECREF(p_module);
//     }
//     else
//     {
//         PyErr_Print();
//         fprintf(stderr, "Cant't load module\n");
//     }

//     Py_Finalize();

    if(init_wrapper() != 0)
    {
        printf("Initializing failed!\n");
        return 0;
    }

    int factorial_res = factorial(5);

    printf("Factorial: %d\n", factorial_res);

    printf("GCD: %d\n", gcd(12, 4));

    struct Solution solution = diofantic_eq(1914, 899);

    printf("Diofantic_eq: [ X = %d, Y = %d ]\n", solution.x, solution.y);

    finalize_wrapper();
    
    return 0;
}