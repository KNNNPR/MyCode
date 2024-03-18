package ru.mirea.lab2.MVideoK;

import java.util.Scanner;

public class MVideo {
    public static void main(String[]  args) {
        Scanner in = new Scanner(System.in);
        int userControl;
        Shop Mvideo = new Shop();
        String newBrand;
        String newModel;
        while(true){
            userControl = in.nextInt();
            switch(userControl){
                case 1: {
                    System.out.println("Enter Data");
                    newBrand = in.next();
                    newModel = in.next();
                    Mvideo.addComputer(newBrand, newModel);
                    break;
                }
                case 2: {
                    System.out.println("Enter Data");
                    newBrand = in.next();
                    newModel = in.next();
                    Mvideo.removeComputer(newBrand, newModel);
                    break;
                }
                case 3: {
                    System.out.println("Enter Data");
                    newBrand = in.next();
                    newModel = in.next();
                    Mvideo.searchComp(newBrand, newModel);
                    break;
                }
                case 4: {
                    System.exit(0);
                }
            }
        }
    }
}
