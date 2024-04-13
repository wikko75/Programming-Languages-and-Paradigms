#ifndef GALOIS_INL
#define GALOIS_INL

#include "Galois.hpp"
#include <fmt/color.h>
#include <utility>


template <u_int64_t Order>
inline Galois<Order>::Galois(int64_t value)
   : m_value{value >= 0 ? static_cast<int64_t>(value % Order) : static_cast<int64_t>((Order + value) % Order)}
{
    
}


template <u_int64_t Order>
constexpr auto Galois<Order>::operator+=(const Galois<Order>& other) -> Galois<Order>&
{
    m_value = (m_value + other.m_value) % Order;
    return *this;
}


template <u_int64_t Order>
constexpr auto Galois<Order>::operator-=(const Galois<Order>& other) -> Galois<Order>&
{
    // a -= b  ->  -b => (order - b)  
    // ex. order = 5, a = 3, -a = 5 - 3 = 2 , because  3 + 2 = 0
    m_value = (m_value + (Order - other.m_value)) % Order;
    return *this;
}


template <u_int64_t Order>
constexpr auto Galois<Order>::operator*=(const Galois<Order>& other) -> Galois<Order>&
{
    m_value = (m_value * other.m_value) % Order;
    return *this;
}


template <u_int64_t Order>
constexpr auto Galois<Order>::operator/=(const Galois<Order>& other) -> Galois<Order>&
{
    *this *= ~other;
    return *this;
}


template <u_int64_t Order>
constexpr auto Galois<Order>::operator~() const -> Galois
{
    return {diofantic_eq(m_value)};
}


// works on both a + b and a + int
template <u_int64_t Order>
constexpr auto Galois<Order>::operator+(const Galois<Order>& b) const-> Galois<Order>
{
    return {m_value + b.m_value};
}


template <u_int64_t Order>
constexpr auto operator+(int64_t a, const Galois<Order>& b) -> Galois<Order>
{
    return {a + b.m_value};
}


template <u_int64_t Order>
constexpr auto Galois<Order>::operator-(const Galois<Order> &b) const-> Galois<Order>
{
    return {m_value - b.m_value};
}


template <u_int64_t Order>
constexpr auto operator-(int64_t a, const Galois<Order> &b) -> Galois<Order>
{
    return {a - b.m_value};
}


template <u_int64_t Order>
constexpr auto Galois<Order>::operator*(const Galois &b) const -> Galois
{
    return {m_value * b.m_value};
}


template <u_int64_t Order>
constexpr auto operator*(int64_t a, const Galois<Order>& b) -> Galois<Order>
{
    return {a * b.m_value};
}


template <u_int64_t Order>
constexpr auto operator/(int64_t lhs, const Galois<Order> &rhs) -> Galois<Order>
{
    return {lhs * (~rhs).m_value};
}


template <u_int64_t Order>
constexpr auto Galois<Order>::operator/(const Galois<Order> &rhs) const -> Galois<Order>
{
    return {*this * ~rhs};
}


template <u_int64_t Order>
constexpr auto operator==(const int64_t lhs, const Galois<Order> &rhs) -> bool
{ 
    return Galois<Order>(lhs) == rhs;
}


template <u_int64_t Order>
constexpr auto Galois<Order>::operator==(const Galois<Order> &other) const -> bool
{
    return m_value == other.m_value;
}


template <u_int64_t Order>
auto operator!=(const int64_t lhs, const Galois<Order> &rhs) -> bool
{
    return !(lhs == rhs);
}


template <u_int64_t Order>
constexpr auto Galois<Order>::operator!=(const Galois<Order> &other) const -> bool
{
    return !(*this == other);
}


template <u_int64_t Order>
constexpr auto operator<(const int64_t lhs, const Galois<Order> &rhs) -> bool
{
    return Galois<Order>(lhs) < rhs;
}


template <u_int64_t Order>
constexpr auto Galois<Order>::operator<(const Galois &other) const -> bool
{
    return m_value < other.m_value;
}


template <u_int64_t Order>
constexpr auto operator<=(const int64_t lhs, const Galois<Order> &rhs) -> bool
{
    return !(Galois<Order>(lhs) > rhs);
}


template <u_int64_t Order>
inline constexpr auto Galois<Order>::operator<=(const Galois &other) const -> bool
{
    return !(*this > other);
}


template <u_int64_t Order>
constexpr auto operator>(const int64_t lhs, const Galois<Order> &rhs) -> bool
{
    return Galois<Order>(lhs) > rhs;
}


template <u_int64_t Order>
inline constexpr auto Galois<Order>::operator>(const Galois &other) const -> bool
{
    return m_value > other.m_value;
}


template <u_int64_t Order>
constexpr auto operator>=(const int64_t lhs, const Galois<Order> &rhs) -> bool
{
    return !(Galois<Order>(lhs) < rhs);
}


template <u_int64_t Order>
inline constexpr auto Galois<Order>::operator>=(const Galois &other) const -> bool
{
    return !(*this < other);
}



template <u_int64_t Order>
constexpr auto operator<<(std::ostream& stream, const Galois<Order>& a) -> std::ostream&
{
    stream << a.m_value;
    return stream;
}
 

template <u_int64_t Order>
constexpr auto operator>>(std::istream& stream, Galois<Order>& a) -> std::istream&
{
    int64_t temp {};
    
    if (stream >> temp)
    {
        temp = temp >= 0 ? static_cast<int64_t>(temp % Order)
                         : static_cast<int64_t>((Order + temp) % Order);

        a.m_value = temp;
        return stream;
    }

    stream.setstate(std::ios::failbit);

    //TODO throw some exception
    return stream;
}   


template <u_int64_t Order>
constexpr auto Galois<Order>::value() const noexcept -> int64_t
{
    return m_value;
}


template<u_int64_t Order>
inline auto Galois<Order>::print_info() noexcept -> void
{
    fmt::print(fmt::fg(fmt::color::red), "=====================\n");
    fmt::print(fmt::fg(fmt::color::yellow), "Galois field\n");
    fmt::print(fmt::fg(fmt::color::green), "Properties:\n");
    fmt::print("Order: {}\n", Order);
    fmt::print(fmt::fg(fmt::color::red), "=====================\n\n");
}

template <u_int64_t Order>
constexpr auto Galois<Order>::diofantic_eq(int64_t a) const -> int64_t
{
    uint64_t b {Order};
    uint64_t solution {0};
    int64_t u = 1;

    while (a != 0) 
    {
        uint64_t q = b / a;
        uint64_t r = b % a;

        uint64_t m = solution - u * q;

        b = a;
        a = r;
        solution = u;
        u = m;
    }

    return solution;
}

#endif