package ExamTasks;

import java.util.Set;

public class hasOdd {
    public static boolean hasOdd(Set<Integer> startSet) {
        for(int compare: startSet) {
            if (compare % 2 != 0) {
                return(true);
            }
        }
        return(false);
    }

    public static void main(String[] args) {
        Set<Integer> a = Set.of();
        System.out.println(hasOdd(a));
    }
}
