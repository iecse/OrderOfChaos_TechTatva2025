#  Magical Gem Quest
## Difficulty - Hard

A young wizard is exploring an enchanted **n x n grid of mystical gems**. Each cell in the grid can be one of three types:

- `0` → an **empty tile**, which the wizard can safely pass through.  
- `1` → a **magical gem** that the wizard can collect. Once collected, the cell becomes empty (`0`).  
- `-1` → a **cursed thorn**, which blocks the wizard’s path.  

The wizard wants to collect the **maximum number of gems** by following these rules:

1. Start at the top-left corner `(0, 0)` and move to the bottom-right corner `(n - 1, n - 1)` by moving **right** or **down** only through valid tiles (`0` or `1`).  
2. After reaching `(n - 1, n - 1)`, return to `(0, 0)` by moving **left** or **up** only through valid tiles.  
3. Each time the wizard passes through a tile containing a gem (`1`), the gem is **collected**, and the cell becomes empty (`0`).  
4. If there is **no valid path** from `(0, 0)` to `(n - 1, n - 1)`, the wizard cannot collect any gems.  

Return the **maximum number of gems** the wizard can collect on this round trip.


## Input
- First line: integer `T` — number of test cases.  
- For each test case:  
  1. First line: integer `n` — the size of the grid.  
  2. Next `n` lines: `n` space-separated integers each (`-1`, `0`, or `1`) representing the grid.

## Output Format
- For each test case, print a single integer — the **maximum number of gems** the wizard can collect.


### Constraints
- `1 <= T <= 10`  
- `1 <= n <= 50`  
- `grid[i][j]` is `-1`, `0`, or `1`  
- `grid[0][0] != -1`  
- `grid[n - 1][n - 1] != -1`  


## Example 1

**Input**  
```
1
3
0 1 -1
1 0 -1
1 1 1
```

**Output**
```
5
```


**Explanation**  
- The wizard starts at `(0, 0)` and moves **down, down, right, right** to reach `(2, 2)`.  
- Picks up **4 gems** during this trip, making the grid:  
```
[[0,1,-1],
[0,0,-1],
[0,0,0]]
```

- On the way back, the wizard moves **left, up, up, left**, collecting **1 more gem**.  
- Total gems collected = `5`.


## Example 2

**Input**  
```
1
3
1 1 -1
1 -1 1
-1 1 1
```

**Output**
```
0
```

**Explanation**  
- There is **no valid path** from `(0, 0)` to `(2, 2)`.  
- Wizard cannot collect any gems, so the result is `0`.
