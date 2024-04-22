package lab3.Java;

import java.util.ArrayList;
import java.util.concurrent.ThreadLocalRandom;
import lab2.Java.GaloisInterface;
import lab2.Java.Exceptions.OrderMismatchException;
import lab2.Java.Exceptions.PrimeMismatchException;
import lab3.Java.Exceptions.GeneratorNotFoundException;


public class DHSetup<T extends GaloisInterface> {

    public DHSetup(T elem) throws OrderMismatchException, PrimeMismatchException, GeneratorNotFoundException {
        this.fieldElement = elem;
        this.m_order = elem.order();
        this.m_generator = chooseGenerator();

        if (this.m_generator == null) {
            throw new GeneratorNotFoundException();
        }

    }

    public T getGenerator()
    {
        return m_generator;
    }

    public T power(T a, long b) throws OrderMismatchException, PrimeMismatchException {
        T res = (T) a.createObject(1, a.order()); 
        while (b > 0) {
            if ((b & 1) == 1) {
                res = (T) res.multiply(a); 
            }
            b >>= 1; 
            a = (T) a.multiply(a);
        }
        return res;
    }


    public long getOrder() {
        return m_order;
    }


    private boolean isPrime(long n) {
        if (n < 2) {
            return false;
        }
        long a = 2;
        while (a * a < n) {
            if (n % a == 0) {
                return false;
            }
            ++a;
        }

        return true;
    } 

    private ArrayList<Long> getPrimeDivisors(long p) {
        ArrayList<Long> divisors = new ArrayList<>();
        for (long i = 2; i * i < p; ++i) {
            if (p % i == 0 && isPrime(i)) 
            {
                divisors.add(i);
                while (p % i == 0) 
                {
                    p /= i;
                }
            }
        }
        if (p > 1) 
        {
            divisors.add(p);
        }
    
        return divisors;
    }

    private T chooseGenerator() throws OrderMismatchException, PrimeMismatchException
    {
        ThreadLocalRandom rng = ThreadLocalRandom.current();
        T generator = null;
        // ensures we won't jump into an infinite loop
        long safetyCounter = 0;
        T valuesNotPermitted = (T) fieldElement.createObject(1, this.m_order);

        while (true) {
            // generator should be found up to 2*N tries
            if (safetyCounter > 2 * (this.m_order - 2))
            {
                break;
            }

            // get random element from field
            generator = (T) fieldElement.createObject(rng.nextLong(1, this.m_order), this.m_order);

            ArrayList<Long> divisors = getPrimeDivisors(this.m_order - 1);
            // System.out.println("Divisors " + divisors);
            
            // check if each divisor  satisfies predicate
            for (Long divisor : divisors) {
                if(power(generator, (this.m_order - 1) / divisor ) == valuesNotPermitted) {
                    safetyCounter++;
                    break;
                }
                return generator;
            }
        }
        return null;
    }

    private long m_order;
    private T m_generator;
    // just for having info about what class we're dealing with
    // idk how to do this differently yet
    private T fieldElement;
    
}