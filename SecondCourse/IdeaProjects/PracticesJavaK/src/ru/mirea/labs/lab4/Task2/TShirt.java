package ru.mirea.labs.lab4.Task2;

public class TShirt extends Clothes implements MenClothing, WomenClothing{
    public TShirt(String userColour, int userSize) {
        super(userColour, userSize);
    }

    @Override
    public void dressMan() {
        System.out.println("Tshirt: colour = " + this.colour + " price = " + this.price + " Size = " + this.size);
    }

    @Override
    public void dressWoman() {
        System.out.println("Tshirt: colour = " + this.colour + " price = " + this.price + " Size = " + this.size);
    }

}
