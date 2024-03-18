package ExamTasks.Task11_firstLast;

public class LinkedIntList {
    private ListNode front;


    public void addNode(int userData) {
        ListNode insertedNode = new ListNode(userData);
        if(front == null) front = insertedNode;
        else {
            ListNode current = front;
            while(current.next != null) {
                current = current.next;
            }
            current.next = insertedNode;
        }
    }
    public void showList() {
        ListNode iter = front;
        while(iter != null) {
            System.out.print(iter.data + " ");
            iter = iter.next;
        }
    }
    public void firstLast() {
        ListNode iter = front;
        while(iter.next != null) {
            iter = iter.next;
        }
        iter.next = front;
        front = front.next;
        iter.next.next = null;
//        ListNode first = front;
//        front = front.next;
//        ListNode current = front;
//        while(current.next != null) {
//            current = current.next;
//        }
//        current.next = first;
//        first.next = null;
    }
}
