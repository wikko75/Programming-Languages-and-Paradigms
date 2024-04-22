package lab2.Java;


public class Main {
    public static void main(String[] args) {        
        try {

            Galois.printInfo();

            final long order = 1234577;

            Galois a = new Galois(15, order);

            Galois b = new Galois(1234576, order);

            System.out.println(
                String.format("\nInitial values:\n" +
                              "a = %s\nb = %s\n", a.value(), b.value()));
                                             
            System.out.println("a + b = " + a.add(b).value());
            System.out.println("1234578 + b = " + new Galois(1234578, order).add(b).value());
            System.out.println("a + 4 = " + a.add(Galois.valueOf(4, order)).value());

            System.out.println("a - b = " + a.subtract(b).value());
            
            System.out.println("a * b = " + a.multiply(b).value());
            
            System.out.println("a = " + a.value());
            System.out.println("~a = " + a.inverse().value());
            System.out.println("Check: a * ~a = " + a.multiply(a.inverse()).value());
            
            System.out.println("a / b = " + a.divide(b).value());
            System.out.println("Check: a / b * b = " + a.divide(b).multiply(b).value());

            System.out.println("\nIs a equal to b? " + a.equals(b));
            System.out.println("Is a not equal to b? " + !a.equals(b));
            System.out.println("Is a less than b? " + a.lessThan(b));
            System.out.println("Is a less than or equal to b? " + a.lessThanOrEqual(b));
            System.out.println("Is a greater than b? " + a.greaterThan(b));
            System.out.println("Is a greater than or equal to b? " + a.greaterThanOrEqual(b));
            
            System.out.println(
                String.format("\nEnd values:\n" +
                              "a = %s\nb = %s\n", a.value(), b.value()));

        } catch (Exception e) {
            e.printStackTrace();
        }      
    }
}