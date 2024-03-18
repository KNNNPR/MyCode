package ru.mirea.lab2.CircleK;

import ru.mirea.lab2.CircleK.Circle;
import ru.mirea.lab2.CircleK.Point;

import java.util.Scanner;

public class Tester  {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int length = in.nextInt();
        double newRad;
        double newX;
        double newY;
        Circle[] massCircle = new Circle [length];
        for(int i = 0; i < length; i++){
            newRad = in.nextDouble();
            newX = in.nextDouble();
            newY = in.nextDouble();
            Point newCenter = new Point(newX, newY);
            massCircle[i] = new Circle(newRad, newCenter);
        }
        for(int i = 0; i < length; i++){
            System.out.println(massCircle[i].toString());
        }
    }
}
