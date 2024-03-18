package ru.mirea.lab2.BookShellK;

import java.util.Scanner;

public class BookShellTester {
    public static void main(String[] args) {
        BookShell liter;
        Scanner in = new Scanner(System.in);
        int amount = in.nextInt();
        String newAuthor;
        String newTitle;
        int newAge;
        liter = new BookShell(amount);
        for(int i = 0; i < amount; i++) {
            newAuthor = in.next();
            newTitle = in.next();
            newAge = in.nextInt();
            liter.addBook(new Book(newAuthor, newTitle, newAge));
        }
        liter.sortBooksInShell();
        liter.showShell();
    }
}
