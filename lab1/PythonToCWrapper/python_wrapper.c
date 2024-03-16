#include <stdio.h>
#include <Python.h>
#include "python_wrapper.h"

/*
    C wrappper of Python functions from Python folder.

    Versions:
     - iterative (default)
     - recursive

    If you wish to change functions version, modify:
    
    p_module = PyImport_ImportModule("functions_iterative");

    to

    p_module = PyImport_ImportModule("functions_recursive");

*/


static PyObject* p_module = NULL;

int init_wrapper()
{

    printf("Initializing Wrapper...\n");
    Py_Initialize();

    // Add ../Python/functions_iterative.py  path to python's 'module search paths'
    PyObject *sys = PyImport_ImportModule("sys");
    PyObject *path = PyObject_GetAttrString(sys, "path");
    PyList_Append(path, PyUnicode_FromString("../Python"));

    p_module = PyImport_ImportModule("functions_iterative");

    if (!p_module)
    {
        printf("p_module not initialized!\nCheck if python module has been imported!\n");
        Py_XDECREF(sys);
        Py_XDECREF(path);
        finalize_wrapper();
        return -1;
    }

    Py_XDECREF(sys);
    Py_XDECREF(path);
    return 0;
}


int factorial(int n)
{
    if (!p_module)
    {
        printf("p_module not initialized!\nCheck if python module has been imported!\n");
        return -1;
    }
    
    PyObject* p_factorial = PyObject_GetAttrString(p_module, "factorial");

    if (!p_factorial || !PyCallable_Check(p_factorial))
    {
        fprintf(stderr, "Can't find function or object not callable\n");

        if (PyErr_Occurred())
        {
            PyErr_Print();
        }

        Py_XDECREF(p_factorial);
        return -1;
    }

    PyObject* p_factorial_args = PyTuple_New(1);
    PyTuple_SetItem(p_factorial_args, 0, PyLong_FromLong(n));

    PyObject* p_factorial_result = PyObject_CallObject(p_factorial, p_factorial_args);

    if (!p_factorial_result)
    {
        printf("Cant't retrive result!\n");
        PyErr_Print();

        Py_XDECREF(p_factorial);
        Py_XDECREF(p_factorial_result);
        Py_XDECREF(p_factorial_args);

        return -1;
    }

    int result = (int) PyLong_AsLong(p_factorial_result);
    // printf("Result: %ld\n", PyLong_AsLong(p_factorial_result));

    Py_DECREF(p_factorial);
    Py_DECREF(p_factorial_result);
    Py_DECREF(p_factorial_args);


    return result;
}


int gcd(int a, int b)
{
    if (!p_module)
    {
        printf("p_module not initialized!\nCheck if python module has been imported!\n");
        return -1;
    }
    
    PyObject* p_gcd_eq = PyObject_GetAttrString(p_module, "gcd");

    if (!p_gcd_eq || !PyCallable_Check(p_gcd_eq))
    {
        fprintf(stderr, "Can't find function or object not callable\n");

        if (PyErr_Occurred())
        {
            PyErr_Print();
        }

        Py_XDECREF(p_gcd_eq);
        return -1;
    }

    PyObject* p_gcd_args = PyTuple_New(2);
    PyTuple_SetItem(p_gcd_args, 0, PyLong_FromLong(a));
    PyTuple_SetItem(p_gcd_args, 1, PyLong_FromLong(b));

    PyObject* p_gcd_result = PyObject_CallObject(p_gcd_eq, p_gcd_args);

    if (!p_gcd_result)
    {
        printf("Cant't retrive result!\n");
        PyErr_Print();

        Py_XDECREF(p_gcd_eq);
        Py_XDECREF(p_gcd_result);
        Py_XDECREF(p_gcd_args);

        return -1;
    }

    int result = (int) PyLong_AsLong(p_gcd_result);
    // sprintf("Result: %ld\n", PyLong_AsLong(p_gcd_result));

    Py_DECREF(p_gcd_eq);
    Py_DECREF(p_gcd_result);
    Py_DECREF(p_gcd_args);


    return result;
}


struct Solution diofantic_eq(int a, int b)
{   
    struct Solution solution =  {-111, -111};
    if (!p_module)
    {
        printf("p_module not initialized!\nCheck if python module has been imported!\n");
        return solution;
    }
    
    PyObject* p_diofantic_eq = PyObject_GetAttrString(p_module, "diofantic_eq");

    if (!p_diofantic_eq || !PyCallable_Check(p_diofantic_eq))
    {
        fprintf(stderr, "Can't find function or object not callable\n");

        if (PyErr_Occurred())
        {
            PyErr_Print();
        }

        Py_XDECREF(p_diofantic_eq);
        return solution;
    }

    PyObject* p_diofantic_eq_args = PyTuple_New(2);
    PyTuple_SetItem(p_diofantic_eq_args, 0, PyLong_FromLong(a));
    PyTuple_SetItem(p_diofantic_eq_args, 1, PyLong_FromLong(b));

    PyObject* p_diofantic_eq_result = PyObject_CallObject(p_diofantic_eq, p_diofantic_eq_args);


    if (!p_diofantic_eq_result)
    {
        printf("Cant't retrive result!\n");
        PyErr_Print();

        Py_XDECREF(p_diofantic_eq);
        Py_XDECREF(p_diofantic_eq_result);
        Py_XDECREF(p_diofantic_eq_args);
    }

    PyObject* p_x_res = PyObject_GetAttrString(p_diofantic_eq_result, "x");
    PyObject* p_y_res = PyObject_GetAttrString(p_diofantic_eq_result, "y");

    if (!p_x_res || !p_y_res)
    {
        PyErr_Print();

        Py_XDECREF(p_diofantic_eq);
        Py_XDECREF(p_diofantic_eq_result);
        Py_XDECREF(p_diofantic_eq_args);
        Py_DECREF(p_x_res);
        Py_DECREF(p_y_res);

        return solution;
    }
    
    solution.x = (int) PyLong_AsLong(p_x_res);
    solution.y = (int) PyLong_AsLong(p_y_res);
    
    // printf("Result: [ X = %d, Y = %d ]\n", solution.x, solution.y);

    Py_DECREF(p_diofantic_eq);
    Py_DECREF(p_diofantic_eq_result);
    Py_DECREF(p_diofantic_eq_args);
    Py_DECREF(p_x_res);
    Py_DECREF(p_y_res);

    return solution;
}



void finalize_wrapper()
{
    Py_CLEAR(p_module);
    Py_Finalize();
}
