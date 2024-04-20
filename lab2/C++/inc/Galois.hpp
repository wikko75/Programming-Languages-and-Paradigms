#ifndef GALOIS_HPP
#define GALOIS_HPP

#include <iostream>
#include <stdint.h>

/**
 * Since I use Galois only in one .cpp file (main.cpp) that makes use of inline functions,
 * I'm gonna simply #include Galois.inl at the bottom.
 * Otherwise (many translation units, not every one willing to use inline functions),
 * it's a good practice not to include definitions (Galois.inl) in .hpp
 * and instead include .inl only in files that will use inline functions 
 * (at least that's what I've read...)
**/



template <uint64_t Order>
class Galois
{
private:
    int64_t m_value;
public:
    Galois() = default;

    Galois(int64_t value);
    

    //* compound assignment operators

    constexpr auto operator+=(const Galois& other) -> Galois&;

    constexpr auto operator-=(const Galois& other) -> Galois&;

    constexpr auto operator*=(const Galois& other) -> Galois&;

    constexpr auto operator/=(const Galois& other) -> Galois&;


    //* arithmetic operators (don't change the order!!!)

    constexpr auto operator~() const -> Galois;

    friend constexpr auto operator+ <> (int64_t a, const Galois& b) -> Galois;

    constexpr auto operator+(const Galois& b) const -> Galois;

    friend constexpr auto operator- <> (int64_t a, const Galois& b) -> Galois;

    constexpr auto operator-(const Galois& b) const -> Galois;

    friend constexpr auto operator* <> (int64_t a, const Galois& b) -> Galois;

    constexpr auto operator*(const Galois& b) const -> Galois;

    friend constexpr auto operator/ <> (int64_t lhs, const Galois& rhs) -> Galois;

    constexpr auto operator/(const Galois& rgs) const -> Galois;



    //* relation operators

    friend constexpr auto operator== <> (const int64_t lhs, const Galois& rhs) -> bool;

    constexpr auto operator==(const Galois& other) const -> bool;

    friend auto operator!= <> (const int64_t lhs, const Galois& rhs) -> bool;

    constexpr auto operator!=(const Galois& other) const -> bool;

    friend constexpr auto operator< <> (const int64_t lhs, const Galois& rhs) -> bool;

    constexpr auto operator<(const Galois& other) const -> bool;
    
    friend constexpr auto operator<= <> (const int64_t lhs, const Galois& rhs)  -> bool;

    constexpr auto operator<=(const Galois& other) const -> bool;

    friend constexpr auto operator> <> (const int64_t lhs, const Galois& rhs) -> bool;

    constexpr auto operator>(const Galois& other) const -> bool;

    constexpr auto operator>=(const Galois& other) const -> bool;


    
    //* stream operators

    friend constexpr auto operator<< <> (std::ostream& stream, const Galois& a) -> std::ostream&;

    friend constexpr auto operator>> <> (std::istream& stream, Galois& a) -> std::istream&;


    constexpr auto value() const noexcept -> int64_t;


    static constexpr auto print_info() noexcept -> void;
    static constexpr auto is_prime() -> bool;

    static constexpr auto get_order() noexcept -> uint64_t;

    ~Galois() = default;

private:
    constexpr auto diofantic_eq(int64_t a) const -> int64_t;
};

#include "Galois.inl"

#endif