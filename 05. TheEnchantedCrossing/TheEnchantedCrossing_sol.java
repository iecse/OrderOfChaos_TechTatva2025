import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt(); 
        
        while (t-- > 0) {
            int n = sc.nextInt(); 
            int m = sc.nextInt(); 
            
            long[] tiles = new long[n];
            long[] travelers = new long[m];
            
            for (int i = 0; i < n; i++) {
                tiles[i] = sc.nextLong();
            }
            for (int j = 0; j < m; j++) {
                travelers[j] = sc.nextLong();
            }
            
            int successful = 0; 
            int tileIndex = 0;  
            for (int j = 0; j < m; j++) {
                long weight = travelers[j];
                    while (tileIndex < n && tiles[tileIndex] < weight) {
                    tileIndex++;
                }
                if (tileIndex == n) break;
                tiles[tileIndex] -= weight;
                successful++; 
            }
            System.out.println(successful);
        }
        sc.close();
    }
}
