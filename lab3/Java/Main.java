package lab3.Java;

import lab2.Java.Galois;
import lab2.Java.Exceptions.OrderMismatchException;
import lab2.Java.Exceptions.PrimeMismatchException;
import lab3.Java.Exceptions.GeneratorNotFoundException;
import lab3.Java.Exceptions.KeyNotSetException;

public class Main {
    public static void main(String[] args) throws GeneratorNotFoundException {
        try {
            final long order = 1234567891;
            
            Galois a = new Galois(2, order);
            DHSetup<Galois> setup = new DHSetup<Galois>(a);
            System.out.printf("Generator: %d%n", setup.getGenerator().value());

            User<Galois> alice = new User<>(setup, a);
            User<Galois> bob = new User<>(setup, a);

            System.out.printf("Alice's pub_key: %d%n", alice.getPublicKey().value());
            System.out.printf("Bob's pub_key: %d%n%n", bob.getPublicKey().value());
            
            Galois msg = new Galois(10, order);
            System.out.printf("Message: %d%n%n", msg.value());
            
            // public keys exchange
            alice.setKey(bob.getPublicKey());
            bob.setKey(alice.getPublicKey());

            System.out.printf("Alice's encryption key: %d%n",  alice.m_encryptionKey.value());
            System.out.printf("Bob's encryption key: %d%n%n", bob.m_encryptionKey.value());
            
            Galois encryptedMsg =  alice.encrypt(msg);
            
            System.out.printf("Encrypted message: %d%n",  encryptedMsg.value());
            
            Galois decryptedMsg = bob.decrypt(encryptedMsg);

            System.out.printf("Decrypted message: %d%n", decryptedMsg.value());

            } catch (OrderMismatchException e) {
                e.printStackTrace();
            } catch (PrimeMismatchException e) {
                e.printStackTrace();
            } catch (KeyNotSetException e) {
                e.printStackTrace();
            }
        }
}
