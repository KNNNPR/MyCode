package ru.mirea.labs.lab19;
import java.util.regex.Pattern;
import java.util.regex.Matcher;

public class Task1 {
    public static void main(String[] args) {
        String inn = "123456789";
        if (isValidInn(inn)) {
            System.out.println("ИНН действителен.");
        }
        else {
            System.out.println("ИНН недействителен.");
        }
    }
    public static boolean isValidInn(String inn) {
        String innPattern = "\\d{10}|\\d{12}";
        if (Pattern.matches(innPattern, inn)) {
            return true;
        }
        else {
            return false;
        }
    }
}
