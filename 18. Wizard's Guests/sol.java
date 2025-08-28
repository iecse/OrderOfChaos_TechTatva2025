import java.util.Scanner;
public class WizardGuests {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int d = sc.nextInt();
            int k = sc.nextInt();

            int[] diff = new int[n + 2]; 

            for (int i = 0; i < k; i++) {
                int l = sc.nextInt();
                int r = sc.nextInt();
                diff[l] += 1;
                if (r + 1 <= n) diff[r + 1] -= 1;
            }
            // prefix sum to get number of quests on each day
            int[] jobs = new int[n + 1];
            for (int i = 1; i <= n; i++) {
                jobs[i] = jobs[i - 1] + diff[i];
            }
            // sliding window for d-day visits
            int windowSum = 0;
            for (int i = 1; i <= d; i++) {
                windowSum += jobs[i];
            }
            int maxOverlap = windowSum;
            int minOverlap = windowSum;
            int bestBrother = 1;
            int bestMother = 1;
            for (int start = 2; start <= n - d + 1; start++) {
                windowSum = windowSum - jobs[start - 1] + jobs[start + d - 1];
                if (windowSum > maxOverlap) {
                    maxOverlap = windowSum;
                    bestBrother = start;
                }
                if (windowSum < minOverlap) {
                    minOverlap = windowSum;
                    bestMother = start;
                }
            }
            System.out.println(bestBrother + " " + bestMother);
        }

        sc.close();
    }
}
