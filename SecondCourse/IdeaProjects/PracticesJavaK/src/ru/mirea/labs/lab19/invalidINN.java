package ru.mirea.labs.lab19;

public class invalidINN extends Exception{
    public invalidINN(String errorMessage) {
        super(errorMessage);
    }
}
