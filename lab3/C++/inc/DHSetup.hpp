#ifndef DH_SETUP_HPP
#define DH_SETUP_HPP

#include <random>
#include <vector>
#include <optional>
#include <algorithm>
#include <stdint.h> 
#include <fmt/color.h>
#include <fmt/ranges.h>


template <typename T>
class DHSetup
{

public:
    DHSetup()
    {
        m_order = T::get_order();

        auto generator { choose_generator() };

        if (!generator)
        {
            fmt::print(fg(fmt::color::red), "Generator could not be found!\n");
            return;
        }

        m_generator = generator.value();
    }


    auto get_generator() const noexcept -> T 
    {
        return m_generator;
    }


    constexpr auto power(T a, uint64_t b) const -> T
    {
        T res {1};
        while (b > 0) 
        {
            if (b & 1)
            {
                res *= a;
            }

            b /= 2 ; 
            a *= a; 
        }

        return res;
    }


    ~DHSetup() = default;

private:
    T m_generator;
    uint64_t m_order;

    constexpr auto is_prime(uint64_t n) noexcept -> bool
    {
        if (n < 2) 
        {
            return false;
        }
        uint64_t a = 2;
        while (a * a <= n) 
        {
            if (n % a == 0) 
            {
                return false;
            }
            ++a;
        }

        return true;
    }

    constexpr auto prime_divisors(uint32_t p) noexcept -> std::vector<uint64_t>
    {
        std::vector<uint64_t> divisors {};
        for (uint64_t i {2}; i * i <= p; ++i) 
        {
            if (p % i == 0 && is_prime(i)) 
            {
                divisors.push_back(i);
                while (p % i == 0) 
                {
                    p /= i;
                }
            }
        }

        if (p > 1) 
        {
            divisors.push_back(p);
        }

        return divisors;
    }

    auto choose_generator() noexcept -> std::optional<uint64_t>
    {
        auto rng {std::random_device{}};

        std::uniform_int_distribution<uint64_t> dist {1,  m_order - 1};

        uint64_t generator {};

        // ensures we won't jump into an infinite loop
        uint64_t safety_counter {};
        
        while (true)
        {
            generator = dist(rng);

            std::vector<uint64_t> divisors { prime_divisors(m_order - 1) };
            fmt::print("divisors: {}\n", divisors);

            bool is_generator_predicate_satisfied { std::none_of(divisors.begin(), divisors.end(), [*this, generator](uint64_t elem) {
                    return power(generator, (m_order - 1) / elem ) == 1;
                    }) };
            
            if (is_generator_predicate_satisfied)
            {
                return generator;
            }

            safety_counter += 1;

            // generator should be found up to 2*N tries
            if (safety_counter > 2 * (m_order - 2))
            {
                break;
            }
        }

       return {};
    }

};

#endif