#include <iostream>
#include <utility>
#include <fmt/core.h>
#include <string_view>
#include "Galois.hpp"
#include "DHSetup.hpp"
#include "User.hpp"


/// @brief Establish secure channel between two parties
/// @tparam T 
/// @return 
template <typename T>
bool establish_communication(User<T>& alice, User<T>& bob);


int main()
{
    constexpr uint64_t order {1234567891};

    Galois<order>::print_info();

    DHSetup<Galois<order>> setup {};

    User<Galois<order>> alice {setup};
    User<Galois<order>> bob   {setup};


    if (!establish_communication<Galois<order>>(alice, bob))
    {
        fmt::print(fmt::fg(fmt::color::red), 
                  "Communication can not be established!\n");
        return -1;
    }

    Galois<order> msg {10};
    fmt::print("Message: {}\n", msg.value());

    auto cryptogram {bob.encrypt(msg)};

    if (cryptogram.error() == User<Galois<order>>::KeyError::encryption_not_set)
    {
        fmt::print(fmt::fg(fmt::color::red),
                  "Can not encrypt message\nEncryption key not established!");

        return -1;
    }

    fmt::print("Encrypted message: {}\n", (*cryptogram).value());

    auto decrypted_msg {alice.decrypt((*cryptogram).value())};

    if (decrypted_msg.error() == User<Galois<order>>::KeyError::private_not_set)
    {
        fmt::print(fmt::fg(fmt::color::red),
                  "Can not decrypt message\nPrivate key not set!");

        return -1;
    }

    fmt::print("Decrypted message: {}\n", (*decrypted_msg).value());

    return 0;
}




template <typename T>
bool establish_communication(User<T> &alice, User<T> &bob)
{
    // set Alice's and Bob's public keys to exchange
    auto pub_key_alice {alice.get_public_key()};
    auto pub_key_bob   {bob.get_public_key()};

    if (!pub_key_alice.has_value() || !pub_key_bob.has_value())
    {
        fmt::print(fmt::fg(fmt::color::red), "Public keys can not be set!\n");
        return false;
    }

    fmt::print("Alice pub_key: {}\n", (*pub_key_alice).value());
    fmt::print("Bob pub_key: {}\n\n", (*pub_key_bob).value());


    // set encryption key used in communication
    auto set_key_alice {alice.set_key((*pub_key_bob).value())};
    auto set_key_bob {bob.set_key((*pub_key_alice).value())};

    if (!set_key_alice || !set_key_bob)
    {
        fmt::print(fmt::fg(fmt::color::red), 
                  "Encryption key can not be established!\n");
        return false;
    }
    
    //! for debug purpose 
    fmt::print("Alice encryption_key: {}\n", alice.m_encryption_key.value());
    fmt::print("Bob encryption_key: {}\n\n", bob.m_encryption_key.value());

    return true;
}
