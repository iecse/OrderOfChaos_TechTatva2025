#  Hidden Multiplication  

Artem thought of a **mystical number** `x`. To cloak it in mystery, he multiplied it by a **power of 10** (at least `10^1`), creating `y = x ⋅ 10^k`.  

Then, to further confuse everyone, he **added both numbers together**:  


You are given the final number `n`. Your task is to determine **all possible values of `x`** that Artem could have originally thought of.  
`Formula: n = x ⋅ (1 + 10^k)`

---

## Input  

- The first line contains a single integer `t` (`1 ≤ t ≤ 10^4`) — the number of test cases.  
- Each of the next `t` lines contains a single integer `n` (`11 ≤ n ≤ 10^18`).  

---

## Output  
For each test case:  
- Output `0` if no suitable `x` exists.  
- Otherwise, output the **number of possible `x` values**, followed by all valid values in **ascending order**.  

---

## Example  

**Input**  
---
```
2
121
1100
```
**Output**  
---
```
1 11
1 100
```
---
## Explanation  

For `n = 121`:  
- If `k = 1`, then `n = x ⋅ (1 + 10^1) = 11x`.  
  - `x = 121 / 11 = 11` (valid)  
- No other `k` divides `121`.  

For `n = 1100`:  
- If `k = 1`, denominator = `1 + 10^1 = 11`.  
  - `x = 1100 / 11 = 100` (valid)  
- Higher values of `k` don’t divide `1100`.  

Thus:  
- `121 → x = 11`  
- `1100 → x = 100`  

---
