package ru.mirea.labs.lab4.Task2;

import java.util.Scanner;

public class Atelier {
        public static void main(String[] args) {
            Scanner in = new Scanner(System.in);
            Tie userTie = new Tie(in.next(), in.nextInt());
            Skirt userSkirt = new Skirt(in.next(), in.nextInt());
            Pants userPants = new Pants(in.next(), in.nextInt());
            TShirt userTshirt = new TShirt(in.next(), in.nextInt());
            Clothes [] arrayClothes = new Clothes []{userSkirt, userPants, userTshirt, userTie};
            for(Clothes dress: arrayClothes) {
                if(dress.getClass() == Tie.class) {
                    userTie.dressMan();
                }
                if(dress.getClass() == Skirt.class) {
                    userSkirt.dressWoman();
                }
                if(dress.getClass() == Pants.class) {
                    userPants.dressMan();
                    userPants.dressWoman();
                }
                if(dress.getClass() == TShirt.class) {
                    userTshirt.dressMan();
                    userTshirt.dressWoman();
                }
            }
    }
}
