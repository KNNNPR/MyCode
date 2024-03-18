package ru.mirea.labs.lab11.Task1;

import java.awt.*;
import java.util.Calendar;
import java.util.Date;
import java.util.GregorianCalendar;
import java.util.Scanner;

public class TimeCompare {
    public static void main(String[] args) {
        Scanner userScan = new Scanner(System.in);
        Date currDate = new Date();
        Calendar newUserTime = new GregorianCalendar(userScan.nextInt(), userScan.nextInt(), userScan.nextInt());
        Date userDate = newUserTime.getTime();
        if(currDate.after(userDate)) {
            System.out.print("AFTER!!!");
            System.exit(0);
        }
        System.out.print("BEFORE!!!");
        System.exit(0);
    }
}
