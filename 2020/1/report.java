import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;

public class report {
    public static void main(String[] args) throws Exception {
        List<String> lines = Files.readAllLines(Paths.get("input.txt"));
        
        for (int i = 0; i < lines.size(); i++) {
            for (int j = 0; j < lines.size(); j++) {
                for (int k = 0; k < lines.size(); k++) {
                    int number1 = Integer.parseInt(lines.get(i));
                    int number2 = Integer.parseInt(lines.get(j));
                    int number3 = Integer.parseInt(lines.get(k));

                    if (number1 + number2 + number3 == 2020) {
                        System.out.println(number1 * number2 * number3);
                        return;
                    }
                }
            }
        }
    }
}
