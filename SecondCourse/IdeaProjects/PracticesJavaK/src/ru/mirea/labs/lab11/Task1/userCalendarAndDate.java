package ru.mirea.labs.lab11.Task1;

import java.util.Calendar;
import java.util.Date;
import java.util.GregorianCalendar;
import java.util.Scanner;

public class userCalendarAndDate {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        Calendar userCalendar = new GregorianCalendar(in.nextInt(), in.nextInt(), in.nextInt(), in.nextInt(), in.nextInt(), in.nextInt());
        System.out.println(userCalendar.getTime());
        Date userDate = new Date();
        userDate = userCalendar.getTime();
        System.out.println(userCalendar.getTime());
    }
}
