package ru.mirea.lab3.Task1;

import java.util.Random;
import java.util.Scanner;

public class RandomArrayK {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        Random generator = new Random();
        int length = in.nextInt();
        double[] randomNums = new double [length];
        for(int i = 0; i < length; i++) {
            if(i % 2 == 0) {
                randomNums[i] = generator.nextInt();
            }
            randomNums[i] = Math.random();
        }
        for(int i = 0; i < length; i ++) {
            System.out.println(randomNums[i]);
        }
        int min;
        double next;
        double curr;
        double temp;
        for(int i = 0; i < length - 1; i++) {
            min = i;
            for(int j = i + 1; j < length; j++) {
                next = randomNums[j];
                curr = randomNums[min];
                if (next < curr) {
                    temp = randomNums[min];
                    randomNums[min] = randomNums[j];
                    randomNums[j] = temp;
                }
            }
        }
        System.out.println("Sorted array:");
        for(int i = 0; i < length; i ++) {
            System.out.println(randomNums[i]);
        }
    }
}
