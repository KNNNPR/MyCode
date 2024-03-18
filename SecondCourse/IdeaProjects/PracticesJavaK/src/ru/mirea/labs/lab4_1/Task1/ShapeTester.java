package ru.mirea.labs.lab4_1.Task1;

import java.util.Scanner;

public class ShapeTester {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        Circle userCircle = new Circle(in.nextDouble());
        System.out.println(userCircle.getType());
        System.out.println(userCircle.getArea());
        System.out.println(userCircle.getPerimeter());
        Rectangle userRectangle = new Rectangle(in.nextDouble(), in.nextDouble());
        System.out.println(userRectangle.getType());
        System.out.println(userRectangle.getArea());
        System.out.println(userRectangle.getPerimeter());
        Square userSquare = new Square(in.nextDouble());
        System.out.println(userSquare.getType());
        System.out.println(userSquare.getArea());
        System.out.println(userSquare.getPerimeter());
    }
}
