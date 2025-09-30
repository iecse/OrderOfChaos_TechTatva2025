# Magical Potion Mixing

## Question difficulty - Easy

In the enchanted kingdom of Rahasvan, gems hold mystical powers.  
Tantrika, a young sorceress, is collecting magical gems lined up in a row. Each gem has an integer power value.  

Tantrika wants to select a **contiguous subarray** of gems to maximize her magical energy. However, a curse applies:

- She **cannot include two identical gems consecutively** in her chosen subarray.  
- If two consecutive gems have the same power, she must **skip one of them** while forming the subarray.  

Your task is to determine the **maximum magical energy** Tantrika can obtain.

- The subarray must remain **contiguous** after skipping duplicates.  
- You cannot remove elements freely, only **skip consecutive duplicates** while summing.  

## Input

- The first line contains an integer `t` — the number of test cases.  
- For each test case:
  - The first line contains an integer `n` — the number of gems.  
  - The second line contains `n` space-separated integers `gems[i]`, representing the magical power of each gem. 

### Example Input
```
3
7
3 5 5 2 6 2 4
5
1 2 3 4 5
4
7 7 7 3
```

## Output

- A single integer: the maximum sum of powers in any valid subarray.  

### Example Output
```
22
15
10
```
### Explanation
**Test case 1:**  
Skip the second `5`. Valid subarray - `[3, 5, 2, 6, 2, 4]` - sum = 22.  

**Test case 2:**  
All gems are unique, so take the entire array - sum = 15.  

**Test case 3:**  
Tantrika can only take **one `7`** from the consecutive sequence of `7`s, then take the `3`.  

## Constraints

- $`2 ≤ n ≤ 2 * 10^5`$ 
- $`1 ≤ gems[i] ≤ 10^9`$  
- Time complexity requirement: **O(n)**  
