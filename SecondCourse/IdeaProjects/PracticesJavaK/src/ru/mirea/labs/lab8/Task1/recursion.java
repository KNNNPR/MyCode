package ru.mirea.labs.lab8.Task1;

public class recursion {
    public static void recurseTriang(int n) {
        if(n == 0) return;
        for(int i = 0; i < n; i++) {
            System.out.println(n);
        }
        n--;
        recurseTriang(n);
    }

    public static void main(String[] args) {
        recurseTriang(10);
    }
}
