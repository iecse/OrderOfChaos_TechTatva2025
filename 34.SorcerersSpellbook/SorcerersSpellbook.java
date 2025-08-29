import java.util.*;

public class SorcerersSpellbook {

    public static String finalSpellbook(String s) {
        Stack<Character> stack = new Stack<>();

        for (char ch : s.toCharArray()) {
            if (!stack.isEmpty() && stack.peek() == ch) {
                stack.pop(); // annihilation
            } else {
                stack.push(ch);
            }
        }

        // rebuild the string
        StringBuilder result = new StringBuilder();
        for (char ch : stack) {
            result.append(ch);
        }

        return result.length() == 0 ? "Empty Spellbook" : result.toString();
    }
}