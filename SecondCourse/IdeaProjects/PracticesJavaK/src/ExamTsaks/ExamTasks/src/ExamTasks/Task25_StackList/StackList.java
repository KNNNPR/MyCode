package ExamTasks.Task25_StackList;

import java.util.ArrayList;
import java.util.List;

public class StackList {
    private List<Integer> stackElems;



    public StackList() {
        stackElems = new ArrayList<>();
    }

    public int peek() {
        return (stackElems.get(stackElems.size() - 1));
    }
    public void pop() {
        stackElems.remove(stackElems.size() - 1);
    }
    public void push(int userNum) {
        stackElems.add(userNum);
    }
    public void show() {
        for(int c: stackElems) {
            System.out.print(c + " ");
        }
    }
}
