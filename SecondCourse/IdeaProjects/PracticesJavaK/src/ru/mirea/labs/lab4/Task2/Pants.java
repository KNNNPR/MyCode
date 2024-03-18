package ru.mirea.labs.lab4.Task2;

public class Pants extends Clothes implements MenClothing, WomenClothing {
    public Pants(String userColour, int userSize) {
        super(userColour, userSize);
    }

    @Override
    public void dressWoman() {
        System.out.println("Pants: colour = " + this.colour + " price = " + this.price + " Size = " + this.size);
    }

    @Override
    public void dressMan() {
        System.out.println("Pants: colour = " + this.colour + " price = " + this.price + " Size = " + this.size);
    }
}
