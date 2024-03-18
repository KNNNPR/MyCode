package ru.mirea.labs.lab23.Task1;

public class Divide extends Expression {
    private Expression left;
    private Expression right;

    public Divide(Expression left, Expression right) {
        this.left = left;
        this.right = right;
    }

    @Override
    public double evaluate(double x) {
        double denominator = right.evaluate(x);
        if (denominator == 0) {
            throw new ArithmeticException("Division by zero");
        }
        return left.evaluate(x) / denominator;
    }
}
