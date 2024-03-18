package ExamTasks;

import java.util.HashMap;
import java.util.Map;

public class reverse {
    public static Map<String, Integer>reverse(Map<Integer, String> startMap) {
        Map<String, Integer> result = new HashMap<>();
        for(Map.Entry<Integer, String> entry : startMap.entrySet()) {
            result.put(entry.getValue(), entry.getKey());
        }
        return(result);
    }

    public static void main(String[] args) {
        Map<Integer, String> a = Map.of(1, "one", 2, "two");
        Map<Integer, String> b = Map.of(3, "three", 2, "four");
        System.out.println(reverse(a));
        System.out.println(reverse(b));
    }
}
