package ru.mirea.labs.lab4.Task2;

public class Tie extends Clothes implements MenClothing{
    public Tie(String userColour, int userSize) {
        super(userColour, userSize);
    }

    @Override
    public void dressMan() {
        System.out.println("Tie: colour = " + this.colour + " price = " + this.price + " Size = " + this.size);
    }
}
