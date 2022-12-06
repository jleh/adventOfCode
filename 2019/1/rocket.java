import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;

public class rocket {
    public static void main(String[] args) throws Exception {
        List<String> lines = Files.readAllLines(Paths.get("input.txt"));
        int sum = 0;

        for (String line : lines) {
            int mass = Integer.parseInt(line);
            int a;
            while ((a = calculateFuel(mass)) > 0) {
                sum = sum + a;
                mass = a;
            }
        }

        System.out.println(sum);
    }

    private static int calculateFuel(int mass) {
        return mass / 3 - 2;
    }
}
