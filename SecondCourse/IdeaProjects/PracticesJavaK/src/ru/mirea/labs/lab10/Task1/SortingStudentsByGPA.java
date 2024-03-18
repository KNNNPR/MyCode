package ru.mirea.labs.lab10.Task1;

import java.util.Scanner;

public class SortingStudentsByGPA {
    private Student[] IDNumber;

    public SortingStudentsByGPA() {
        IDNumber = new Student[3];
    }
    public void setArray() {
        Scanner scan = new Scanner(System.in);
        for(int i = 0; i < IDNumber.length; i++) {
            IDNumber[i] = new Student(scan.next(), scan.next(), scan.next(), scan.nextInt(), scan.nextInt(),scan.nextInt());
        }
    }
    public void quickSort() {
        int min;
        Student temp;
        StudentComparator comp = new StudentComparator();
        for(int i = 0; i < IDNumber.length; i++) {
            min = i;
            for(int j = i + 1; j < IDNumber.length; j++) {
                if (comp.compare(IDNumber[min], IDNumber[j]) < 0) {
                    min = j;
                    temp = IDNumber[min];
                    IDNumber[min] = IDNumber[j];
                    IDNumber[i] = temp;
                }
            }
        }
        for(int i = 0; i < IDNumber.length; i++) {
            System.out.println(IDNumber[i].getAge());
        }
    }

    public static void main(String[] args) {
        SortingStudentsByGPA a = new SortingStudentsByGPA();
        a.setArray();
        a.quickSort();
    }
}
