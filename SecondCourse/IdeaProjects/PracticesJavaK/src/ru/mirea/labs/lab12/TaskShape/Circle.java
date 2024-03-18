package ru.mirea.labs.lab12.TaskShape;

import java.awt.*;
public class Circle extends Shape{
    private int radius;

    public Circle(int x, int y, int radius) {
        super(x, y);
        this.radius = radius;
    }

    @Override
    public void drawShape(Graphics g) {
        g.setColor(shapeColor);
        g.fillOval(x, y, 2*radius, 2*radius);
    }
}
