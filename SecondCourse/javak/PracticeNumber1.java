package ru.mirea.lab1;
public class PracticeNumber1 {
    public static void main(String[] args){
        double midArif;// переменная для среднего арифметического значения
        double Summ = 0.0;// переменная для храения суммы элементов массива
        int [] a = {1, 56, 89, 90, 1};
        for (int j : a) {
            Summ += j;
        }
        midArif = Summ /a.length;
        System.out.println("Summ is: " + Summ + " Mid is: " + midArif);
    }
}
