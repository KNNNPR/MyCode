package ru.mirea.labs.lab6.Task1;

public class MovableCircle implements Movable {
    private int radius;
    private MovablePoint center;

    public MovableCircle(int radius, int x, int y, int xSpeed, int ySpeed) {
        center = new MovablePoint(x, y, xSpeed, ySpeed);
        this.radius = radius;
    }

    @Override
    public void moveUp() {
        center.setY(center.getY() + center.getySpeed());
    }

    @Override
    public void moveDown() {
        center.setY(center.getY() - center.getySpeed());
    }

    @Override
    public void moveRigth() {
        center.setX(center.getX() + center.getxSpeed());
    }

    @Override
    public void moveLeft() {
        center.setX(center.getX() - center.getxSpeed());
    }

    @Override
    public String toString() {
        return ("Circle with center: " + center.getX() + "  " + center.getY());
    }
}
