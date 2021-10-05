import java.util.*;

class MapUtils {

    public static SortedMap<String, Integer> wordCount(String[] strings) {
        // write your code here
        SortedMap<String, Integer> myMap = new TreeMap<>();
        int count = 1;
        for (int i = 0; i < strings.length; i++) {
            count = 1;
            for (int j = i + 1; j < strings.length; j++) {
                if (strings[i].equals(strings[j])) {
                    count++;
                }
            }
                if (!myMap.containsKey(strings[i])) {
                    myMap.put(strings[i], count);
                }

        }
        return myMap;
    }

    public static void printMap(Map<String, Integer> map) {
        // write your code here
        for (var entry : map.entrySet()) {
            System.out.println(entry.getKey() + " : " + entry.getValue());
        }
    }

}

/* Do not change code below */
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] words = scanner.nextLine().split(" ");
        MapUtils.printMap(MapUtils.wordCount(words));
    }
}