package ru.mirea.lab2.CircleRadiusK;

public class Circle {
    private double radius;

    public double getRadius() {
        return radius;
    }

    public void setRadius(double radius) {
        this.radius = radius;
    }

    public Circle(double radius) {
        this.radius = radius;
    }
    public double findLength() {
        return(2*Math.PI *radius);
    }
    public double findSquare() {
        return (Math.PI * Math.sqrt(radius));
    }
    public boolean compareCircles(Circle other) {
        if (this.findSquare() > other.findSquare()) return (true);
        return(false);
    }
}
