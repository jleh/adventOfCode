import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;

public class signal {
    public static void main(String[] args) throws Exception {
        List<String> lines = Files.readAllLines(Paths.get("input.txt"));
        int lineLength = lines.get(0).length();
        String outputMax = "";
        String outputMin = "";

        for (int i = 0; i < lineLength; i++) {
            Map<Character, Integer> chars = new HashMap<>();

            for (int j = 0; j < lines.size(); j++) {
                char character = lines.get(j).charAt(i);
                Integer val = chars.get(character);
                chars.put(character, val == null ? 1 : val + 1);
            }

            Entry<Character, Integer> max = null;
            for (Entry<Character, Integer> e : chars.entrySet()) {
                if (max == null || e.getValue() > max.getValue()) {
                    max = e;
                }
            }

            Entry<Character, Integer> min = null;
            for (Entry<Character, Integer> e : chars.entrySet()) {
                if (min == null || e.getValue() < min.getValue()) {
                    min = e;
                }
            }

            outputMax = outputMax + max.getKey();
            outputMin = outputMin + min.getKey();
        }

        System.out.println(outputMax);
        System.out.println(outputMin);
    }
}
