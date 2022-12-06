import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;
import java.util.stream.Collectors;

public class sonar {
    public static void main(String[] args) throws Exception {
        List<String> lines = Files.readAllLines(Paths.get("input.txt"));
        List<Integer> input = lines.stream()
            .map(l -> Integer.parseInt(l))
            .collect(Collectors.toList());
        int counter = 0;
        int counter2 = 0;

        for (int i = 1; i < input.size(); i++) {
            if (input.get(i) > input.get(i - 1)) counter++;
        }

        for (int i = 3; i < input.size(); i++) {
            int windowA = input.get(i) + input.get(i - 1) + input.get(i - 2);
            int windowB = input.get(i - 1) + input.get(i - 2) + input.get(i - 3);

            if (windowA > windowB) counter2++;
        }

        System.out.println(counter);
        System.out.println(counter2);
    }
}
