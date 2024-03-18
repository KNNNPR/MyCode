package ru.mirea.lab2.reverseK;

import java.util.Scanner;

public class reverseArray {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int amount = in.nextInt();
        String [] str = new String [amount];
        for(int i = 0; i < str.length;i++) {
            str[i] = in.next();
        }
        for(int i = 0; i < str.length; i++) {
            System.out.print(str[i] + ' ');
        }
        System.out.println('\n');
        String temp;
        for(int i = 0; i < str.length / 2;i++) {
            temp = str[i];
            str[i] = str[str.length - 1 - i];
            str[str.length - 1 - i] = temp;
        }
        for(int i = 0; i < str.length; i++) {
            System.out.print(str[i] + ' ');
        }
    }
}
