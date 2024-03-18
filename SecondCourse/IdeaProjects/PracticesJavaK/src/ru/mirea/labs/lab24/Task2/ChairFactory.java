package ru.mirea.labs.lab24.Task2;

// Абстрактная фабрика для стульев
abstract class ChairFactory {
    public abstract Chair createVictorianChair(int age);

    public abstract Chair createMultiFunctionalChair();

    public abstract Chair createMagicChair();
}