package ru.mirea.labs.lab23.Task1;

import ru.mirea.labs.lab23.Task1.Expression;

public class Variable extends Expression {
    private String name;

    public Variable(String name) {
        this.name = name;
    }

    @Override
    public double evaluate(double x) {
        return x;
    }
}
