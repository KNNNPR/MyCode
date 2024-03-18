package ru.mirea.labs.lab23.Linked;

import java.util.LinkedList;

public class LinkedQueue {
    private LinkedList<Integer> queueList;
    private Integer tail;
    public LinkedQueue() {
        queueList = new LinkedList<Integer>();
    }
    public void addElement(Integer userInt) {
        queueList.add(userInt);
    }
    public void deleteElement() {
        queueList.pop();
    }
    public void showQueueList() {
        for(int i = 0; i < queueList.size(); i++) {
            System.out.print(queueList.get(i) + "   ");
        }
        System.out.println();
    }
}
