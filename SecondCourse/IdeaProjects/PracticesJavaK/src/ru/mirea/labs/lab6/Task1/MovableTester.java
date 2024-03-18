package ru.mirea.labs.lab6.Task1;

import ru.mirea.labs.lab6.Task1.MovableCircle;

public class MovableTester {
    public static void main(String[] args) {
        MovableCircle userCircle = new MovableCircle(20, 0, 0, 5, 7);
        System.out.println(userCircle.toString());
        userCircle.moveLeft();
        userCircle.moveDown();
        System.out.println(userCircle.toString());
    }
}
