package ru.mirea.labs.lab21;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Task {
    public static List<String> convertStringArrayToList(String[] array) {
        List<String> list = new ArrayList<>();
        list.addAll(Arrays.asList(array));
        return list;
    }

    public static void main(String[] args) {
        String[] stringArray = {"Apple", "Banana", "Cherry", "Date"};

        List<String> stringList = convertStringArrayToList(stringArray);

        System.out.println("Array converted to list:");
        for (String item : stringList) {
            System.out.println(item);
        }
    }
}
