package ru.mirea.lab4.num3;

public class Person {
    private String fullName;
    private int age;

    public Person() {
        this.fullName = "Дмитрий";
        this.age = 27;
    }

    public Person(String fullName, int Age) {
        this.fullName = fullName;
        this.age = age;
    }

    public String move() {
        return fullName + " идёт";
    }

    public String talk() {
        return fullName + " говорит";
    }


}
