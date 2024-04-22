package lab3.Java.Exceptions;

public class KeyNotSetException extends Exception {
    public KeyNotSetException(String keyType) {
        super("Error " + keyType + " not set!");
        printStackTrace();
    }
}
