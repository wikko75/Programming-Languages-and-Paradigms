#ifndef DH_USER_HPP
#define DH_USER_HPP

#include "DHSetup.hpp"
#include <expected>
#include <random>

template <typename T>
class User
{
public:

    enum class KeyError
    {
        private_not_set,
        encryption_not_set
    };


    explicit User(DHSetup<T>& DH_setup) 
        : m_DH_setup {DH_setup}
        , is_private_key_set {false}
        , is_encription_key_set {false}
    {
        // get random private key
        std::mt19937 rng {std::random_device{}()};
        std::uniform_int_distribution<uint64_t> range {0, T::get_order() - 1};

        m_private_key = range(rng);
        is_private_key_set = true;
    }

    auto get_public_key() const -> std::expected<T, KeyError>
    {
        if (!is_private_key_set)
        {
            return std::unexpected(KeyError::private_not_set);
        }

        return m_DH_setup.power(m_DH_setup.get_generator(), m_private_key.value());
    }

    auto set_key(T public_key) -> std::expected<void, KeyError>
    {
        if (!is_private_key_set)
        {
            return std::unexpected(KeyError::private_not_set);
        }

        m_encryption_key = m_DH_setup.power(public_key, m_private_key.value());
        is_encription_key_set = true;
        return {};
    }

    auto encrypt(T msg) const -> std::expected<T, KeyError>
    {
        if (!is_encription_key_set)
        {
            
            return std::unexpected(KeyError::encryption_not_set);
        }

        return msg * m_encryption_key;
    }

    auto decrypt(T c) const -> std::expected<T, KeyError> 
    {
        if (!is_private_key_set)
        {
            return std::unexpected(KeyError::private_not_set);
        }

        return c / m_encryption_key;
    }

private:
    DHSetup<T>& m_DH_setup;
    bool is_private_key_set;
    bool is_encription_key_set;

    T m_private_key;
public:
    // TODO move to private
    T m_encryption_key;
};

#endif