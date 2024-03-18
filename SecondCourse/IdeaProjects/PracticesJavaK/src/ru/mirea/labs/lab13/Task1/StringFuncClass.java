package ru.mirea.labs.lab13.Task1;

public class StringFuncClass {
    private String phrace;

    public char printLastChar() {
        return(phrace.charAt(phrace.length() - 1));
    }
    public boolean endsWithTripleSign() {
        return(phrace.endsWith("!!!"));
    }
    public boolean startsWithILove() {
        return(phrace.startsWith("I Love"));
    }
    public boolean containsJava() {
        return(phrace.contains("Java"));
    }
    public int positionOfJava() {
        return(phrace.indexOf("Java"));
    }
    public void changeChar() {
        phrace = phrace.replace('a', 'o');
    }
    public void toUpper() {
        phrace = phrace.toUpperCase();
    }
    public void toLower() {
        phrace = phrace.toLowerCase();
    }

    public StringFuncClass(String phrace) {
        this.phrace = phrace;
    }

    public static void main(String[] args) {
        StringFuncClass userString = new StringFuncClass(System.in.toString());
        userString.changeChar();
        System.out.println(userString.containsJava());
        System.out.println(userString.endsWithTripleSign());
        System.out.println(userString.printLastChar());
        System.out.println(userString.positionOfJava());
        System.out.println(userString.startsWithILove());
    }
}
