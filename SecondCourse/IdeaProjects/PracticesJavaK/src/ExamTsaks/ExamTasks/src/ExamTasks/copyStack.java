package ExamTasks;

import java.lang.invoke.StringConcatException;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class copyStack {
    public static Stack<Integer> copyStack(Stack<Integer> userStack) {
        Stack<Integer> result = new Stack<>();
        Queue<Integer> help = new LinkedList<>();

        while(!userStack.isEmpty()) {
            help.add(userStack.pop());
        }
        while(!help.isEmpty()) {
            result.push(help.poll());
        }
        while(!result.isEmpty()) {
            help.add(result.pop());
        }
        while(!help.isEmpty()) {
            result.push(help.peek());
            userStack.push(help.poll());
        }
        return (result);
    }


    public static void main(String[] args) {
        Stack<Integer> test = new Stack<>();
        test.push(1);
        test.push(3);
        test.push(16);
        test.push(22);
        test.push(27);
        copyStack(test);
    }
}
