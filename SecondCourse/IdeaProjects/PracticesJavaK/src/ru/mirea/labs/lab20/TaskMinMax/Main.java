package ru.mirea.labs.lab20.TaskMinMax;

public class Main {
    public static void main(String[] args) {
        MinMax<Integer> test = new MinMax<>(new Integer[]{1, 2, 3, 4, 5, 6, 7, 8, 9 ,10});
        System.out.println(test.min());
        System.out.println(test.max());
    }
}
