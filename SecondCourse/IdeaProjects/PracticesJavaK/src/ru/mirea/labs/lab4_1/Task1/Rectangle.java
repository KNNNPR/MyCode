package ru.mirea.labs.lab4_1.Task1;

public class Rectangle extends Shape {
    private double width;
    private double length;

    public Rectangle(double width, double length) {
        this.width = width;
        this.length = length;
        this.type = "Rectangle";
    }

    @Override
    public String getType() {
        return super.getType();
    }

    @Override
    public double getPerimeter() {
        return(2*width + 2*length);
    }

    @Override
    public double getArea() {
        return(width*length);
    }

    @Override
    public String toString() {
        return("Rectange: width = " + this.width + " length = " + this.length);
    }
}
