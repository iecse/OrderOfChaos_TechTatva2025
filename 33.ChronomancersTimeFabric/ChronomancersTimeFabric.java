import java.util.LinkedList;
import java.util.Queue;

public class ChronomancersTimeFabric{

    public static int getTimeToCorrupt(int[][] grid) {
        if (grid == null || grid.length == 0) {
            return 0;
        }

        int rows = grid.length;
        int cols = grid[0].length;
        Queue<int[]> queue = new LinkedList<>();
        int stableCount = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1) {
                    queue.offer(new int[]{r, c});
                } else if (grid[r][c] == 0) {
                    stableCount++;
                }
            }
        }

        if (stableCount == 0) {
            return 0;
        }

        int ticks = 0;
        int[][] directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (!queue.isEmpty() && stableCount > 0) {
            int levelSize = queue.size();
            for (int i = 0; i < levelSize; i++) {
                int[] current = queue.poll();
                int r = current[0];
                int c = current[1];

                for (int[] dir : directions) {
                    int newR = r + dir[0];
                    int newC = c + dir[1];

                    if (newR >= 0 && newR < rows && newC >= 0 && newC < cols && grid[newR][newC] == 0) {
                        grid[newR][newC] = 1;
                        queue.offer(new int[]{newR, newC});
                        stableCount--;
                    }
                }
            }
            ticks++;
        }

        return stableCount == 0 ? ticks : -1;
    }
}