package ru.mirea.lab4.num1;

public class ShapeTester {
    public static void main(String[] args) {
        Shape shape1 = new Circle(5.0);
        Shape shape2 = new Rectangle(3.0,9.0);
        Shape shape3 = new Square(8.0);
        Shape shape4 = new Rectangle();
        Shape shape5 = new Circle(2.0, "Красный", true);
        Shape shape6 = new Square(6.0, "Зелёный", false);
        Shape shape7 = new Rectangle(2.5, 5.0, "Оранжевый", true);
        Shape shape8 = new Circle();

        System.out.println(shape1);
        System.out.println();

        System.out.println(shape2);
        System.out.println();

        System.out.println(shape3);
        System.out.println();

        System.out.println(shape4);
        System.out.println();

        System.out.println(shape5);
        System.out.println();

        System.out.println(shape6);
        System.out.println();

        System.out.println(shape7);
        System.out.println();

        System.out.println(shape8);
        System.out.println();
    }
}
