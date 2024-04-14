package lab2.Java;

public class Galois {

    private static long s_order = 1234577;

    public static void printInfo() {
        System.out.println("=============\n" +
        "Galois\n" +
        "Properties:\n" +
        String.format("Default order: %s\n", s_order) +
        "=============");
    }


    public static Galois valueOf(long value) {
        return new Galois(value);
    }

    
    private long m_value;

    private long m_order = 1234577;
    

    public Galois() {}
    

    public Galois(long value, long order) throws Exception {
        if (!isPrime(order)) {
            throw new Exception("Field order must be a prime number");
        }
        m_order = order;
        m_value = value >= 0 ? value % m_order : (m_order + value);
    }


    public Galois(long value) {
        m_value = value >= 0 ? value % m_order : (m_order + value);
    }
    

    public Galois add(Galois other) throws OrderMismatchException {
        if (!checkOrder(other)) {
            throw new OrderMismatchException("add()");
        }
        return new Galois((this.m_value + other.m_value) % this.m_order);
    }
    

    public Galois subtract(Galois other) throws OrderMismatchException {
        if (!checkOrder(other)) {
            throw new OrderMismatchException("sub()");
        }

        long value = (this.m_value - other.m_value);
        
        if (value < 0) {
            value = (this.m_order + this.m_value);

            return new Galois(value);
        }
        
        value %= this.m_order;
        return new Galois(value);
    }
    
    
    public Galois multiply(Galois other) throws OrderMismatchException {
        if (!checkOrder(other)) {
            throw new OrderMismatchException("multiply()");
        }

        return new Galois((this.m_value * other.m_value) % this.m_order);
    }


    public Galois divide(Galois other) throws OrderMismatchException {
        if (!checkOrder(other)) {
            throw new OrderMismatchException("divide()");
        }
            
        return this.multiply(other.inverse());
    }


    public Galois inverse() {
        return new Galois(diofanticEq(this.m_value));
    }
    

    public boolean equals(Galois other) throws OrderMismatchException{
        if (!checkOrder(other)) {
            throw new OrderMismatchException("equals()");
        }
        
        return this.m_value == other.m_value;
    }
    
    
    public boolean notEquals(Galois other) throws OrderMismatchException{
        if (!checkOrder(other)) {
            throw new OrderMismatchException("notEquals()");
        }
        
        return !(this.equals(other));
    }
    
    
    public boolean lessThan(Galois other) throws OrderMismatchException {
        if (!checkOrder(other)) {
            throw new OrderMismatchException("lessEquals()");
        }
        
        return this.m_value < other.m_value;
    }
    
    
    public boolean lessThanOrEqual(Galois other) throws OrderMismatchException {
        if (!checkOrder(other)) {
            throw new OrderMismatchException("lessThatOrEqual()");
        }
        
        return !greaterThan(other);
    }
    
    
    public boolean greaterThan(Galois other) throws OrderMismatchException {
        if (!checkOrder(other)) {
            throw new OrderMismatchException("greaterThan()");
        }
        
        return this.m_value > other.m_value;
    }
    
    
    public boolean greaterThanOrEqual(Galois other) throws OrderMismatchException {
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
    

    public long value() {
        return m_value;
    }

    
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
        }
        return true;
    }

    
    private boolean checkOrder(Galois other) {
        if (this.m_order != other.m_order) {
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
}
