package ru.mirea.labs.lab4_1.Task3;

public class Schooler extends Learner {
    private int classNum;

    public Schooler(int a, String name) {
        this.classNum = a;
        this.name = name;
    }

    public int getClassNum() {
        return (classNum);
    }

    public String getName() {
        return (name);
    }
}
