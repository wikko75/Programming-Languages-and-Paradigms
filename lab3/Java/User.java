package lab3.Java;

import java.util.concurrent.ThreadLocalRandom;
import lab2.Java.GaloisInterface;
import lab2.Java.Exceptions.OrderMismatchException;
import lab2.Java.Exceptions.PrimeMismatchException;
import lab3.Java.Exceptions.KeyNotSetException;


public class User<T extends GaloisInterface> {

    User(DHSetup<T> setup, T fieldElem)  {
        this.m_setup = setup;
        this.isPrivateKeySet = false;
        this.isPrivateKeySet = false;

        this.m_privateKey = (T) fieldElem.createObject(ThreadLocalRandom.current().nextLong(1, setup.getOrder()), setup.getOrder());
        this.isPrivateKeySet = true;
    }


    public T getPublicKey() throws KeyNotSetException, OrderMismatchException, PrimeMismatchException {
        if (!isPrivateKeySet)
        {
            throw new KeyNotSetException("PRIVATE");
        }
        this.isPrivateKeySet = true;
        return this.m_setup.power(m_setup.getGenerator(), m_privateKey.value());
    }

    public void setKey(T public_key) throws KeyNotSetException, OrderMismatchException, PrimeMismatchException {
        if (!isPrivateKeySet) {
            throw new KeyNotSetException("PRIVATE");
        }
        
        this.m_encryptionKey = m_setup.power(public_key, this.m_privateKey.value());
        isEncryptionKeySet = true;
    }

    public T encrypt(T msg) throws KeyNotSetException, OrderMismatchException, PrimeMismatchException {
        if (!isEncryptionKeySet)
        {
            
            throw new KeyNotSetException("ENCRYPTION");
        }

        return (T) msg.multiply(this.m_encryptionKey);
    }

    public T  decrypt(T c) throws KeyNotSetException, OrderMismatchException, PrimeMismatchException {
        if (!isEncryptionKeySet)
        {   
            throw new KeyNotSetException("ENCRYPTION");
        }

        return (T) c.divide(this.m_encryptionKey);
    }


    private DHSetup<T> m_setup;
    private Class<T> galois;
    private T m_privateKey;
    // TODO make private
    public T m_encryptionKey;
    private boolean isPrivateKeySet;
    private boolean isEncryptionKeySet;

    
}
