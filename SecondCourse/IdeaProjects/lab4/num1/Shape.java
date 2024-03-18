package ru.mirea.lab4.num1;

public abstract class Shape {

    protected String color;
    protected boolean filled;
    public String getType() {
        return "фигура";
    }

    public Shape() {
        this.color = "Жёлтый";
        this.filled = true;
    }

    public Shape(String color, boolean filled) {
        this.color = color;
        this.filled = filled;
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public boolean isFilled() {
        return filled;
    }

    public void setFilled(boolean filled) {
        this.filled = filled;
    }

    public abstract double getArea();
    public abstract double getPerimeter();

    @Override
    public String toString() {
        return "Это " + getType() + ", периметр = " + getPerimeter() + ", площадь = " + getArea() + ", цвет = " + getColor() + ", полный = " + filled + ". ";
    }
}
