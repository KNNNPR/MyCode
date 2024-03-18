package ExamTasks.Task26_ArrayListList;

public class main {
    public static void main(String[] args) {
        ArrayListList test =  new ArrayListList();
        test.add(23);
        test.add(32);
        test.add(1);
        test.add(-10);
        test.add(-90);
        test.add(2);
        test.add(0);
        test.show();


        System.out.println(test.get(3));
        test.set(3, 900);
        test.show();
        test.add(666);
        test.show();
        System.out.println(test.isEmpty());
        test.remove(4);
        test.show();
    }
}
