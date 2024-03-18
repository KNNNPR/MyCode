package ru.mirea.labs.lab20.TaskMinMax;

public class MinMax<E extends Comparable<E>>{
    private E[] list;

    public MinMax(E[] userList) {
        this.list = userList;
    }

    public E min() {
        E min = list[0];
        for (E e : list) {
            if(e.compareTo(min) == 1) {
                min = e;
            }
        }
        return(min);
    }
    public E max() {
        E max = list[0];
        for (E e : list) {
            if(e.compareTo(max) == -1) {
                max = e;
            }
        }
        return(max);
    }
}

