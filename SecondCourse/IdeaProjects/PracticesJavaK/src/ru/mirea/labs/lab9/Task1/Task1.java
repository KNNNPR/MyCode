package ru.mirea.labs.lab9.Task1;

public class Task1 {
    public static void myQuickSort(Student[] array) {
        int j;
        for (int i = 1; i < array.length - 1; i++) {
            Student swap = array[i];
            for(j = i; j > 0 && swap.compareTo(array[j - 1]) > 0; j-- ) {
                array[j] = array[j - 1];
            }
            array[j] = swap;
        }
    }
    public static void main(String[] args) {
        Student[] array = {new Student("APTYP", 22, 19), new Student("KIRILL", 24, 19), new Student("VALERA", 17, 19)};
        myQuickSort(array);
        for(int i = 0; i < array.length; i++) {
            System.out.println(array[i].toString());
        }
    }
}