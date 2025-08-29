class SummitOfEldoria {
    public int[] findPeakGrid(int[][] heights) {
        int rows = heights.length;
        int cols = heights[0].length;

        int lowCol = 0;
        int highCol = cols - 1;

        while (lowCol <= highCol) {
            int midCol = lowCol + (highCol - lowCol) / 2;
            int maxRow = 0;

            for (int i = 0; i < rows; i++) {
                if (heights[i][midCol] > heights[maxRow][midCol]) {
                    maxRow = i;
                }
            }

            int currentVal = heights[maxRow][midCol];
            int leftVal = (midCol > 0) ? heights[maxRow][midCol - 1] : Integer.MIN_VALUE;
            int rightVal = (midCol < cols - 1) ? heights[maxRow][midCol + 1] : Integer.MIN_VALUE;
            int upVal = (maxRow > 0) ? heights[maxRow - 1][midCol] : Integer.MIN_VALUE;
            int downVal = (maxRow < rows - 1) ? heights[maxRow + 1][midCol] : Integer.MIN_VALUE;

            if (currentVal > leftVal && currentVal > rightVal 
                && currentVal > upVal && currentVal > downVal) {
                return new int[]{maxRow, midCol};
            }

            if (midCol > 0 && leftVal > currentVal) {
                highCol = midCol - 1;
            } else {
                lowCol = midCol + 1;
            }
        }
        return new int[]{-1, -1};
    }
}
