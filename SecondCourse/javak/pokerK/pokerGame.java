package ru.mirea.lab2.pokerK;

import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;

public class pokerGame {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int playersAmount = in.nextInt();
        String[] suits = {"h", "s", "d", "k"};
        String[] value = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "valet", "queen", "king", "ace"};
        int lengthOfDeck = suits.length*value.length;
        if (5*playersAmount > lengthOfDeck || 5*playersAmount <= 0) {
            System.out.println("Wrong input");
            System.exit(0);
        }
        String[] deck = new String[lengthOfDeck];
        int index = 0;
        for(int i = 0; i < suits.length; i++) {
            for(int j = 0; j < value.length; j++) {
                deck[index] = suits[i] + " " + value[j];
                index++;
            }
        }
        Random rnd = new Random();
        for(int i = 0; i < lengthOfDeck; i++) {
            int randomIndex = rnd.nextInt(i + 1);
            String rand = deck[randomIndex];
            deck[randomIndex] = deck[i];
            deck[i] = rand;
        }
        int counter = 0;
        for(int i = 0; i < 5*playersAmount; i++) {
            if(counter == 5) {
                System.out.print('\n');
                counter = 0;
            }
            System.out.print(deck[i]+ ",");
            counter++;
        }
    }
}
