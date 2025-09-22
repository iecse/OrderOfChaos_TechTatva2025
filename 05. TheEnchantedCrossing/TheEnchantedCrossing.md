# The Enchanted Crossing  

## Difficulty: Easy  

In the enchanted forest of **Jaadoo Nagar**, there is a magical bridge made of tiles.  
Each tile has a **capacity** (an integer), and each traveler has a **weight**.  

The bridge works as follows:  
- A traveler can step on a tile if their weight ≤ tile’s current capacity.  
- After stepping, the tile’s capacity decreases by the traveler’s weight (but not below 0).  
- If the traveler cannot step on the current tile, they must try the next one.  
- Travelers cross **in order**, always choosing the **leftmost tile** that can hold them.  

**Task:** For each test case, given `tiles` and `travelers`, output how many travelers successfully cross the bridge.  

## Input  
- First line: integer `t` (1 ≤ t ≤ 10), the number of test cases.  
- For each test case:  
  - First line: two integers `n` and `m` (1 ≤ n, m ≤ 10^5).  
  - Second line: `n` integers `tiles[i]` (1 ≤ tiles[i] ≤ 10^9).  
  - Third line: `m` integers `travelers[j]` (1 ≤ travelers[j] ≤ 10^9).  


## Output  
For each test case, print a single integer — the number of travelers who cross the bridge.  

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
- Traveler 1 (weight 4) steps on tile 1 - capacity becomes 1  
- Traveler 2 (weight 2) skips tile 1, steps on tile 2 - capacity becomes 8  
- Traveler 3 (weight 7) steps on tile 2 - capacity becomes 1  
- Traveler 4 (weight 1) skips tile 1, steps on tile 2 - capacity becomes 0  
  All 4 cross  

**Test case 2:**  
- Traveler 1 (weight 4) - cannot step on any tile - fails  
- Traveler 2 (weight 2) - steps on tile 1 - capacity becomes 1  
- Traveler 3 (weight 2) - skips tile 1, steps on tile 2 - capacity becomes 1  
  2 travelers cross
 
## Constraints
- 1 ≤ n, m ≤ 10^5  
- 1 ≤ tiles[i] ≤ 10^9  
- 1 ≤ travelers[j] ≤ 10^9  
- The sum of `n + m` across all test cases does not exceed **2 × 10^5**  
- Expected time complexity: **O(n + m)** per test case  
