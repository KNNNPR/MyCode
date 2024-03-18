package ru.mirea.labs.lab4.Task1;

import java.util.Scanner;

public class TimesOfYearK {
    public enum TimesOfYear {
        Winter( -5),
        Spring( 12),
        Summer( 27),
        Autumn( 9) {
            @Override
            public String getDescription() {
                return("Warm time of year");
            }
        };

        private String name;
        private int temp;

        TimesOfYear( int temp) {
            this.temp = temp;
        }

        public String getDescription() {
            return("Cold time of Year");
        }
    }

     static void favouriteTime(TimesOfYear userTime) {
        switch(userTime) {
            case Winter: {
                System.out.println("Winter is GOAT!");
                break;
            }
            case Spring: {
                System.out.println("Spring is GOAT!");
                break;
            }
            case Summer: {
                System.out.println("Summer is GOAT!");
                break;
            }
            case Autumn: {
                System.out.println("Autumn is GOAT!");
                break;
            }
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int userChoise = in.nextInt();
        TimesOfYear userTime;
        switch(userChoise) {
            case 1: {
                userTime = TimesOfYear.Winter;
                break;
            }
            case 2: {
                userTime = TimesOfYear.Spring;
                break;
            }
            case 3: {
                userTime = TimesOfYear.Summer;
                break;
            }
            case 4: {
                userTime = TimesOfYear.Autumn;
                break;
            }
            default: {
                userTime = TimesOfYear.Winter;
                break;
            }
        }
        favouriteTime(userTime);
        for(TimesOfYear time: TimesOfYear.values()) {
            System.out.println(time.toString() + "  " + time.temp + "  " +time.getDescription());
        }
    }
}
