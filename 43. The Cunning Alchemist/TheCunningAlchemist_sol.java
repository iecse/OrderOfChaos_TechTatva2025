import java.util.*;
public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        List<Long> cost = new ArrayList<>();
        long c = 3;
        long cnt = 1;
        for (int i = 0; i < 21; i++) {
            cost.add(c);
            c = 3 * c + cnt;
            cnt *= 3;
        }
        int t = sc.nextInt();
        while (t-- > 0) {
            long n = sc.nextLong();
            long minCost = 0;

            int sz = 0;
            while (n > 0) {
                long rem = n % 3; 
                minCost += rem * cost.get(sz);
                n /= 3;
                sz++;
            }
            System.out.println(minCost);
        }
        sc.close();
    }
}
