import java.nio.file.Files;
import java.nio.file.Paths;

public class captcha {
    public static void main(String[] args) throws Exception {
        var line = Files.readString(Paths.get("input.txt"));
        int sum = 0;

        for (int i = 0; i < line.length(); i++) {
            var nextIndex = i + line.length() / 2;
            var nextC = nextIndex > line.length() - 1
                ? line.charAt(nextIndex - line.length()) 
                : line.charAt(nextIndex);
            var next = Integer.parseInt("" + nextC);
            var current = Integer.parseInt("" + line.charAt(i));

            if (next == current) {
                sum = sum + current;
            }
        }

        System.out.println(sum);
    }
}
