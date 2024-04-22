package lab3.Java.Exceptions;

public class GeneratorNotFoundException extends Exception {
    public GeneratorNotFoundException() {
        super("Can not found generator");
        printStackTrace();
    }
}
