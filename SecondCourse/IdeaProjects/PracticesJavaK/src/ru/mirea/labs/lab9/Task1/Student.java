package ru.mirea.labs.lab9.Task1;

public class Student implements Comparable<Student>{
    private String studentName;
    private int studentId;
    private int studentAge;

    public Student(String name, int id, int age) {
        this.studentId = id;
        this.studentAge = age;
        this.studentName = name;
    }
    public String toString(){return(studentName + "  " + studentId);}
    @Override
    public int compareTo(Student other) {
        return Integer.compare(this.studentId, other.studentId);
    }
}
