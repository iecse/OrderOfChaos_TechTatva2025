# The Enchanted Crossing

## Question Difficulty: Easy

In the enchanted forest of **Sylvara**, there is a **bridge made of magical tiles** that stretches over a chasm. Each tile has a **weight capacity**, represented by an integer.  

A group of **travelers** must cross the bridge. Each traveler has a **weight**. The bridge has a peculiar property:

- A traveler can step on a tile if their weight is **less than or equal to the tile's current capacity**.  
- **After stepping on a tile**, the tile’s capacity **reduces by the traveler’s weight** (but it cannot go below 0).  
- **If a traveler cannot step on a tile**, they must **skip it and move to the next tile**.  

The travelers must cross **in order**, stepping on the **leftmost tile possible** that can hold them.  

**Task:** For each test case, given arrays `tiles` (tile capacities) and `travelers` (weights), output the number of travelers who successfully cross the bridge.  


## Input
- The first line contains a single integer `t` (1 ≤ t ≤ 10) — the number of test cases.  
- For each test case:  
  - The first line contains two integers `n` and `m` (1 ≤ n, m ≤ 10^5).  
  - The second line contains `n` integers `tiles[i]` (1 ≤ tiles[i] ≤ 10^9).  
  - The third line contains `m` integers `travelers[j]` (1 ≤ travelers[j] ≤ 10^9).

### Example Input
```
2
3 4
5 10 3
4 2 7 1
2 3
3 3
4 2 2
```

### Output
- For each test case, output a single integer — the number of travelers who successfully cross the bridge.

### Example Output
```
4
2
```

### Explanation
**Test case 1:**  
- Traveler 1 (weight 4) steps on tile 1 → capacity becomes 1  
- Traveler 2 (weight 2) skips tile 1, steps on tile 2 → capacity becomes 8  
- Traveler 3 (weight 7) steps on tile 2 → capacity becomes 1  
- Traveler 4 (weight 1) skips tile 1, steps on tile 2 → capacity becomes 0  
  All 4 cross  

**Test case 2:**  
- Traveler 1 (weight 4) → cannot step on any tile → fails  
- Traveler 2 (weight 2) → steps on tile 1 → capacity becomes 1  
- Traveler 3 (weight 2) → skips tile 1, steps on tile 2 → capacity becomes 1  
  2 travelers cross
 
## Constraints
- 1 ≤ n, m ≤ 10^5  
- 1 ≤ tiles[i] ≤ 10^9  
- 1 ≤ travelers[j] ≤ 10^9  
- The sum of `n + m` across all test cases does not exceed **2 × 10^5**  
- Expected time complexity: **O(n + m)** per test case  
