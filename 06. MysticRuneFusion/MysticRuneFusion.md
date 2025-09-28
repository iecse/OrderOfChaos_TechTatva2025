# Mystic Rune Fusion  

## Difficulty: Medium  

In the land of **Naaglok Dham**, there is a row of **mystic runes**, each having an integer power.  

To cast a spell, the wizard can choose a **contiguous subarray** of runes and perform **rune fusion**.  

Fusion works as follows:  
- Within the chosen subarray, process runes from **left to right**.  
- A rune can **absorb the power of its immediate left neighbor once**, but **only if its power is strictly greater** than that neighbor.  
- When absorption happens:  
  - The absorbing rune’s power increases by the neighbor’s power.  
  - The neighbor’s power becomes **0** (its energy is transferred).  
- The updated power is then used for further fusions to the right.  

The goal is to find the **maximum total power** of any contiguous subarray after applying all possible fusions.  


## Input  
- First line: integer `t` — number of test cases.  
- For each test case:  
  - First line: integer `n` — number of runes.  
  - Second line: `n` space-separated integers `runes[i]` — the power of each rune.  


## Output  
For each test case, print a single integer — the **maximum total power** obtainable.  


## Example  

### Input  
```
2
5
1 3 2 5 4
4
4 1 2 3
```
### Output 
```
15
10
```


## Explanation  

**Test case 1:**  
Choose subarray `[1, 3, 2, 5, 4]`:  
- Rune `3` absorbs `1` - `[0, 4, 2, 5, 4]`  
- Rune `2` cannot absorb `4` - `[0, 4, 2, 5, 4]`  
- Rune `5` absorbs `2` - `[0, 4, 0, 7, 4]`  
- Rune `4` cannot absorb `7` - `[0, 4, 0, 7, 4]`  
Total = `15` (maximum possible).  

**Test case 2:**  
Choose `[4, 1, 2, 3]`:  
- Rune `1` cannot absorb `4`.  
- Rune `2` absorbs `1` - `[4, 0, 3, 3]`  
- Rune `3` absorbs `3`? No, must be strictly greater.  
Total = `10`.  

## Constraints  
- 1 ≤ n ≤ 10^5  
- −10^4 ≤ runes[i] ≤ 10^4  
- Expected complexity: O(n) or O(n log n)  
