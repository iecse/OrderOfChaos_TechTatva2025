import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt(); 

        while (t-- > 0) {
            int n = sc.nextInt();
            long[] A = new long[n];
            long[] B = new long[n];

            for (int i = 0; i < n; i++) A[i] = sc.nextLong();
            for (int i = 0; i < n; i++) B[i] = sc.nextLong();

            System.out.println(maxZeroes(A, B));
        }

        sc.close();
    }

    static int maxZeroes(long[] A, long[] B) {
        Map<String, Integer> countMap = new HashMap<>();
        int alwaysZero = 0;
        int maxSameD = 0;  

        for (int i = 0; i < A.length; i++) {
            if (A[i] == 0) {
                if (B[i] == 0) {
                    alwaysZero++; 
                }
            } else {
                long numerator = -B[i];
                long denominator = A[i];
                long gcd = gcd(numerator, denominator);
                numerator /= gcd;
                denominator /= gcd;

                if (denominator < 0) {
                    numerator = -numerator;
                    denominator = -denominator;
                }

                String key = numerator + "/" + denominator;
                countMap.put(key, countMap.getOrDefault(key, 0) + 1);
                maxSameD = Math.max(maxSameD, countMap.get(key));
            }
        }
        return maxSameD + alwaysZero;
    }
    static long gcd(long a, long b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
}
