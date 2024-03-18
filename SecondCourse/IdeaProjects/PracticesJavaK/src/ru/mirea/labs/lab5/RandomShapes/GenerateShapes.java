package ru.mirea.labs.lab5.RandomShapes;

import javax.swing.*;
import java.awt.*;
import java.util.Random;

public class GenerateShapes extends JPanel {
    private final Shape[] shapes;

    public GenerateShapes() {
        shapes = new Shape[20];
        Random rand = new Random();

        for (int i = 0; i < 20; i++) {
            int x = rand.nextInt(800);
            int y = rand.nextInt(600);
            int shapeType = rand.nextInt(3);

            if (shapeType == 0) {
                int r = rand.nextInt(50) + 20;
                shapes[i] = new Circle(x, y, r);
            } else if (shapeType == 1) {
                int width = rand.nextInt(100) + 50;
                int height = rand.nextInt(100) + 50;
                shapes[i] = new Rectangle(x, y, width, height);
            } else {
                int sideLength = rand.nextInt(80) + 20;
                shapes[i] = new Rectangle(x, y, sideLength, sideLength);
            }
        }
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);

        for (Shape shape : shapes) {
            shape.drawShape(g);
        }
    }

    public static void main(String[] args) {
        JFrame frame = new JFrame("Random Shapes");
        GenerateShapes figs = new GenerateShapes();
        frame.add(figs);
        frame.setSize(800, 600);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}
