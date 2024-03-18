package ExamTasks.Task9_removeDuplicates;

public class main {
    public static void main(String[] args) {
        LinkedIntList list1 = new LinkedIntList();
        list1.addNode(14);
        list1.addNode(8);
        list1.addNode(14);
        list1.addNode(12);
        list1.addNode(1);
        list1.addNode(14);
        list1.addNode(11);
        list1.addNode(8);
        list1.addNode(8);
        list1.addNode(10);
        list1.addNode(4);
        list1.addNode(9);
        list1.addNode(1);
        list1.addNode(2);
        list1.addNode(5);
        list1.addNode(2);
        list1.addNode(4);
        list1.addNode(12);
        list1.addNode(12);
        list1.showList();


        System.out.println();
        System.out.println();

        list1.removeDuplicates();
        list1.showList();
    }
}
