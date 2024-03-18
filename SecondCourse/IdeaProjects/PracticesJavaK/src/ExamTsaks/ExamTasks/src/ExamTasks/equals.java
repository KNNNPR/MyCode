package ExamTasks;

import java.util.Stack;

public class equals {
    public static boolean equals(Stack<Integer> firstStack, Stack<Integer> secondStack) {
        Stack<Integer> help = new Stack<>();
        while(!firstStack.isEmpty() && !secondStack.isEmpty()) {
            if(firstStack.peek() != secondStack.peek()) {
                if(help.isEmpty()) {
                    System.out.println(firstStack);
                    System.out.println(secondStack);
                    return(false);
                }
                firstStack.push(help.pop());
                secondStack.push(help.pop());
                System.out.println(firstStack);
                System.out.println(secondStack);
                return(false);
            }
            help.push(firstStack.pop());
            help.push(secondStack.pop());
        }
        while(!help.isEmpty()) {
            firstStack.push(help.pop());
            secondStack.push(help.pop());
        }
        System.out.println(firstStack);
        System.out.println(secondStack);
        return(true);
    }


    public static void main(String[] args) {
        Stack<Integer> test1 = new Stack<>();
        test1.push(3);
        test1.push(2);
        test1.push(1);

        Stack<Integer> test2 = new Stack<>();
        test2.push(3);
        test2.push(2);
        test2.push(2);

        System.out.println(equals(test1, test2));

        System.out.println(test1);
        System.out.println(test2);
    }
}
