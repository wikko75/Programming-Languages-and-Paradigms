package lab2.Java;

import lab2.Java.Exceptions.OrderMismatchException;
import lab2.Java.Exceptions.PrimeMismatchException;

public class Galois implements GaloisInterface {

    private static long s_order = 1234577;

    public static void printInfo() {
        System.out.println("=============\n" +
        "Galois\n" +
        "Properties:\n" +
        String.format("Default order: %s\n", s_order) +
        "=============");
    }


    public static Galois valueOf(long value, long order) throws PrimeMismatchException {
        return new Galois(value, order);
    }
    
    
    public Galois(long value, long order) throws PrimeMismatchException {
        if (!isPrime(order)) {
            throw new PrimeMismatchException();
        }
        m_order = order;
        m_value = value >= 0 ? value % m_order : (m_order + value);
    }

    @Override
    public GaloisInterface createObject(long value, long order) {
        try {
            return new Galois(value, order);
        } catch (Exception e) {

            e.printStackTrace();
        }
        return null;
    }
    
    @Override
    public GaloisInterface add(GaloisInterface other) throws OrderMismatchException, PrimeMismatchException {
        if (!checkOrder(other)) {
            throw new OrderMismatchException("add()");
        }
        return new Galois((this.m_value + other.value()) % this.m_order, this. m_order);
    }
    
    @Override
    public GaloisInterface subtract(GaloisInterface other) throws OrderMismatchException, PrimeMismatchException {
        if (!checkOrder(other)) {
            throw new OrderMismatchException("sub()");
        }
        
        long value = (this.m_value - other.value());
        
        if (value < 0) {
            value = (this.m_order + this.m_value);
            
            return new Galois(value, this.m_order);
        }
        
        value %= this.m_order;
        return new Galois(value, this.m_order);
    }
    
    @Override
    public GaloisInterface multiply(GaloisInterface other) throws OrderMismatchException, PrimeMismatchException {
        if (!checkOrder(other)) {
            throw new OrderMismatchException("multiply()");
        }
        
        return new Galois((this.m_value * other.value()) % this.m_order, this.m_order);
    }
    
    @Override
    public GaloisInterface divide(GaloisInterface other) throws OrderMismatchException, PrimeMismatchException {
        if (!checkOrder(other)) {
            throw new OrderMismatchException("divide()");
        }
        
        return this.multiply(other.inverse());
    }
    
    @Override
    public Galois inverse() throws PrimeMismatchException {
        return new Galois(diofanticEq(this.m_value), this.m_order);
    }
    
    @Override
    public boolean equals(GaloisInterface other) throws OrderMismatchException{
        if (!checkOrder(other)) {
            throw new OrderMismatchException("equals()");
        }
        
        return this.m_value == other.value();
    }
    
    @Override
    public boolean notEquals(GaloisInterface other) throws OrderMismatchException{
        if (!checkOrder(other)) {
            throw new OrderMismatchException("notEquals()");
        }
        
        return !(this.equals(other));
    }
    
    @Override
    public boolean lessThan(GaloisInterface other) throws OrderMismatchException {
        if (!checkOrder(other)) {
            throw new OrderMismatchException("lessEquals()");
        }
        
        return this.m_value < other.value();
    }
    
    @Override
    public boolean lessThanOrEqual(GaloisInterface other) throws OrderMismatchException {
        if (!checkOrder(other)) {
            throw new OrderMismatchException("lessThatOrEqual()");
        }
        
        return !greaterThan(other);
    }
    
    @Override
    public boolean greaterThan(GaloisInterface other) throws OrderMismatchException {
        if (!checkOrder(other)) {
            throw new OrderMismatchException("greaterThan()");
        }
        
        return this.m_value > other.value();
    }
    
    @Override
    public boolean greaterThanOrEqual(GaloisInterface other) throws OrderMismatchException {
        if (!checkOrder(other)) {
            throw new OrderMismatchException("greaterThanOrEqual()");
        }
        
        return !lessThan(other);
    }
    
    @Override
    public String toString() {
        return "Galois [ value: " + m_value +
        ", order: " + m_order +
        "]";
    }
    
    @Override
    public long value() {
        return m_value;
    }
    
    @Override
    public long order() {
        return m_order;
    }
    
    private boolean isPrime(long n) {
        if (n < 2) {
            return false;
        }
        long a = 2;
        while (a <= Math.sqrt(n)) {
            if (n % a == 0) {
                return false;
            }
            ++a;
        }
        return true;
    }
    
    private boolean checkOrder(GaloisInterface other) {
        if (this.m_order != other.order()) {
            return false;
        }
        return true;
    }
    
    private long diofanticEq(long a) {
        long b = this.m_order;
        long solution = 0;
        long u = 1;
        
        while (a != 0) {
            long q = b / a;
            long r = b % a;
            
            long m = solution - u * q;
            
            b = a;
            a = r;
            solution = u;
            u = m;
        }
        
        return solution;
    }

    private long m_value;
    private long m_order;
}
