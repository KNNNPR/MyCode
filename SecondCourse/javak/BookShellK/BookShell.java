package ru.mirea.lab2.BookShellK;

public class BookShell {
    private Book booksInShell[];
    public BookShell(int amount) {
        booksInShell = new Book[amount];
    }
    public void addBook(Book newBook) {
        for (int i = 0; i < booksInShell.length; i++) {
            if(booksInShell[i] == null) {
                booksInShell[i] = newBook;
                break;
            }
        }
    }
    public void sortBooksInShell() {
        int min;
        int next;
        int curr;
        Book temp;
        for(int i = 0; i < booksInShell.length - 1; i++) {
            min = i;
            for(int j = i + 1; j < booksInShell.length; j++) {
                next = booksInShell[j].getYear();
                curr = booksInShell[min].getYear();
                if (next < curr) {
                    temp = booksInShell[min];
                    booksInShell[min] = booksInShell[j];
                    booksInShell[j] = temp;
                }
            }
        }
    }

    public void showShell() {
        for(int i = 0; i < booksInShell.length; i++) {
            System.out.println(booksInShell[i].toString());
        }
    }
}
