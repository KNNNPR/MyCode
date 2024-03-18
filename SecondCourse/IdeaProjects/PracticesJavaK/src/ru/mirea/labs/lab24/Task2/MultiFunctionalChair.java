package ru.mirea.labs.lab24.Task2;

// Многофункциональный стул
class MultiFunctionalChair implements Chair {
    public int sum(int a, int b) {
        return a + b;
    }

    @Override
    public void sit() {
        System.out.println("Sitting on a multi-functional chair.");
    }
}
