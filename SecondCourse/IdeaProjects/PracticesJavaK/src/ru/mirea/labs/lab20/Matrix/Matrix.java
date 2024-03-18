package ru.mirea.labs.lab20.Matrix;

import java.util.function.BinaryOperator;

public class Matrix <E>{
    private int rows;
    private int colums;
    private E[][] matrixInside;

    public Matrix(int newRows, int newColums) {
        this.rows = newRows;
        this.colums = newColums;
        this.matrixInside = (E[][]) new Object[rows][colums];
    }
    public void setCell(E e, int userRows, int userColums) {
        this.matrixInside[userRows][userColums] = e;
    }
    public E getCell(int userRows, int userColums) {
        return(this.matrixInside[userRows][userColums]);
    }
    public Matrix<E> operate(Matrix<E> otherMatrix, BinaryOperator<E> operator) {
        if(otherMatrix.rows != this.rows || otherMatrix.colums != this.colums) {
            System.out.println("Error by size");
            return(null);
        }
        Matrix<E> result = new Matrix<E>(this.rows, this.colums);
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < colums; j++) {
                result.setCell(operator.apply(this.getCell(i, j), otherMatrix.getCell(i, j)), i, j);
            }
        }
        return(result);
    }
    public void showMatrix() {
        for(int i = 0; i < this.rows; i++) {
            for(int j = 0; j < this.colums; j++) {
                System.out.print(getCell(i, j));
                System.out.print(' ');
            }
            System.out.print('\n');
        }
    }
}
