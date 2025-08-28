# Runes of Equilibrium
## Question Difficulty: Medium

### Description:
Deep inside the **Obsidian Library**, you discover a row of **ancient runes**, each glowing with an integer value.  
A ritual can only be performed if the runes are split into **two continuous groups** such that:  

- The **sum of the left group** equals the **sum of the right group**.  
- Both groups contain at least one rune.  

However, the runes are unstable: you are allowed to **remove at most one rune** anywhere in the sequence to make the ritual possible.  

Your task is to determine whether the ritual can be performed.  

---

### Input:
The first line contains a single integer `t` (1 ≤ t ≤ 10^5) — the number of rune sequences to analyze.  

For each sequence:  
- The first line contains an integer `n` (2 ≤ n ≤ 2×10^5) — the number of runes.  
- The second line contains `n` space-separated integers `R₁, R₂, ..., Rₙ` (−10^4 ≤ Rᵢ ≤ 10^4) — the rune energies.  

---

### Output:
For each rune sequence, output `"YES"` if the ritual can be performed, otherwise `"NO"`.  

---

### Constraints
- Number of test cases: 1 ≤ t ≤ 10^5  
- Runes per sequence: 2 ≤ n ≤ 2×10^5  
- Rune values: −10^4 ≤ Rᵢ ≤ 10^4  
- Total number of runes across all test cases ≤ 4×10^5  

---

### Examples

#### Example 1
**Input**

1

4

1 1 1 1

**Output**
YES

**Explanation**  
Already possible without removal: split `[1,1]` and `[1,1]`.  

---

#### Example 2
**Input**

1

5

2 3 5 2 2

**Output**
NO


**Explanation**  
No matter which rune is removed, no valid continuous split with equal sums exists.  

---

#### Example 3
**Input**

1

6

4 1 2 2 1 5

**Output**
NO


**Explanation**  
Even after removing one rune, there is no way to split into two equal halves.  

---

#### Example 4
**Input**

1

3

10 5 5

**Output**
YES

**Explanation**  
Split `[10]` and `[5,5]` → both sums equal 10.  

---

### *Question designed by Kushal [rkushell](https://github.com/rkushell)*
