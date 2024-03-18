package ExamTasks.Task26_ArrayListList;

import ExamTasks.Task18_longestSortedSequence.ArrayIntList;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public class ArrayListList {
    private List<Integer> arrayListElements;

    public ArrayListList (){
        arrayListElements = new LinkedList<>();
    }
    public void add(int userNum) {
        arrayListElements.add(userNum);
    }
    public void clear() {
        arrayListElements.clear();
    }
    public boolean isEmpty() {
        return(arrayListElements.isEmpty());
    }
    public int get(int index) {
        return(arrayListElements.get(index));
    }
    public void remove(int index) {
        arrayListElements.remove(index);
    }
    public void set(int index, Integer userInt) {
        arrayListElements.set(index, userInt);
    }
    public void show() {
        for(int i =0 ; i < arrayListElements.size(); i++) {
            System.out.print(arrayListElements.get(i) + " ");
        }
        System.out.println();
    }
}

