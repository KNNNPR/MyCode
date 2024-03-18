package ru.mirea.labs.lab23.Task1;

public class Main {
    public static void main(String[] args) {
        String [] resolution = new String [] {"x+2", "garsh"};
        if (args.length != 1) {
            System.out.println("Usage: Main <x>");
            return;
        }

        double x = Double.parseDouble(args[0]);
        Expression expression = new Substract(
                new Substract(
                        new Multiply(new Variable("x"), new Variable("x")),
                        new Multiply(new Const(2), new Variable("x"))
                ),
                new Const(1)
        );

        double result = expression.evaluate(x);
        System.out.println("Result: " + result);
    }
}

