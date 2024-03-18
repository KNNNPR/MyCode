package ru.mirea.labs.lab23.Linked;

public class Main {
    public static void main(String[] args) {
        LinkedQueue test = new LinkedQueue();
        test.addElement(23);
        test.addElement(35);
        test.showQueueList();
        test.deleteElement();
        test.showQueueList();
    }
}
