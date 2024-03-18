package ru.mirea.lab3.Task3;

public class Convertor {
    private double r;

    public Convertor(double r) {
        this.r= r;
    }

    public double toEuros() {
        return (this.r * 89.4);
    }

    public double toDollars() {
        return(this.r * 75.7);
    }
}
