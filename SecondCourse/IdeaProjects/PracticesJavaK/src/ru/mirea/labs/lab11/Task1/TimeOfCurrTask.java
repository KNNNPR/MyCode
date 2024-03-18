package ru.mirea.labs.lab11.Task1;

import java.util.Date;
public class TimeOfCurrTask {
    public static void main(String[] args) {
        String developerName = System.getProperty("user.name");
        Date dateReceived = new Date();
        long sevenDaysInMillis = 7 * 24 * 60 * 60 * 1000;
        Date dateDue = new Date(System.currentTimeMillis() + sevenDaysInMillis*5);
        System.out.println("Разработчик: " + developerName);
        System.out.println("Дата получения задания: " + dateReceived);
        System.out.println("Дата сдачи задания: " + dateDue);
    }
}
