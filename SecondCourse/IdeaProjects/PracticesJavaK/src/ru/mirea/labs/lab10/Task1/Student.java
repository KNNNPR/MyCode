package ru.mirea.labs.lab10.Task1;

public class Student {
    private String name;
    private String lastName;
    private String profession;
    private int age;
    private int gropNum;
    private int midMark;

    public Student(String name, String lastName, String profession, int age, int gropNum, int midMark) {
        this.name = name;
        this.lastName = lastName;
        this.profession = profession;
        this.age = age;
        this.gropNum = gropNum;
        this.midMark = midMark;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getLastName() {
        return lastName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public String getProfession() {
        return profession;
    }

    public void setProfession(String profession) {
        this.profession = profession;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public int getGropNum() {
        return gropNum;
    }
    public void setGropNum(int gropNum) {
        this.gropNum = gropNum;
    }
    public int getMidMark() {
        return midMark;
    }

    public void setMidMark(int midMark) {
        this.midMark = midMark;
    }
}
