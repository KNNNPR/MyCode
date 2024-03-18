package ru.mirea.lab2.DogK;

import java.util.Scanner;

public class DogTester {
    public static void main(String[] args) {
        DogsHouse homeOne = new DogsHouse();
        int D;
        Scanner inTwo = new Scanner(System.in);
        System.out.println("Enter Amount og dogs");
        D = inTwo.nextInt();
        homeOne.addManyDogs(D);
        homeOne.showDogs();
    }
}
