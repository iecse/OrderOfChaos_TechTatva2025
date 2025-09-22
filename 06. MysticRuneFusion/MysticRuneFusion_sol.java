import java.util.*;

public class MysticRuneFusion {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();
            int[] runes = new int[n];
            for (int i = 0; i < n; i++) {
                runes[i] = sc.nextInt();
            }

            long maxSum = Long.MIN_VALUE;

            for (int start = 0; start < n; start++) {
                for (int end = start; end < n; end++) {
                    int[] fused = new int[n];
                    for (int i = 0; i < n; i++) {
                        fused[i] = runes[i];
                    }

                    for (int i = start + 1; i <= end; i++) {
                        if (fused[i] > fused[i - 1] && fused[i - 1] != 0) {
                            fused[i] += fused[i - 1];
                            fused[i - 1] = 0;
                        }
                    }

                    long sum = 0;
                    for (int i = start; i <= end; i++) {
                        sum += fused[i];
                    }

                    if (sum > maxSum) {
                        maxSum = sum;
                    }
                }
            }

            System.out.println(maxSum);
        }
    }
}
