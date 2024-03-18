package ru.mirea.lab2.BookShellK;

public class Book {
    private String Tittle;
    private String Author;
    private int year;

    public String getTittle() {
        return Tittle;
    }

    public void setTittle(String tittle) {
        Tittle = tittle;
    }

    public String getAuthor() {
        return Author;
    }

    public void setAuthor(String author) {
        Author = author;
    }

    public int getYear() {
        return year;
    }

    public void setYear(int year) {
        this.year = year;
    }

    public Book(String tittle, String author, int year) {
        this.Tittle = tittle;
        this.Author = author;
        this.year = year;
    }

    @Override
    public String toString() {
        return "Book{" +
                "Tittle='" + Tittle + '\'' +
                ", Author='" + Author + '\'' +
                ", year=" + year +
                '}';
    }
}
