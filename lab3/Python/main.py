import DHSetup as dh
import User as u
import sys
import os
sys.path.insert( 0, os.path.abspath(__file__ + "/../../../lab2/Python/") )
import Galois as field

if __name__ == "__main__":
    order = 1234567891
    setup = dh.DHSetup(field_order=order, field_class=field.Galois)
    alice = u.User(setup)
    bob = u.User(setup)

    # setting shared encryption key by public keys exchange
    alice.set_key(bob.get_public_key())
    bob.set_key(alice.get_public_key())
    print(alice._encryption_key)
    print(bob._encryption_key)

    msg = field.Galois(87123189, order)
    encrypted_msg = alice.encrypt(msg)
    decrypted_msg = bob.decrypt(encrypted_msg)
    print(f"""Message: {msg}\nEncrypted message: {encrypted_msg}\nDecrypted message: {decrypted_msg}""")