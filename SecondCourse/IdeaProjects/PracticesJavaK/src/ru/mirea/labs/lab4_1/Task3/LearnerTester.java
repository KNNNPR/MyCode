package ru.mirea.labs.lab4_1.Task3;

public class LearnerTester {
    public static void main(String[] args) {
        Learner array [] = {new Student(2, "Oleg"), new Schooler(7, "Vadim")};
        for(Learner i: array) {
            if (i.getClass() == Student.class) {
                System.out.println(i.toString()  + " is Student");
            }
            else {
                System.out.println(i.toString());
            }
        }
    }
}
