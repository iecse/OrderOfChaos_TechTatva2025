import java.util.Arrays;

public class ArchonAttunement {
    public int solveAttunement(int[] caches, int H) {
        int left = 1;
        int right = Arrays.stream(caches).max().orElse(0);
        int min_k = right;

        while (left <= right) {
            int k = left + (right - left) / 2;
            if (k == 0) {
                left = 1;
                continue;
            }
            long total_cycles = 0;
            for (int cache : caches) {
                total_cycles += (long)(cache + k - 1) / k;
            }
            if (total_cycles <= H) {
                min_k = k;
                right = k - 1;
            } else {
                left = k + 1;
            }
        }
        return min_k;
    }
}