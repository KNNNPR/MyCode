package ru.mirea.labs.lab18;

public class Task1 {
    public static void main(String[] args) {
        try {
            System.err.println(2/0);
        }
        catch (ArithmeticException e) {
            System.out.println("divided by zero");
        }
    }
}
