package ru.mirea.labs.lab8.Task2;

public class recurseSummOfNum {
    public static int recurseSum(int a, int res) {
        if(a / 10 == 0) return(res + a);
        res+= a % 10;
        return(recurseSum(a / 10, res));
    }

    public static void main(String[] args) {
        System.out.println(recurseSum(1103451, 0));
    }
}
