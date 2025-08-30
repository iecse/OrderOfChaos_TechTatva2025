public class CelestialForge {
    public int minInstability(int[] crystals, long K) {
        int n = crystals.length;
        if (n == 0) return -1;

        int maxDiff = 0;
        for (int i = 1; i < n; i++) {
            maxDiff = Math.max(maxDiff, Math.abs(crystals[i] - crystals[i - 1]));
        }

        int left = 0, right = maxDiff, ans = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canForge(crystals, K, mid)) {
                ans = mid;
                right = mid - 1; 
            } else {
                left = mid + 1;  
            }
        }

        return ans;
    }

    private boolean canForge(int[] crystals, long K, int d) {
        int n = crystals.length;
        int i = 0;

        while (i < n) {
            int j = i + 1;
            while (j < n && Math.abs(crystals[j] - crystals[j - 1]) <= d) {
                j++;
            }

            if (hasSubarrayWithSumAtLeastK(crystals, i, j - 1, K)) {
                return true;
            }

            i = j; 
        }

        return false;
    }

    private boolean hasSubarrayWithSumAtLeastK(int[] arr, int l, int r, long K) {
        long sum = 0;
        int start = l;
        for (int end = l; end <= r; end++) {
            sum += arr[end];
            while (sum >= K) {
                return true; 
            }
        }
        return false;
    }
}