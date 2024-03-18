package ru.mirea.lab4.num1;

public class Square extends Rectangle {


    public Square() {
        super();
    }
    public Square(double side) {
        super(side,side);
    }
    public Square(double side, String color, boolean filled) {
        super(side,side,color,filled);
    }

    public double getSide() {
        return getWidth();
    }

    public void setSide(double side) {
        setWidth(side);
        setHeight(side);
    }
    @Override
    public String getType() {
        return "квадрат";
    }
    public String toString() {
        return "Это " + getType() + ", периметр = " + getPerimeter() + ", площадь = " + getArea() + ", цвет = " + getColor() + ", полный = " + filled + ", сторона = " + getSide() + ". ";
    }

}
