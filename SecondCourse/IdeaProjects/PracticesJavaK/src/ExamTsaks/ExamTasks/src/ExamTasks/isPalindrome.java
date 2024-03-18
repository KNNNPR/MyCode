package ExamTasks;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class isPalindrome {
    public static boolean isPalindrome(Queue<Integer> userQueue) {
        Stack<Integer> help = new Stack<>();

        for(int i = 0; i < userQueue.size(); i++) {
            userQueue.add(userQueue.peek());
            help.push(userQueue.poll());
        }
        for(int i = 0; i< userQueue.size(); i++) {
            if(help.peek() != userQueue.peek()) {
                System.out.println(help);
                System.out.println(userQueue);
                return (false);
            }
            userQueue.add(help.pop());
            userQueue.poll();
        }
        System.out.println(userQueue);
        return(true);
    }


    public static void main(String[] args) {
        Queue<Integer> test = new LinkedList<>();
        test.add(3);
        test.add(5);
        test.add(7);
        test.add(9);
        test.add(1);
        test.add(5);
        test.add(3);
        System.out.println(isPalindrome(test));
    }
}
