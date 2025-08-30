# Mystic Rune Fusion

## Question Difficulty: Medium

In the magical land of Naaglok Dham, a wizard has discovered a row of **mystic runes**, each with an integer power.  

To perform a **powerful spell**, the wizard can select a **contiguous subarray** of runes and perform **rune fusion**. The fusion rules are:

- Each rune in the selected subarray can **absorb the power of its immediate left neighbor** **once**, but only if it is **strictly greater than the neighbor**.  
- Absorption happens **from left to right**, **inside the chosen subarray**.  
- After absorption, the **new power of a rune** is used for further fusions to its right.  

The wizard wants to determine the **maximum total power** achievable from any contiguous subarray **after performing all possible fusions**.


## Input

- The first line contains an integer `t` - the number of test cases.  
- For each test case:
  - The first line contains an integer `n` — the number of runes.  
  - The second line contains `n` space-separated integers `runes[i]`, representing the power of each rune.

### Example Input
```
2
5
1 3 2 5 4
4
4 1 2 3
```

## Output

- A single integer: the **maximum total power** obtainable from any contiguous subarray after fusion.

### Example Output 
```
15
10
```
### Explanation

**Test case 1:**  
- Consider the subarray `[3, 2, 5, 4]`:  
  - Step 1: `3` absorbs `1` - becomes `4`  
  - Step 2: `2` cannot absorb `3` - stays `2`  
  - Step 3: `5` absorbs `2` - becomes `7`  
  - Step 4: `4` cannot absorb `5` - stays `4`  
- Total power of subarray = `4 + 2 + 7 + 4 = 17`  
- Maximum power achievable for any subarray = **15**.

**Test case 2:**  
- Choosing the subarray `[4,1,2,3]` - after applying fusion rules, total = **10**.

## Constraints

- `2 ≤ n ≤ 2 * 10^5`  
- `-10^4 ≤ runes[i] ≤ 10^4`  
- Time complexity requirement: **O(n)** or **O(n log n)**
