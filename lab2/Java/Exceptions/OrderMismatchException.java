package lab2.Java.Exceptions;

import lab2.Java.Galois;

public class OrderMismatchException extends Exception{
    public OrderMismatchException(String function) {
        super(function + " invoked on object of " + Galois.class + " with different field order that field order of argument.");
    }
}
