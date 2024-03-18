package ExamTasks;

import java.util.HashMap;
import java.util.Map;

public class isUnique {
    public static boolean isUnique(Map<String, String> startMap) {
        Map<String, Integer> result = new HashMap<>();
        for(Map.Entry<String, String> entry : startMap.entrySet()) {
            result.put(entry.getValue(), result.getOrDefault(entry.getValue(), 0) + 1);
        }
        for(int compare: result.values()) {
            if(compare > 1) return (false);
        }
        System.out.println(result);
        return(true);
    }

    public static void main(String[] args) {
        Map<String,String> map1 = new HashMap<>();
        map1.put("Marty","Stepp");
        map1.put("Stuart","Reges");
        map1.put("Jessica","Miller");
        map1.put("Amanda","Camp");
        map1.put("Hal","Perkins");
        System.out.println(isUnique(map1));
    }
}
