package ExamTasks;

import java.util.HashMap;
import java.util.Map;

public class rarest {
    public static int rarest(Map<String, Integer> startMap) throws Exception {
        if(startMap.isEmpty()) {
            throw new Exception("Map is empty");
        }
        Map<Integer, Integer> result = new HashMap<>();
        for (Map.Entry<String, Integer> entry : startMap.entrySet()) {
            result.put(entry.getValue(), result.getOrDefault(entry.getValue(), 0) + 1);
        }
        System.out.println(result);


        int resultReturn = 10000;
        int resultKey = -1;
        for(Map.Entry<Integer, Integer> entry : result.entrySet()) {
            if(entry.getValue() < resultReturn) {
                resultReturn = entry.getValue();
                resultKey = entry.getKey();
            }
        }
        return (resultKey);
        }



    public static void main(String[] args) throws Exception {
        Map<String, Integer> map = new HashMap<>();
        map.put("Ally", 20);
        map.put("Victor", 17);
        map.put("Billy", 21);
        map.put("William", 20);
        map.put("Roger", 21);
        map.put("Bob", 22);
        map.put("Robert", 22);
        map.put("Stanley", 20);
        map.put("Jack", 17);
        map.put("Alan", 15);
        map.put("Bettie", 34);
        System.out.println(rarest(map));
    }
}
