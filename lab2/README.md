# C++ / Java / Python implementation of finite field
Reference: [Galois field](https://en.wikipedia.org/wiki/Finite_field)
## Prerequisites
* C++ 20+
* [fmt](https://github.com/fmtlib/fmt) (installed on Linux)
* CMake
* Python
* Java
## Details
**C++** and **Python** overload following operators:
- compound assignment
- arithmetic
- relational

Additionaly **C++**:
- overloads stream operators (insertion and extraction)
- performs valid operations with left / right operand being an _int_64_t_ literal

Since **Java** doesn't allow operator overloading, each operator has its corresponding action defined inside a member function.

## Build and Run
##  C++

- building
``` powershell
cd C++
```
``` powershell
cmake -S . -B build && cmake build --build
```
- running main.cpp
``` powershell
./build/Galois
```
- running tests

``` powershell
ctest --test-dir ./build --output-on-failure
```
---

## Java

I'm not a Java guy.

I used VS code with _Extension Pack for Java_ - it even worked! <br>
But you're gonna have to figure it out on your own...

<img src="https://static1.moviewebimages.com/wordpress/wp-content/uploads/2023/01/the-office-michael-scott.jpg" alt="Michael Scott from The Office" width="400">

---

## Python
Sweet and easy:

``` powershell
python main.py
```
---





