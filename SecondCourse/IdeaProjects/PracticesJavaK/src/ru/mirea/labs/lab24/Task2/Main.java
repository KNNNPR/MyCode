package ru.mirea.labs.lab24.Task2;

public class Main {
    public static void main(String[] args) {
        ChairFactory factory = new ConcreteChairFactory();
        Chair victorianChair = factory.createVictorianChair(50);
        Chair multiFunctionalChair = factory.createMultiFunctionalChair();
        Chair magicChair = factory.createMagicChair();

        Client client = new Client();
        client.sit(victorianChair);
        client.sit(multiFunctionalChair);
        client.sit(magicChair);

        if (multiFunctionalChair instanceof MultiFunctionalChair) {
            int result = ((MultiFunctionalChair) multiFunctionalChair).sum(3, 5);
            System.out.println("Result of sum: " + result);
        }

        if (magicChair instanceof MagicChair) {
            ((MagicChair) magicChair).doMagic();
        }
    }
}