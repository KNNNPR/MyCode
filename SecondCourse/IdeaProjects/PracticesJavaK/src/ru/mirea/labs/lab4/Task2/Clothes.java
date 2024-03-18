package ru.mirea.labs.lab4.Task2;

public abstract class Clothes {
    enumSize size;
    int price;
    String colour;

    public enumSize getSize() {
        return size;
    }

    public void setSize(enumSize size) {
        this.size = size;
    }

    public int getPrice() {
        return price;
    }

    public void setPrice(int price) {
        this.price = price;
    }

    public String getColour() {
        return colour;
    }

    public void setColour(String colour) {
        this.colour = colour;
    }

    public Clothes(String userColour, int userSize) {
        this.colour = userColour;
        this.price = 1500;
        switch (userSize) {
            case 40 -> {
                this.size = enumSize.L;
            }
            case 38 -> {
                this.size = enumSize.M;
            }
            case 36 -> {
                this.size = enumSize.S;
            }
            case 34 -> {
                this.size = enumSize.XS;
            }
            default -> {
                this.size = enumSize.XXS;
            }
        }
    }
}
