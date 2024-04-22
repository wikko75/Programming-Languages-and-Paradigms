package lab2.Java.Exceptions;

public class PrimeMismatchException extends Exception{
    public PrimeMismatchException() {
        super("Field order must be a prime number");
    }
}
