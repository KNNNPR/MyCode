package ru.mirea.labs.lab20.Matrix;

public class MainMatrix {
    public static void main(String[] args) {
        Matrix<Integer> test = new Matrix<>(2, 2);
        test.setCell(2, 0, 0);
        test.setCell(3, 0, 1);
        test.setCell(1, 1, 0);
        test.setCell(5, 1, 1);
        test.showMatrix();

        Matrix<Integer> other = new Matrix<>(2, 2);
        other.setCell(2, 0, 0);
        other.setCell(3, 0, 1);
        other.setCell(1, 1, 0);
        other.setCell(5, 1, 1);

        Matrix<Integer> res = test.operate(other, Integer::sum);
        res.showMatrix();
    }
}
