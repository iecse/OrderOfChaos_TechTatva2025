import java.util.*;

public class Solution {
    public String predictOutcome(int[] spells) {
        Deque<Integer> activeSpells = new ArrayDeque<>();

        for (int spell : spells) {
            if (spell > 0) {
                activeSpells.push(spell);
            } else {
                while (!activeSpells.isEmpty() && activeSpells.peek() > 0 && spell < 0) {
                    int sunfire = activeSpells.peek();

                    if (sunfire > Math.abs(spell)) {
                        activeSpells.push(activeSpells.pop() + spell);
                        spell = 0;
                    } else if (sunfire < Math.abs(spell)) {
                        activeSpells.pop();
                        spell += sunfire;
                    } else {
                        activeSpells.pop();
                        spell = 0;
                    }
                }
                if (spell < 0) {
                    activeSpells.push(spell);
                }
            }
        }

        List<Integer> remainingSpells = new ArrayList<>();
        while (!activeSpells.isEmpty()) {
            remainingSpells.add(0, activeSpells.pop());
        }

        int left = 0;
        int right = remainingSpells.size() - 1;
        while (left < right) {
            if (!remainingSpells.get(left).equals(remainingSpells.get(right))) {
                return "Chaotic";
            }
            left++;
            right--;
        }

        return "Harmonious";
    }
}