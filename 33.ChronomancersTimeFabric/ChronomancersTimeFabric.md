## The Chronomancer's Time Fabric

### Problem Statement

You are a **Chronomancer**, a guardian of the very fabric of time. This fabric is represented as a 2D grid of **Temporal Nexuses**. Each nexus can exist in one of three states:

  * **Stable (0):** A healthy, functioning point in time.
  * **Corrupted (1):** A nexus that has succumbed to a temporal anomaly. This corruption is contagious.
  * **Void (2):** An empty, impassable rift in the fabric. Corruption cannot enter or pass through a void nexus.

The temporal corruption spreads in discrete **ticks**. In a single tick, any stable nexus that is adjacent (up, down, left, or right) to a corrupted nexus will also become corrupted.

Your task is to predict the future. Given the initial state of the Time Fabric, determine the minimum number of ticks required for the corruption to spread to every single stable nexus. If there is at least one stable nexus that is permanently safe from the corruption (i.e., it can never be reached), then the timeline is considered salvageable.

### Input Format

  * The first line contains an integer $T$, the number of test cases.
  * The first line of each test case contains two space-separated integers, $R$ and $C$, representing the number of rows and columns in the Time Fabric grid.
  * The next $R$ lines each contain $C$ space-separated integers, describing the initial state of each nexus in the grid.

### Output Format

For each test case, print a single integer on a new line:

  * The minimum number of ticks required for all stable nexuses to become corrupted.
  * If it is impossible for all stable nexuses to be corrupted, print `-1`.
  * If there are no stable nexuses to begin with, print `0`.

### Constraints

  * $1 \le T \le 100$
  * $1 \le R, C \le 500$
  * The value of each nexus will be $0$, $1$, or $2$.
  * The sum of $R \times C$ over all test cases will not exceed $250,000$.

-----

### Sample Input 1

```
1
3 3
1 0 2
0 0 0
0 1 0
```

### Sample Output 1

```
2
```

### Explanation 1

  * **Tick 0:** The grid has two corruption sources at `(0,0)` and `(2,1)`.
  * **Tick 1:** The corruption spreads to adjacent stable nexuses. The nexuses at `(1,0)`, `(0,1)`, `(1,1)`, `(2,0)`, and `(2,2)` become corrupted. The nexus at `(0,2)` is a void and blocks the spread.
  * **Tick 2:** The newly corrupted nexus at `(1,1)` spreads its corruption to the last remaining stable nexus at `(1,2)`.
    After 2 ticks, all stable nexuses have been corrupted.

-----

### Sample Input 2

```
1
3 3
0 2 0
2 1 2
0 2 0
```

### Sample Output 2

```
-1
```

### Explanation 2

The initial corrupted nexus at `(1,1)` is completely surrounded by void nexuses. It cannot spread its corruption to any of the four stable nexuses, so they remain eternally safe. Thus, the output is `-1`.

-----

*Question designed by Kushal [rkushell](https://github.com/rkushell)*