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

    fmt::print(fmt::fg(fmt::color::yellow),"\nEnd values:\na = {}\nb = {}\n\n", a.value(), b.value());

    return 0;
}