package ExamTasks.Task11_firstLast;



public class main {
    public static void main(String[] args) {
        LinkedIntList list1 = new LinkedIntList();
        list1.addNode(1);
        list1.addNode(8);
        list1.addNode(6);
        list1.addNode(10);
        list1.showList();
        System.out.println();
        list1.firstLast();
        list1.showList();
    }
}
