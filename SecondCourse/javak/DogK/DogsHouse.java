package ru.mirea.lab2.DogK;

import java.util.ArrayList;
import java.util.Scanner;

public class DogsHouse {
    private ArrayList<Dog> pitomnic;
    private Scanner in;
    private String newName;
    private int newAge;
    public DogsHouse() {
        pitomnic = new ArrayList<Dog>();
        in = new Scanner(System.in);
    }
    public void addDog() {
        newName = in.next();
        newAge = in.nextInt();
        pitomnic.add(new Dog(newName, newAge));
    }
    public void addManyDogs(int amount) {
        for(int i = 0; i < amount; i++) {addDog();}
    }
    public void showDogs() {
        for (int i = 0; i < pitomnic.size(); i++) {
            System.out.println(pitomnic.get(i).toString());
        }
    }
}
