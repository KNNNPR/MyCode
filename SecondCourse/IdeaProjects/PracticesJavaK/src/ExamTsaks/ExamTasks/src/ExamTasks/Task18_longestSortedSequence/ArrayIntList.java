package ExamTasks.Task18_longestSortedSequence;

public class ArrayIntList {
    private int[] elementData;
    private int size;



    public ArrayIntList(int[] userArray) {
        elementData = userArray;
        size = userArray.length;
    }
    public int longestSortedSequence() {
        int length = 1;
        int savedLength = 0;
        for(int i = 0; i < size - 1; i++) {
            if(elementData[i] > elementData[i + 1]) {
                savedLength = Math.max(savedLength, length);
                length = 1;
            }
            else {
                length++;
            }
        }
        return(savedLength);
    }
}
