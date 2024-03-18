package ru.mirea.lab1;

import java.math.BigInteger;
import java.sql.SQLOutput;
import java.util.Scanner;

public class PracticeNumber5 {
    public static int Fact(int a){
        if(a == 1) return(1);
        return(a*Fact(a-1));
    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);// создание экземпляра класса сканер
        int a = in.nextInt();
        System.out.println(Fact(a));
    }
}
