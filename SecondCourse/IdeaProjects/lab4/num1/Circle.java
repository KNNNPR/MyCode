package ru.mirea.lab4.num1;

public class Circle extends Shape {
    private double r;

    public Circle() {
        super();
        this.r = 2.0;
    }
    public Circle(double r) {
        super();
        this.r = r;
    }

    public Circle(double r, String color, boolean filled) {
        super(color, filled);
        this.r = r;
    }

    public double getR() {
        return r;
    }

    public void setR(double r) {
        this.r = r;
    }
    @Override
    public String getType() {
        return "окружность";
    }

    @Override
    public double getArea() {
        return Math.PI * r * r;
    }

    @Override
    public double getPerimeter() {
        return 2 * Math.PI * r;
    }

    public String toString() {
        return "Это " + getType() + ", периметр = " + getPerimeter() + ", площадь = " + getArea() + ", цвет = " + getColor() + ", полный = " + filled + ", радиус = " + getR() + ". ";
    }
}
