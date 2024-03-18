package ExamTasks.Task7_removeAll;

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
            System.out.println(iter.data);
            iter = iter.next;
        }
    }
    public void removeAll(LinkedIntList otherList) {
        ListNode curr1 = front;
        ListNode prev = null;
        ListNode curr2 = otherList.front;
        while (curr1 != null && curr2 != null) {
            if(curr1.data == curr2.data) {
                if(prev == null) {
                    front = curr1.next;
                    curr1 = front;
                }
                else {
                    prev.next = curr1.next;
                    curr1 = prev.next;
                }
                curr2 = curr2.next;
            }
            else if(curr1.data < curr2.data) {
                prev = curr1;
                curr1 = curr1.next;
            }
            else curr2 = curr2.next;
        }
    }
}
