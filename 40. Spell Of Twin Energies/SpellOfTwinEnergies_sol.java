import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();  

        while (t-- > 0) {
            long c = sc.nextLong();  
            System.out.println(canStabilize(c));
        }

        sc.close();
    }
    static boolean canStabilize(long c) {
        long spellA = 0;
        long spellB = (long) Math.sqrt(c);

        while (spellA <= spellB) {
            long totalPower = spellA * spellA + spellB * spellB;

            if (totalPower == c) {
                return true;   
            } else if (totalPower < c) {
                spellA++;        
            } else {
                spellB--;       
            }
        }

        return false;
    }
}
