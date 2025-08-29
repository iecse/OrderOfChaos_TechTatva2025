import java.util.*;

public class Main {
    static class WizardGemQuest {
        int[][][] memo;
        int[][] grid;
        int N;

        public int collectGems(int[][] grid) {
            this.grid = grid;
            N = grid.length;
            memo = new int[N][N][N];
            for (int[][] layer : memo) {
                for (int[] row : layer) Arrays.fill(row, Integer.MIN_VALUE);
            }
            return Math.max(0, dp(0, 0, 0));
        }

        private int dp(int r1, int c1, int c2) {
            int r2 = r1 + c1 - c2;
            if (r1 >= N || r2 >= N || c1 >= N || c2 >= N || grid[r1][c1] == -1 || grid[r2][c2] == -1)
                return -999999;
            if (r1 == N - 1 && c1 == N - 1)
                return grid[r1][c1];
            if (memo[r1][c1][c2] != Integer.MIN_VALUE)
                return memo[r1][c1][c2];

            int ans = grid[r1][c1];
            if (c1 != c2) ans += grid[r2][c2];

            int next = Math.max(Math.max(dp(r1, c1 + 1, c2 + 1), dp(r1 + 1, c1, c2 + 1)),
                                Math.max(dp(r1, c1 + 1, c2), dp(r1 + 1, c1, c2)));

            memo[r1][c1][c2] = ans + next;
            return memo[r1][c1][c2];
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();

        while (T-- > 0) {
            int n = sc.nextInt();
            int[][] grid = new int[n][n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    grid[i][j] = sc.nextInt();
                }
            }

            WizardGemQuest quest = new WizardGemQuest();
            int result = quest.collectGems(grid);
            System.out.println(result);
        }
    }
}
