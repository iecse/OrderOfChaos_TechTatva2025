# ⚔️ Longest Uniform Subarray After One Flip  

You are given a **binary array** `nums`.  

You possess a **single spell of transformation**: you may flip **exactly one bit** (turn `0 → 1` or `1 → 0`).  

Your quest: find the length of the **longest contiguous subarray** that contains only **one type of element** (all `0`s or all `1`s) after this magical flip.  

---

## 📥 Input  
- A binary array `nums`.  

---

## 📤 Output  
- The length of the longest uniform subarray possible after one flip.  

---

## 🌟 Examples  

### Example 1  
**Input:**  
---
```
nums = [1,1,0,1]
```
**Output:**  
---
```
4
```
---

**Explanation:**  
- Flip the `0` → `[1,1,1,1]`.  
- Entire array becomes length `4`. ✅  

---

### Example 2  
**Input:**  
---
```
nums = [0,1,1,0,0,1]
```
**Output:**  
---
```
4
```
---
**Explanation:**  
- Flip different positions:  
  - Flip `1` → longest = 3 zeros.  
  - Flip another `1` → longest = 3 ones.  
  - Flip middle `0` → longest = 3 ones.  
- Best possible = subarray of `4` zeros (indices 3–6). ✅  

---
### Example 3  
**Input:**  
---
```
nums = [0,0,0]
```
**Output:** 
```
3
```
---
**Explanation:**  
- Flip any `0`.  
- Still max uniform subarray length = 3.  

---

## ⚖️ Constraints  
- `1 ≤ nums.length ≤ 10^5`  
- `nums[i] ∈ {0,1}`  

---