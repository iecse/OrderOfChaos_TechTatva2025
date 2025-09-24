import java.util.*;

static boolean RunesOfEquilibrium(int[] arr, long total) {
    long prefix = 0;
    for (int i = 0; i < arr.length - 1; i++) {
        prefix += arr[i];
        if (prefix * 2 == total) return true;
    }

    Map<Long, Integer> freq = new HashMap<>();
    for (int x : arr) freq.put((long)x, freq.getOrDefault((long)x, 0) + 1);

    prefix = 0;
    for (int x : arr) {
        prefix += x;
        freq.put((long)x, freq.get(x*1L) - 1);
        if (freq.get((long)x) == 0) freq.remove((long)x);

        long left = prefix - x, right = total - prefix;
        if (left == right || (right - left != 0 && freq.containsKey(right - left))) return true;
    }
    return false;
}
