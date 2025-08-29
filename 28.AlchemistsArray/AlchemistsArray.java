import java.util.*;

public class AlchemistsArray {

    public static int findLongestBalancedMix(int[] potions) {
        if (potions == null || potions.length == 0) {
            return 0;
        }

        Map<Integer, Integer> counts = new HashMap<>();
        Map<Integer, Integer> freqs = new HashMap<>();
        int longestMix = 0;

        for (int i = 0; i < potions.length; i++) {
            int potion = potions[i];
            int currentLength = i + 1;

            int oldCount = counts.getOrDefault(potion, 0);
            counts.put(potion, oldCount + 1);

            if (oldCount > 0) {
                freqs.put(oldCount, freqs.get(oldCount) - 1);
                if (freqs.get(oldCount) == 0) {
                    freqs.remove(oldCount);
                }
            }

            int newCount = oldCount + 1;
            freqs.put(newCount, freqs.getOrDefault(newCount, 0) + 1);

            boolean isBalanced = false;

            if (freqs.size() == 1) {
                isBalanced = true;
            } else if (freqs.size() == 2) {
                Object[] keys = freqs.keySet().toArray();
                int freq1 = (int) keys[0];
                int freq2 = (int) keys[1];
                if (Math.abs(freq1 - freq2) == 1) {
                    isBalanced = true;
                }
            }
            
            if (isBalanced) {
                longestMix = currentLength;
            }
        }
        return Math.max(potions.length > 0 ? 1 : 0, longestMix);
    }

    public static void main(String[] args) {
        int[] potions1 = {2, 2, 1, 1, 5, 3, 3}; 
        int[] potions2 = {1, 1, 2, 2, 1, 3, 4, 5};

        System.out.println("--- Corrected Alchemist's Array Tests ---");

        int result1 = findLongestBalancedMix(potions1);
        System.out.println("Input: " + Arrays.toString(potions1) + ", Longest Mix: " + result1);

        int result2 = findLongestBalancedMix(potions2);
        System.out.println("Input: " + Arrays.toString(potions2) + ", Longest Mix: " + result2);
    }
}