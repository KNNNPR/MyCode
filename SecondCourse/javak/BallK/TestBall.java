package ru.mirea.lab2.BallK;

import ru.mirea.lab2.BallK.Ball;

import java.util.Scanner;

public class TestBall  {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        double startX = in.nextDouble();
        double startY = in.nextDouble();
        Ball testBall = new Ball(startX, startY);
        System.out.println(testBall.toString());
        testBall.move(7.90, 8.0);
        System.out.println(testBall.toString());
    }
}
