package ru.mirea.lab4.num1;

public class Rectangle extends Shape {
    private double width;
    private double height;

    public Rectangle() {
        super();
        this.width = 5.0;
        this.height = 3.0;
    }

    public Rectangle(double width, double height) {
        super();
        this.width = width;
        this.height = height;
    }

    public Rectangle(double width, double height, String color, boolean filled) {
        super(color, filled);
        this.width = width;
        this.height = height;
    }

    public double getWidth() {
        return width;
    }

    public void setWidth(double width) {
        this.width = width;
    }

    public double getHeight() {
        return height;
    }

    public void setHeight(double height) {
        this.height = height;
    }

    @Override
    public String getType() {
        return "прямоугольник";
    }

    @Override
    public double getArea() {
        return width * height;
    }
    @Override
    public double getPerimeter() {
        return (width + height) * 2;
    }

    public String toString() {
        return "Это " + getType() + ", периметр = " + getPerimeter() + ", площадь = " + getArea() + ", цвет = " + getColor() + ", полный = " + filled + ", длина = " + getHeight() + ", ширина = " + getWidth() + ". ";
    }
}
