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
            
            long maxPower = Long.MIN_VALUE;
            
            for (int start = 0; start < n; start++) {
                for (int end = start; end < n; end++) {
                    long[] sub = new long[end - start + 1];
                    for (int i = 0; i < sub.length; i++) {
                        sub[i] = runes[start + i];
                    }
                    
                    for (int i = 0; i < sub.length; i++) {
                        long leftNeighbor = 0;
                        boolean canAbsorb = false;
                        
                        if (i == 0 && start > 0) {
                            leftNeighbor = runes[start - 1];
                            canAbsorb = true;
                        } else if (i > 0) {
                            leftNeighbor = sub[i - 1];
                            canAbsorb = true;
                        }
                        
                        if (canAbsorb && sub[i] > leftNeighbor) {
                            sub[i] += leftNeighbor;
                            if (i > 0) sub[i - 1] = 0;
                        }
                    }
                    
                    long sum = 0;
                    for (long x : sub) sum += x;
                    maxPower = Math.max(maxPower, sum);
                }
            }
            
            System.out.println(maxPower);
        }
        sc.close();
    }
}
