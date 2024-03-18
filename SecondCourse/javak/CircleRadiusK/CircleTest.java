package ru.mirea.lab2.CircleRadiusK;

import java.util.Scanner;

public class CircleTest {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        Circle one = new Circle(in.nextDouble());
        Circle two = new Circle(in.nextDouble());
        if(one.compareCircles(two)) {
            System.out.println("Area of First Circle is bigger than the Second");
        }
        else {
            System.out.println("Area of Second Circle is bigger than the First");
        }
        if(one.findLength()> two.findLength()) {
            System.out.println("Square of First Circle is bigger than the Second");
        }
        else {
            System.out.println("Square of Second Circle is bigger than the First");
        }
    }
}
