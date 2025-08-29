
import java.util.*;

public class MysticalRitualCircles {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();
            long totalEnergy = sc.nextLong();
            int peakEnergy = sc.nextInt();

            int[] energy = new int[n + 1];
            long[] prefix = new long[n + 1];

            for (int i = 1; i <= n; i++) {
                energy[i] = sc.nextInt();
                prefix[i] = prefix[i - 1] + energy[i];
            }

            long ritualCount = 0;
            Map<Long, Integer> prefixCount = new HashMap<>();
            int leftBound = 1;

            for (int right = 1; right <= n; right++) {
                if (energy[right] > peakEnergy) {
                    prefixCount.clear();
                    leftBound = right + 1;
                } else if (energy[right] == peakEnergy) {
                    while (leftBound <= right) {
                        prefixCount.put(prefix[leftBound - 1],
                                prefixCount.getOrDefault(prefix[leftBound - 1], 0) + 1);
                        leftBound++;
                    }
                }

                long targetPrefix = prefix[right] - totalEnergy;
                ritualCount += prefixCount.getOrDefault(targetPrefix, 0);
            }

            System.out.println(ritualCount);
        }

        sc.close();
    }
}