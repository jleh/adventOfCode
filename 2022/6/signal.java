import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.HashSet;

public class signal {
    public static void main(String[] args) throws Exception {
        int distinctChars = 14;
        String line = Files.readString(Paths.get("input.txt"));

        for (int i = distinctChars; i < line.length(); i++) {
            var chars = new HashSet<>();

            for (int j = 0; j < distinctChars; j++) {
                chars.add(line.charAt(i - j));
            }

            if (chars.size() == distinctChars) {
                System.out.println(i + 1);
                break;
            }
        }
    }
}
