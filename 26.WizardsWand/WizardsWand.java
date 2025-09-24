
class WizardsdWand{
    static long kadane(long[] arr) {
        long best = arr[0], curr = arr[0];
        for (int i = 1; i < arr.length; i++) {
            curr = Math.max(arr[i], curr + arr[i]);
            best = Math.max(best, curr);
        }
        return best;
    }

    static long wizardWand(long[] arr) {
        int n = arr.length;
        if (n == 1) return arr[0];

        long ans = kadane(arr);

        long[] maxLeft = new long[n];
        long curr = arr[0];
        maxLeft[0] = arr[0];
        for (int i = 1; i < n; i++) {
            curr = Math.max(arr[i], curr + arr[i]);
            maxLeft[i] = Math.max(maxLeft[i-1], curr);
        }

        long[] maxRight = new long[n];
        curr = arr[n-1];
        maxRight[n-1] = arr[n-1];
        for (int i = n-2; i >= 0; i--) {
            curr = Math.max(arr[i], curr + arr[i]);
            maxRight[i] = Math.max(maxRight[i+1], curr);
        }
        for (int i = 0; i + 2 < n; i++) {
            ans = Math.max(ans, maxLeft[i] + maxRight[i+2]);
        }

        return ans;
    }
}