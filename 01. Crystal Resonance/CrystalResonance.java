import java.util.*;

public class CrystalResonance {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();
            int[] powers = new int[n];

            for (int i = 0; i < n; i++) {
                powers[i] = sc.nextInt();
            }

            if (hasDuplicate(powers)) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }

        sc.close();
    }

    public static boolean hasDuplicate(int[] arr) {
        Set<Integer> seen = new HashSet<>();
        for (int power : arr) {
            if (seen.contains(power)) {
                return true;
            }
            seen.add(power);
        }
        return false;
    }

}