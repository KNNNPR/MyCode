package ru.mirea.labs.lab11.Task1;

import java.util.Calendar;
import java.util.Date;
import java.util.GregorianCalendar;

public class newStudent  {
    private String studentName;
    private int studentAge;
    private Date studentDateOfBirth;

    public newStudent(String name, int age, int yearOfBirth, int monthOfBird, int dayOfBird) {
        this.studentAge = age;
        this.studentName = name;
        this.studentDateOfBirth =  new GregorianCalendar(yearOfBirth, monthOfBird, dayOfBird).getTime();
    }

    public String toString() {
        return ("Student name: " + studentName + '\n' +
                "Student Age: " + studentAge + '\n' +
                "Student date of birth: " + studentDateOfBirth);
    }

    public static void main(String[] args) {
        newStudent ya = new newStudent("Kirill", 19, 2004, 3, 22);
        System.out.print(ya.toString());
    }
}