package ExamTasks.Task9_removeDuplicates;

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
    public void removeDuplicates() {
        ListNode current = front;
        while (current != null) {
            ListNode previous = null;
            ListNode duplicate = current.next;
            if (duplicate == null) return;
            while (duplicate.next != null && duplicate.data != current.data) {
                previous = duplicate;
                duplicate = duplicate.next;
            }
            if(duplicate.data == current.data ) {
                previous.next = duplicate.next;
            }
            else current = current.next;
        }
    }
}