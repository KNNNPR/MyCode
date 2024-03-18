package ru.mirea.labs.lab12.TaskShape;

import java.awt.*;

public class Rectangle extends Shape{
    private int width, height;

    public Rectangle(int x, int y, int width, int height) {
        super(x, y);
        this.width = width;
        this.height = height;
    }

    @Override
    public void drawShape(Graphics g) {
        g.setColor(shapeColor);
        g.fillRect(x, y, width, height);
    }
}
