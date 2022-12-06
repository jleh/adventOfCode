import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Arrays;

public class paper {
    private static int l = 0;
    private static int w = 1;
    private static int h = 2;

    public static void main(String[] args) throws Exception {
        var lines = Files.readAllLines(Paths.get("input.txt"));
        var total = 0;

        for (var line : lines) {
            var values = new int[3];
            var strValues = line.split("x");
            values[l] = Integer.parseInt(strValues[l]);
            values[w] = Integer.parseInt(strValues[w]);
            values[h] = Integer.parseInt(strValues[h]);

            var area = 2 * values[l] * values[w] 
                    + 2 * values[w] * values[h] 
                    + 2 * values[h] * values[l];
            
            int[] areas = new int[] {
                values[l] * values[w], 
                values[w] * values[h],
                values[h] * values[l]
            };

            Arrays.sort(areas);

            total = total + area + areas[0];
        }

        System.out.println(total);
    }
}
