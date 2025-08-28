import java.util.*;

public class Paradox {
    public static int[] nextStrongerWaits(int[] readings) {
        int n = readings.length;
        int[] ans = new int[n];
        int[] stack = new int[n];
        int top = -1;

        for (int i = 0; i < n; i++) {
            while (top >= 0 && readings[i] > readings[stack[top]]) {
                int idx = stack[top--];
                ans[idx] = i - idx;
            }
            stack[++top] = i;
        }
        return ans;
    }

    public static void main(String[] args) {
        int[] a = {89, 91, 95, 87, 85, 90, 97};
        System.out.println(Arrays.toString(nextStrongerWaits(a)));

        int[] b = {100, 90, 80, 70};
        System.out.println(Arrays.toString(nextStrongerWaits(b)));
    }
}
