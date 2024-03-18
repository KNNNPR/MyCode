package ru.mirea.lab3.Task2;

import java.util.Scanner;

public class ClassEnvelopeK {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        double num = in.nextDouble();
        Double newDub = Double.valueOf(num);
        System.out.println("Value inside of Double");
        System.out.println(newDub.doubleValue());
        System.out.println("String value to Double");
        System.out.println(Double.parseDouble("45.90"));
        String d = Double.toString(3.14);
        System.out.println("Double value to string");
        System.out.println(newDub.intValue());
        System.out.println(newDub.doubleValue());
        System.out.println(newDub.shortValue());
        System.out.println(newDub.floatValue());
        System.out.println(newDub.byteValue());
        System.out.println(newDub.longValue());
    }
}
