import sys, os
sys.path.insert( 0, os.path.abspath(__file__ + "/../../../lab2/Python/") )
import Galois as field
import DHSetup as dh
import random


class KeyNotSetException(Exception):
    def __init__(self, key_type : str) -> None:
        super().__init__(f"Error: {key_type} key not set!")


class User:
    def __init__(self, dh_setup : dh.DHSetup) -> None:
        self._private_key = None
        self._encryption_key = None
        self._dh_setup = dh_setup
        self._private_key = random.randint(0, dh_setup.m_order - 1)

    def get_public_key(self):
        if self._private_key is None:
            raise KeyNotSetException("Private")
        return self._dh_setup.power(self._dh_setup.get_generator(), self._private_key)

    def set_key(self, public_key):
        if self._private_key is None:
            raise KeyNotSetException("Private")
        self._encryption_key = self._dh_setup.power(public_key, self._private_key)

    def encrypt(self, msg):
        if self._encryption_key is None:
            raise KeyNotSetException("Encryption")        
        return msg * self._encryption_key
    
    def decrypt(self, encrypted_msg):
        if self._encryption_key is None:
            raise KeyNotSetException("Encryption")
        return encrypted_msg / self._encryption_key
    




if __name__ == "__main__":
    print("Running User module")