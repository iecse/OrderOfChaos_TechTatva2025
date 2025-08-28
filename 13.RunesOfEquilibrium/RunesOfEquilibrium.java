import java.util.*;

public class RunesOfEquilibrium {
    public static void main(String[] args) {
        @SuppressWarnings("resource")
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int[] arr = new int[n];
            long total = 0;
            for (int i = 0; i < n; i++) {
                arr[i] = sc.nextInt();
                total += arr[i];
            }
            if (canBalance(arr, total)) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }

    static boolean canBalance(int[] arr, long total) {
        int n = arr.length;
        long prefix = 0;
        for (int i = 0; i < n - 1; i++) {
            prefix += arr[i];
            if (prefix * 2 == total) return true;
        }

        prefix = 0;
        Map<Long, Integer> freq = new HashMap<>();
        for (int x : arr) freq.put((long)x, freq.getOrDefault((long)x, 0) + 1);

        for (int i = 0; i < n; i++) {
            prefix += arr[i];
            freq.put((long)arr[i], freq.get(arr[i]*1L) - 1);
            if (freq.get((long)arr[i]) == 0) freq.remove((long)arr[i]);

            long leftSum = prefix - arr[i];
            long rightSum = total - prefix;
            if (leftSum == rightSum) return true;

            long diff = rightSum - leftSum;
            if (diff != 0 && freq.containsKey(diff)) return true;
        }

        return false;
    }
}
