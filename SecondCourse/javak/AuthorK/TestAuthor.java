package ru.mirea.lab2.AuthorK;

import ru.mirea.lab2.AuthorK.Author;

import java.util.Scanner;

public class TestAuthor  {
    public static void main(String [] args){
        Scanner in = new Scanner(System.in);
        String newEmail = in.nextLine();
        Author testAuthor = new Author("Miha", "MihaYo@hmail.com", "Male");
        System.out.println(testAuthor.toString());
        testAuthor.setEmail(newEmail);
        System.out.println(testAuthor.toString());
    }
}
