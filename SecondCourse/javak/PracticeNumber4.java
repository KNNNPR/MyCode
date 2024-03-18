package ru.mirea.lab1;

public class PracticeNumber4 {
    public static void main(String[] args){
        double Chislo = 0;
        for(int i = 0; i < 10; i++){
            Chislo = 1.0 / i;//
            System.out.printf("Number %d: %.2f%n",i, Chislo);//форматирование для нужной точности
        }
    }
}
