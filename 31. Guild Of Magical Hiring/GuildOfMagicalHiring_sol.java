import java.util.*;

public class Main {
    public double mincostToHireWorkers(int[] quality, int[] wage, int k) {
        int n = quality.length;
        double[] ratio = new double[n];
        Integer[] indices = new Integer[n];
        for (int i = 0; i < n; i++) {
            ratio[i] = (double) wage[i] / quality[i];
            indices[i] = i;
        }
        Arrays.sort(indices, Comparator.comparingDouble(i -> ratio[i]));

        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        int sumQuality = 0;
        double res = Double.MAX_VALUE;

        for (int i = 0; i < n; i++) {
            int idx = indices[i];
            maxHeap.offer(quality[idx]);
            sumQuality += quality[idx];
            if (maxHeap.size() > k) sumQuality -= maxHeap.poll();
            if (maxHeap.size() == k) res = Math.min(res, ratio[idx] * sumQuality);
        }

        return res;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        Main sol = new Main();

        while (T-- > 0) {
            int n = sc.nextInt();
            int k = sc.nextInt();
            int[] quality = new int[n];
            int[] wage = new int[n];
            for (int i = 0; i < n; i++) quality[i] = sc.nextInt();
            for (int i = 0; i < n; i++) wage[i] = sc.nextInt();

            double ans = sol.mincostToHireWorkers(quality, wage, k);
            System.out.printf("%.5f\n", ans);
        }
    }
}
