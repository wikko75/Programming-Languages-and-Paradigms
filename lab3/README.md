# Implementation of calculations in Diffe-Hellman key exchange protocol
## `Prerequisites`
* C++23
* [fmt](https://github.com/fmtlib/fmt) (installed on Linux)
* CMake
* Python
* Java

## `Details`
### Classes:
1. `DHSetup` - responsible for setting up publicly known information for both sides of communication:
   - field order
   - generator
     
2. `User` - party of communication
   - has its own private key
   - shares its public key to other users

Both classes make use of `Galois` class implemented in lab2.

#

### To establish communication channel:
1. Create `DHSetup` instance
2. Create `User`'s instances (they must be using the same `DHSetup` instance)
3. Exchange users' public keys to establish mutual encrypion key use in encrypion / decryption of messages.

   Example in main.cpp


## `Build and Run`
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
./build/Diffie_Hellman
```
---

## Java

Same as in lab2

<img src="https://external-content.duckduckgo.com/iu/?u=https%3A%2F%2Fi.pinimg.com%2Foriginals%2F52%2Ff3%2Fbb%2F52f3bbb811a55f7de12d30feb0a56e23.jpg&f=1&nofb=1&ipt=d6f6b0d391c513001e7b9210631fe43da98b81545b31eb2a930fee5a6caacd2c&ipo=images" alt="Michael Scott from The Office" width="200">

---

## Python
Sweet and easy:

``` powershell
python main.py
```
---


## `Sample usage in C++`
> main.cpp
``` C++
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

    auto encryped_msg {bob.encrypt(msg)};

    if (encryped_msg.error() == User<Galois<order>>::KeyError::encryption_not_set)
    {
        fmt::print(fmt::fg(fmt::color::red),
                  "Can not encrypt message\nEncryption key not established!");

        return -1;
    }

    fmt::print("Encrypted message: {}\n", (*encryped_msg).value());

    auto decrypted_msg {alice.decrypt((*encryped_msg).value())};

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
    
    //! for showcase / debug purpose 
    fmt::print("Alice encryption_key: {}\n", alice.m_encryption_key.value());
    fmt::print("Bob encryption_key: {}\n\n", bob.m_encryption_key.value());

    return true;
}
```

> output:
``` powershell
=====================
Galois field
Properties:
Order: 1234567891
=====================

Alice pub_key: 846361901
Bob pub_key: 552333465

Alice encryption_key: 1091707631
Bob encryption_key: 1091707631

Message: 12783
Encrypted message: 977775100
Decrypted message: 12783
```

## `Notes`
I'm satisfied with C++ implementation, but that's not a surprise...
