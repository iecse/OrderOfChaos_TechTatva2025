# B. Hidden Multiplication

**time limit per test:** 1 second  
**memory limit per test:** 256 megabytes  

Artem thought of a number `x`. To make it harder to guess, he multiplied it by a power of 10 (at least `10^1`), obtaining a number `y = x ⋅ 10^k`.  

Then he added both numbers together and announced:  


You are given the final number `n`. Your task is to determine all possible values of `x` that Artem could have originally thought of.

---

## Input
- The first line contains a single integer `t` (`1 ≤ t ≤ 10^4`) — the number of test cases.  
- Each of the next `t` lines contains a single integer `n` (`11 ≤ n ≤ 10^18`).  

## Output
For each test case:  
- Output `0` if there are no suitable values of `x`.  
- Otherwise, output the number of suitable values of `x`, followed by all valid values in ascending order.  

---

## Example

**Input**  
```
121
1100
```

**Output**  

```
1 11
1 100
```

---

## Explanation

For `n = 121`:  
- If `k = 1`, then n = x ⋅ (1 + 10^1) = 11x
  
So `x = 121 / 11 = 11` is valid.   
- No other `k` works.  

For `n = 1100`:  
- If `k = 1`, then denominator = `1 + 10^1 = 11`.  
So `x = 100` is valid. 
- Higher values of `k` don’t divide `n`.  

---

👉 The problem reduces to checking divisors of the form `(1 + 10^k)` for `k ≥ 1` and seeing if they divide `n`.  
