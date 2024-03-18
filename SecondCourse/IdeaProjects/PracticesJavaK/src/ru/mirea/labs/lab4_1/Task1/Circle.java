package ru.mirea.labs.lab4_1.Task1;

public class Circle extends Shape {
    private double radius;
    public Circle(double radius) {
        this.radius = radius;
        this.type = "Circle";
    }

    public double getRadius() {
        return (radius);
    }

    @Override
    public double getArea() {
        return (3.14*radius*radius);
    }

    @Override
    public double getPerimeter() {
        return(2*3.14*radius);
    }

    @Override
    public String getType() {
        return super.getType();
    }

    @Override
    public String toString() {
        return("Circle: radius = " + this.radius);
    }
}
