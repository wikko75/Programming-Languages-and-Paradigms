#include <iostream>
#include <fmt/core.h>
#include "Galois.hpp"
#include "DHSetup.hpp"

int main()
{
    fmt::print("Hello!\n");
    DHSetup<Galois<1234567891>> setup {};

    fmt::print("order: {}\n", Galois<11>::get_order());


    fmt::print("Gen: {}", setup.get_generator().value());
    return 0;
}
