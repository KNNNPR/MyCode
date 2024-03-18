package ru.mirea.lab1;

import java.util.Scanner;

public class PracticeNumber2 {
    public static void main(String[] args) {
        {
            Scanner in = new Scanner(System.in);// создание экземпляра класса сканер для считывания польз.ввода
            int length = in.nextInt();//считывание значения длинны масива
            int [] Array = new int[length];
            for(int i = 0; i < length; i++){
                Array[i] = in.nextInt();//заполнение массива
            }
            ////////////////////////////////////
            int Summ = 0;
            int j = 0;
            do {// первый цикл для счета суммы
                Summ += Array[j];
                j+=1;
            }while(j < length);
            System.out.println("First Summ = " + Summ);
            Summ = j = 0;
            while(j < length){// второй цикл для счета суммы
                Summ+=Array[j];
                j+=1;
            }
            System.out.println("Second Summ = " + Summ);
            int Max = Array[0];
            int Min = Array[0];
            for (int i = 0; i < length; i++){// поиск максимума
                if (Array[i] > Max) Max = Array[i];
            }
            System.out.println("Max element = " + Max);
            for (int i = 0; i < length; i++){// поиск минимума
                if (Array[i] < Min) Min = Array[i];
            }
            System.out.println("Min element = " + Min);
        }
        }
    }
