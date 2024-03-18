package ExamTasks.Task7_removeAll;

public class main {
    public static void main(String[] args) {
        LinkedIntList list1 = new LinkedIntList();
        list1.addNode(1);
        list1.addNode(3);
        list1.addNode(5);
        list1.addNode(7);
        list1.showList();


        System.out.println();


        LinkedIntList list2 = new LinkedIntList();
        list2.addNode(1);
        list2.addNode(2);
        list2.addNode(3);
        list2.addNode(4);
        list2.addNode(5);
        list2.showList();


        list2.removeAll(list1);



        System.out.println();



        list2.showList();
    }
}
