package ru.mirea.labs.lab4.Task2;

public class Skirt extends Clothes implements WomenClothing{
    public Skirt(String userColour, int userSize) {
        super(userColour, userSize);
    }

    @Override
    public void dressWoman() {
        System.out.println("Skirt: colour = " + this.colour + " price = " + this.price + " Size = " + this.size);
    }
}
