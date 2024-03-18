package ru.mirea.labs.lab8.Task4;

public class LeftRightNum {
    public static void recurseNum(int n, int del) {
        if(del == 0) return;
        if(n / del > 10) recurseNum(n, del*=10);
        else {
            System.out.print(n / del + "  ");
            recurseNum(n % del, del /= 10);
        }
    }

    public static void main(String[] args) {
        recurseNum(99887766, 1);
    }
}
