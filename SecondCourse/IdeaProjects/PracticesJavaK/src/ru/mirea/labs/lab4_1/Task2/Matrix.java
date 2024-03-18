package ru.mirea.labs.lab4_1.Task2;

import java.util.Scanner;

public class Matrix {
    private int rows;
    private int colums;
    private double[][] matrixNums;

    public Matrix(int rows, int colums) {
        this.colums = colums;
        this.rows = rows;
        this.matrixNums = new double[rows][colums];
    }

    public int getRows() {
        return rows;
    }

    public int getColums() {
        return colums;
    }

    public void setMatrixNums(Scanner in) {
        double num;
        for(int i = 0; i < this.rows; i++) {
            for(int j = 0; j < this.colums; j++) {
                num = in.nextDouble();
                this.matrixNums[i][j] = num;
            }
        }
    }
    public void showMatrix() {
        System.out.println("Matrix");
        for(int i = 0; i < this.getRows(); i++) {
            for(int j = 0; j< this.getColums(); j++) {
                if(j == this.getColums() - 1) {
                    System.out.print(matrixNums[i][j] + " |");
                }
                else if(j == 0) {
                    System.out.print("| " + matrixNums[i][j] + "  ");
                }
                else {
                    System.out.print(matrixNums[i][j] + "  ");
                }
            }
            System.out.print('\n');
        }
    }

    public void setMatrixNum(int a, int b, double c) {
        this.matrixNums[a][b] = c;
    }

    public double getMatrixNum(int a, int b) {
        return(this.matrixNums[a][b]);
    }
    public Matrix summMatrix(Matrix userMatrix) {
        Matrix result = new Matrix(this.rows, this.colums);
        double newNum;
        for(int i = 0; i < this.rows; i++) {
            for(int j = 0; j < this.colums; j++) {
                newNum = this.matrixNums[i][j] + userMatrix.getMatrixNum(i, j);
                result.setMatrixNum(i, j, newNum);
            }
        }
        return(result);
    }
}
