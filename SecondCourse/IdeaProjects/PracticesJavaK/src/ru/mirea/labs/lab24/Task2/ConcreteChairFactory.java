package ru.mirea.labs.lab24.Task2;

// Конкретная реализация абстрактной фабрики
class ConcreteChairFactory extends ChairFactory {
    @Override
    public Chair createVictorianChair(int age) {
        return new VictorianChair(age);
    }

    @Override
    public Chair createMultiFunctionalChair() {
        return new MultiFunctionalChair();
    }

    @Override
    public Chair createMagicChair() {
        return new MagicChair();
    }
}