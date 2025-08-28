# The Enchanted Arrays of Utopia

**Question Difficulty: Easy**

---

## Description

In the mystical kingdom of **Utopia**, even numbers are enchanted.  
Arrays of numbers are judged by the **Council of Magic Fashion**:

An array is called **fashionable** if:

**Min(a)**+**Max(a)** is **divisible by 2** — meaning their sum forms a perfect balance between **light** and **shadow**.

However, not every array is born fashionable. To make it acceptable to the council, you may perform a ritual:
- In one ritual, you can **remove a single element** from the array.  

Your task is to determine the **minimum number of rituals** required to make the array **fashionable**.

---

## Input

- The first line contains a single integer `t` (1 ≤ t ≤ 1000) — the number of test cases.  
- For each test case:  
  - The first line contains an integer `n` (1 ≤ n ≤ 50) — the size of the array.  
  - The second line contains `n` integers `a₁, a₂, …, aₙ` (1 ≤ aᵢ ≤ 50) — the magical values of the array.  

---

## Output

For each test case, output a single integer — the **minimum number of rituals** required to make the array fashionable.

---

## Example

**Input**
3
3
1 4 3
4
2 2 2 2
5
5 7 9 10 2

**Output**
1
0
0

---

## Explanation

- **Test Case 1:**  
  Array = `[1, 4, 3]`  
  min = 1, max = 4 → 5 (odd). Not fashionable.  
  Remove `4` → `[1, 3]` → 1 + 3 = 4 (even). Fashionable.  
  Minimum rituals = **1**

- **Test Case 2:**  
  Array = `[2, 2, 2, 2]`  
  min = max = 2 → 2 + 2 = 4 (even). Already fashionable.  
  Rituals = **0**

- **Test Case 3:**  
  Array = `[5, 7, 9, 10, 2]`  
  min = 2, max = 10 → 12 (even). Already fashionable.  
  Rituals = **0**

---
~ <a href=https://github.com/r1shu-R> Rishabh </a>