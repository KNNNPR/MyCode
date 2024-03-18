package ExamTasks;

import java.util.ArrayList;
import java.util.List;

public class alternate {
    public static List<Integer> alternate(List<Integer> firstArray, List<Integer> secondArray) {
        List<Integer> result = new ArrayList<>();
        int firstIndex = 0;
        int secondIndex = 0;
        while(firstIndex < firstArray.size() || secondIndex < secondArray.size()) {
           if(firstIndex < firstArray.size()) {
               result.add(firstArray.get(firstIndex));
           }
            if(secondIndex < secondArray.size()) {
                result.add(secondArray.get(firstIndex));
            }
            firstIndex++;
            secondIndex++;
        }
        return result;
    }

    public static void main(String[] args) {
        List<Integer> a =  List.of(1, 2, 3, 4, 5);
        List<Integer> b =  List.of(6, 7, 8, 9, 10, 11, 12);
        System.out.println(alternate(a, b));
    }
}
