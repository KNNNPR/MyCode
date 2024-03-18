package ru.mirea.labs.lab6.Task2;

public class Dog implements Nameable{
    private String name;

    public Dog(String name) {
        this.name = name;
    }
    @Override
    public String getName() {
        return ("DOg name: " + name);
    }
}
