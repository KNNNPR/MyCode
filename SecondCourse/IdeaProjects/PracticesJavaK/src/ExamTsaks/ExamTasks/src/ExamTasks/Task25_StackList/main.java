package ExamTasks.Task25_StackList;

public class main {
    public static void main(String[] args) {
        StackList test = new StackList();
        test.push(1);
        test.push(2);
        test.push(4);
        test.push(23);
        test.push(10);
        test.push(-9);
        test.push(23);
        test.push(12);
        test.show();
        test.pop();
        test.pop();
        System.out.println();
        System.out.println(test.peek());
    }
}
