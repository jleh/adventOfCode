import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.HashSet;
import java.util.Set;

public class calibration {
    public static void main(String[] args) throws Exception {
        var lines = Files.readAllLines(Paths.get("input.txt"));
        var frequency = 0;
        Set<Integer> seenFrequencies = new HashSet<>();
        boolean found = false;

        seenFrequencies.add(0);

        while (!found) {
            for (var line : lines) {
                frequency = frequency + Integer.parseInt(line);
                
                if (seenFrequencies.contains(frequency)) {
                    System.out.println("Part 2: " + frequency);
                    found = true;
                    return;
                }
    
                seenFrequencies.add(frequency);
            }
        }
    }
}
