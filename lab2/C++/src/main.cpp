#include <iostream>
#include <fmt/core.h>
#include "Galois.hpp"

int main()
{
    constexpr int64_t order {1234577};
    
    Galois<order> a(15);
    Galois<order> b(1234576);
        

    Galois<order>::print_info();


    fmt::print(fmt::fg(fmt::color::yellow),"Initial values:\na = {}\nb = {}\n\n", a.value(), b.value());


    fmt::print("a + b =     {}\n", (a + b).value());
    fmt::print("int64 + b = {}\n", (1234578 + b).value());
    fmt::print("a + int64 = {}\n\n", (a + 4).value());

    fmt::print("a - b =     {}\n", (a - b).value());
    fmt::print("b - int64 = {}\n", (b - 4).value());
    fmt::print("int64 - b = {}\n\n", (4 - b).value());

    fmt::print("a * b =     {}\n", (a * b).value());
    fmt::print("int64 * b = {}\n", (1234578 * b).value());
    fmt::print("a * int64 = {}\n\n", (a * 4).value());


    fmt::print("a = {}\n~a = {}\n", a.value(), (~b).value());
    fmt::print("Check: a * ~a = {}\n\n", (a * ~a).value());

    fmt::print("a / b = {}\n", (a / b).value());
    fmt::print("Check: a / b * b = {}\n", (a / b * b).value());
    fmt::print("int64 / b = {}\n", (10 / b).value());
    fmt::print("a / int64 = {}\n\n", (a / 10).value());


    if(15 == a)
    {
        fmt::print("equal!\n");
    }
    else
    {
        fmt::print("not equal!\n");
    }


    if (a == b)
    {
        fmt::print("equal!\n");

    }
    else
    {

        fmt::print("not equal!\n");
    }

    if (a != b)
    {
        fmt::print("not equal!\n");
    }
    else
    {
        fmt::print("equal!\n");
    }

    if(-20 <= a)
    {
        fmt::print("Smaller!\n");
    }
    else
    {
        fmt::print("Greater!\n");
    }

    if (a >= 5)
    {
        fmt::print("Greater!\n");
    }
    else
    {
        fmt::print("Smaller!\n");
    }

    if (5 >= b)
    {
        fmt::print("Greater!\n");
    }
    else
    {
        fmt::print("Smaller!\n");
    }

    fmt::print(fmt::fg(fmt::color::yellow),"\nEnd values:\na = {}\nb = {}\n\n", a.value(), b.value());

    std::cin >> b;
    std::cout << "b = " << b << "\n";

    std::cout << a << "\n";

    return 0;
}

// TODO include GTest