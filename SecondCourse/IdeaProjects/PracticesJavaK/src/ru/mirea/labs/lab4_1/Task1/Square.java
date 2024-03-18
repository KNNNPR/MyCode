package ru.mirea.labs.lab4_1.Task1;

public class Square extends Shape {
    private double side;

    @Override
    public double getPerimeter() {
        return(4*side);
    }

    @Override
    public double getArea() {
        return(side*side);
    }

    @Override
    public String getType() {
        return super.getType();
    }

    @Override
    public String toString() {
        return("Square side = " + this.side);
    }
    public Square(double side) {
        this.type = "Square";
        this.side = side;
    }
}
