package lab2.Java;

import lab2.Java.Exceptions.OrderMismatchException;
import lab2.Java.Exceptions.PrimeMismatchException;

public interface GaloisInterface {

    long order();

    long value();

    /**
     * Walkaround method to be able to instantiate actuall Class implementing GaloisInterface
     *
     * Haven't thought af something better yet
     */
    GaloisInterface createObject(long value, long order);

    GaloisInterface add(GaloisInterface other) throws OrderMismatchException, PrimeMismatchException;

    GaloisInterface subtract(GaloisInterface other) throws OrderMismatchException, PrimeMismatchException;

    GaloisInterface multiply(GaloisInterface other) throws OrderMismatchException, PrimeMismatchException;

    GaloisInterface divide(GaloisInterface other) throws OrderMismatchException, PrimeMismatchException;

    GaloisInterface inverse() throws PrimeMismatchException;

    boolean equals(GaloisInterface other) throws OrderMismatchException;

    boolean notEquals(GaloisInterface other) throws OrderMismatchException;

    boolean lessThan(GaloisInterface other) throws OrderMismatchException;

    boolean lessThanOrEqual(GaloisInterface other) throws OrderMismatchException;

    boolean greaterThan(GaloisInterface other) throws OrderMismatchException;

    boolean greaterThanOrEqual(GaloisInterface other) throws OrderMismatchException;
}