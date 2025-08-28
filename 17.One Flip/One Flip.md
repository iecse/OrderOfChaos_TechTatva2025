# Problem: Longest Uniform Subarray After One Flip  

**Difficulty:** Medium  

You are given a binary array `nums`.  

You are allowed to **flip exactly one bit** in the array (change a `0` to `1` or a `1` to `0`).  

Return the length of the **longest contiguous subarray** consisting only of equal elements (all 0’s or all 1’s) after the flip.  

---

## Example 1  

**Input:**  
`nums = [1,1,0,1]`  

**Output:**  
`4`  

**Explanation:**  
- Flip the `0` → `[1,1,1,1]`.  
- The entire array becomes 4 ones. ✅  

---

## Example 2  

**Input:**  
`nums = [0,1,1,0,0,1]`  

**Output:**  
`4`  

**Explanation:**  
- If you flip the `1` at position 2 → `[0,0,1,0,0,1]`, longest = 3 zeros.  
- If you flip the `1` at position 5 → `[0,1,1,0,1,1]`, longest = 3 ones.  
- If you flip the `0` at position 3 → `[0,1,1,1,0,1]`, longest = 3 ones.  
Best possible = 4 (zeros from indices 3–6). ✅  

---

## Example 3  

**Input:**  
`nums = [0,0,0]`  

**Output:**  
`3`  

**Explanation:**  
Flip any `0` → `[0,0,1]` (or similar), longest zeros = 3.  

---

## Constraints  

- `1 <= nums.length <= 10^5`  
- `nums[i] ∈ {0,1}`  
