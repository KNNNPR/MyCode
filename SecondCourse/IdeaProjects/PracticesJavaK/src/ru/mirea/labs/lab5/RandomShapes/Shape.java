package ru.mirea.labs.lab5.RandomShapes;

import javax.swing.*;
import java.awt.*;
import java.util.Random;

public abstract class Shape {
    protected Color shapeColor;
    protected int x;
    protected int y;

    public Shape(int x, int y) {
        this.x = x;
        this.y = y;
        this.shapeColor = getRandomShapeColor();
    }

    public abstract void drawShape(Graphics g);

    private Color getRandomShapeColor() {
        Random rand = new Random();
        int R = rand.nextInt(255);
        int G = rand.nextInt(255);
        int B = rand.nextInt(255);
        return (new Color(R, G, B));
    }
}
