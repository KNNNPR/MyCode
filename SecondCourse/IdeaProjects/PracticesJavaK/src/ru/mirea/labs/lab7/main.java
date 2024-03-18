package ru.mirea.labs.lab7;

public class main {
    public static void main(String[] args) {
        MovableRectangle userRect = new MovableRectangle(0, 0, 3, 3);
        System.out.println(userRect.toString());
        userRect.moveRigth();
        userRect.moveUp();
        System.out.println(userRect.toString());
    }
}
