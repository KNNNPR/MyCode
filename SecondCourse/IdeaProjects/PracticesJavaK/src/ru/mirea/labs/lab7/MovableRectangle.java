package ru.mirea.labs.lab7;

public class MovableRectangle implements Movable{
    private int x1, y1, x2, y2;

    public MovableRectangle(int x1, int y1, int x2, int y2) {
        this.x1 = x1;
        this.y1 = y1;
        this.x2 = x2;
        this.y2 = y2;
    }

    @Override
    public void moveUp() {
        y1++;
        y2++;
    }

    @Override
    public void moveDown() {
        y1--;
        y2--;
    }

    @Override
    public void moveRigth() {
        x1++;
        x2++;
    }

    @Override
    public void moveLeft() {
        x1--;
        x2--;
    }

    @Override
    public String toString() {
        return "MovableRectangle[(" + x1 + ", " + y1 + "), (" + x2 + ", " + y2 + ")]";
    }
}
