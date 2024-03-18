package ru.mirea.labs.lab23.Task1;

import ru.mirea.labs.lab23.Task1.Expression;

public class Substract extends Expression {
    private Expression left;
    private Expression right;

    public Substract(Expression left, Expression right) {
        this.left = left;
        this.right = right;
    }

    @Override
    public double evaluate(double x) {
        return left.evaluate(x) - right.evaluate(x);
    }
}

