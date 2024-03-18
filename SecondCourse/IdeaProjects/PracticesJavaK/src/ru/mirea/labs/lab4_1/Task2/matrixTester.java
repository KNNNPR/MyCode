package ru.mirea.labs.lab4_1.Task2;

import java.util.Scanner;

public class matrixTester {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        Matrix userMatrixOne = new Matrix(in.nextInt(), in.nextInt());
        userMatrixOne.setMatrixNums(in);
        Matrix userMatrixTwo = new Matrix(in.nextInt(), in.nextInt());
        userMatrixTwo.setMatrixNums(in);
        Matrix summOfOneTwo = userMatrixOne.summMatrix(userMatrixTwo);
        summOfOneTwo.showMatrix();
    }
}
