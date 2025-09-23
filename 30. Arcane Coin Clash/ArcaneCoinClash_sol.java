import java.util.*;

public class ArcaneCoinClash {

    static class Interval implements Comparable<Interval> {
        int start, end;
        Interval(int a, int b) {
            this.start = a;
            this.end = b;
        }
        public int compareTo(Interval other) {
            return Integer.compare(this.start, other.start);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();
            int k = sc.nextInt(); // number of rounds, not explicitly used in calculation

            int[] a = new int[n];
            Interval[] intervals = new Interval[n];
            long ans = 0;

            for (int i = 0; i < n; i++) a[i] = sc.nextInt();

            for (int i = 0; i < n; i++) {
                int b = sc.nextInt();
                if (b < a[i]) {
                    int temp = a[i];
                    a[i] = b;
                    b = temp;
                }
                ans += b - a[i];
                intervals[i] = new Interval(a[i], b);
            }

            Arrays.sort(intervals);

            boolean overlap = false;
            for (int i = 1; i < n; i++) {
                if (intervals[i].start <= intervals[i - 1].end) {
                    overlap = true;
                    break;
                }
            }

            if (overlap) {
                System.out.println(ans);
            } else {
                int minGap = Integer.MAX_VALUE;
                for (int i = 1; i < n; i++) {
                    minGap = Math.min(minGap, intervals[i].start - intervals[i - 1].end);
                }
                System.out.println(ans + 2L * minGap);
            }
        }

        sc.close();
    }
}
