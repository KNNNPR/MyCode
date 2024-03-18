package ru.mirea.labs.lab24.Task2;

// Магический стул
class MagicChair implements Chair {
    public void doMagic() {
        System.out.println("Performing magic with the chair.");
    }

    @Override
    public void sit() {
        System.out.println("Sitting on a magic chair.");
    }
}
