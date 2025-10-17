import java.util.*;
public class MagicalPotionMixing {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int[] gems = new int[n];
            for (int i = 0; i < n; i++) {
                gems[i] = sc.nextInt();
            }
            int total = 0;
            for (int i = 0; i < n; i++) {
                total += gems[i];
                while (i + 1 < n && gems[i + 1] == gems[i]) {
                    i++;
                }
            }
            System.out.println(total);
        }
        sc.close();
    }
}
