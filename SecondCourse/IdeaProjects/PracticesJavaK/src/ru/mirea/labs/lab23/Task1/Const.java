package ru.mirea.labs.lab23.Task1;

public class Const extends Expression {
    private double value;

    public Const(double value) {
        this.value = value;
    }

    public double evaluate(double x) {
        return value;
    }
}
