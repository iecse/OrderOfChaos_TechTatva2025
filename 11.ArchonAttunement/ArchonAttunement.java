import java.util.Arrays;

public class ArchonAttunement {

    /**
     * Finds the minimum integer Attunement Factor (k) using binary search.
     *
     * @param caches An array of integers representing the Aetherium in each cache.
     * @param H      An integer representing the total Lunar Cycles available.
     * @return The minimum integer k that allows completion within H cycles.
     */
    public int solveAttunement(int[] caches, int H) {
        // 1. Define the search space for k. The upper bound is the largest cache size.
        int left = 1;
        int right = Arrays.stream(caches).max().orElse(0);
        
        int min_k = right; // Initialize with a guaranteed valid k

        while (left <= right) {
            // Use this formula to prevent overflow when calculating the midpoint
            int k = left + (right - left) / 2;

            // k cannot be 0, but our search starts at 1. This check is for robustness.
            if (k == 0) {
                left = 1;
                continue;
            }

            // 2. Calculate the total time required for this k.
            // Use a 'long' to prevent overflow, as the sum can be very large.
            long total_cycles = 0;
            for (int cache : caches) {
                // This is an efficient integer-only way to calculate ceiling(cache / k)
                total_cycles += (long)(cache + k - 1) / k;
            }

            // 3. Check if k is valid and adjust the search space.
            if (total_cycles <= H) {
                // This k is a possible answer. Let's try to find an even smaller one.
                min_k = k;
                right = k - 1;
            } else {
                // This k is too small (too slow). We must find a larger one.
                left = k + 1;
            }
        }
        
        return min_k;
    }
}