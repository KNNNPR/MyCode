package ru.mirea.lab4.num3;

public class PersonTester {
    public static void main(String[] args) {
        Person person1 = new Person();
        Person person2 = new Person("Никита", 25);

        System.out.println(person1.move());
        System.out.println(person1.talk());

        System.out.println();

        System.out.println(person2.move());
        System.out.println(person2.talk());
    }
}
