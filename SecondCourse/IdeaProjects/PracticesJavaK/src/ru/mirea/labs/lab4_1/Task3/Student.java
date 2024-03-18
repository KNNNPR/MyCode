package ru.mirea.labs.lab4_1.Task3;

public class Student extends Learner {
    private int courseNum;

    public Student(int a, String name) {
        this.courseNum = a;
        this.name = name;
    }

    public int getCourseNum() {
        return (courseNum);
    }
    public String getName() {
        return(name);
    }
}
