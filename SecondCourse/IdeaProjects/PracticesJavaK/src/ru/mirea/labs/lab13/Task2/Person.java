package ru.mirea.labs.lab13.Task2;

public class Person {
    private String firstName;
    private String secondName;
    private String lastName;


    public Person(String firstName, String secondName, String lastName) {
        this.firstName = firstName;
        this.secondName = secondName;
        this.lastName = lastName;
    }

    public String getFIO() {
        if(firstName.isEmpty() && lastName.isEmpty()) {
            return(secondName);
        }
        else {
            return (secondName + ' ' + firstName.charAt(0) + '.' + lastName.charAt(0) + '.');
        }
    }


    public static void main(String[] args) {
        Person ya = new Person("", "Kozlov", "");
        System.out.print(ya.getFIO());
    }
}
