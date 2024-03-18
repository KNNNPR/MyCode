package ru.mirea.labs.lab24.Task2;

// Викторианский стул
class VictorianChair implements Chair {
    private int age;

    public VictorianChair(int age) {
        this.age = age;
    }

    @Override
    public void sit() {
        System.out.println("Sitting on a Victorian chair.");
    }
}