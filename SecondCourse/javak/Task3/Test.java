package ru.mirea.lab3.Task3;

import java.util.Scanner;

public class Test {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        double userVal = in.nextDouble();
        Convertor valueExchange = new Convertor(userVal);
        System.out.println(valueExchange.toDollars());
        System.out.println(valueExchange.toEuros());
    }
}
