# The Lever of Jadoo Nagar

## Question Difficulty: Easy



In the mystical realm of **Jadoo Nagar**, two enchanted arrays of numbers exist:  

- The **Array of Flame** (`a`)  
- The **Array of Frost** (`b`)  

Both arrays contain exactly `n` numbers each.  

---

## The Ritual of the Lever

The magical Lever works in iterations:

If there exists an index i where `a[i] > b[i]`, reduce that rune `(a[i] = a[i] - 1)`.

If there exists an index i where `a[i] < b[i]`, increase that rune `(a[i] = a[i] + 1)`.

If in Step 1 no such index exists, the ritual ends.

The number of iterations is unique and does not depend on which indices are chosen.

---

## The Task

Given the two enchanted arrays `a` and `b`, determine the **exact number of iterations** the Lever will perform before its power fades.  

It is foretold that this number is **unique** and does not depend on which runes the Lever chooses in each step.

---

## Input
- The first line contains the number of test cases `t` (`1 ≤ t ≤ 10^4`).  
- For each test case:  
  - The first line contains an integer `n` (`1 ≤ n ≤ 10`).  
  - The second line contains `n` integers, the **Array of Flame** `a` (`1 ≤ a[i] ≤ 10`).  
  - The third line contains `n` integers, the **Array of Frost** `b` (`1 ≤ b[i] ≤ 10`).  

---

## Output
For each test case, return the **number of iterations** that the Lever performs before halting.  

## Example

**Input**  
```
2
3
5 2 3
2 2 4
4
1 5 3 2
2 2 3 5
```

**Output**  
```
3
3
```
---
~ <a href=https://github.com/r1shu-R> Rishabh </a>
