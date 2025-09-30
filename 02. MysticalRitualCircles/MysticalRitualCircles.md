# Mystical Ritual Circles

**Question Difficulty: Medium**

## Problem

In the Whispering Citadel, Archmage Zara studies ancient ritual circles made of mystical nodes. Each node holds a certain energy level, and together they may form powerful _sacred pathways_.

A sacred pathway is simply a contiguous sequence of nodes (a subarray) that satisfies both of the following conditions:

1. The **total energy** of the pathway is exactly **s**.
2. The **strongest node** (maximum energy in that pathway) is exactly **p**.

If any node in the pathway has energy greater than **p**, the ritual collapses. If no node reaches **p**, the ritual is incomplete.

Your task is to help Zara count how many sacred pathways exist in each mystical formation.

---

## Input

- The first line contains an integer **t** (1 ≤ t ≤ 10⁴) — the number of mystical formations.
- For each formation:
  - The first line contains three integers **n, s, p**:
    - **n** — number of nodes (1 ≤ n ≤ 2×10⁵)
    - **s** — required total energy (−2×10¹⁴ ≤ s ≤ 2×10¹⁴)
    - **p** — required peak energy (−10⁹ ≤ p ≤ 10⁹)
  - The second line contains **n integers** `e₁, e₂, …, eₙ` (−10⁹ ≤ eᵢ ≤ 10⁹) — the energy of each node.

It is guaranteed that the total of all **n** across test cases does not exceed 2×10⁵.

---

## Constraints

- number of nodes (1 ≤ n ≤ 2×10⁵)
- required total energy (−2×10¹⁴ ≤ s ≤ 2×10¹⁴)
- required peak energy (−10⁹ ≤ p ≤ 10⁹)

---

## Output

For each formation, print a single integer: the number of sacred pathways (contiguous subsequences) that meet the conditions.

---

## Example

### Input

```
9
1 0 0
0
1 -2 -1
-2
3 -1 -1
-1 1 -1
6 -3 -2
-1 -1 -1 -2 -1 -1
8 3 2
2 2 -1 -2 3 -1 2 2
9 6 3
1 2 3 1 2 3 1 2 3
13 7 3
0 -1 3 3 3 -2 1 2 2 3 -1 0 3
2 -2 -1
-2 -1
2 -2 -1
-1 -2
```

### Output

```
1
0
2
0
2
7
8
0
0
```

---

_Question designed by [Abhyuday-Gupta912](https://github.com/Abhyuday-Gupta912)_
