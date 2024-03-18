package ru.mirea.labs.lab6.Task2;

public class Planet implements Nameable {
    private String name;

    public Planet(String name) {
        this.name = name;
    }

    @Override
    public String getName() {
        return("Planet name: " + name);
    }
}
