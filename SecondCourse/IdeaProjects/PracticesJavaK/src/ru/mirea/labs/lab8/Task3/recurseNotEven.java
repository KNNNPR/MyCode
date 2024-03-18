package ru.mirea.labs.lab8.Task3;
public class recurseNotEven {
    public static void recurseSum(int a) {
        if(a % 10 == 0) return;
        System.out.print(a % 10 + "  ");
        recurseSum(a / 10);
    }
    public static void main(String[] args) {
        recurseSum(37868485);
    }
}
