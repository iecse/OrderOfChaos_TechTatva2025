# A. Sort Towers (easy)

-Mahika
Alittle apprentice **Vasya the Young Builder** has received an enchanted builder’s kit from the Grand Mage. The kit consists of several **magic rods**, each imbued with a length that determines its power.

Two rods can be stacked into the same **Mystic Tower** if (and only if) their lengths are identical — the enchantments resonate only with rods of equal size.

Vasya’s task is to conjure the **fewest number of Mystic Towers**, while still using every rod he has.

Your mission: Help Vasya determine:

1. The **height of the tallest tower** he can build.  
2. The **total number of towers** after all rods are used.

---

## Input

- The first line contains an integer **N** (1 ≤ N ≤ 1000) — the number of magic rods.  
- The second line contains **N** space-separated integers `l₁, l₂, ..., lₙ` — the lengths of the rods.  
  Each `lᵢ` is a natural number not exceeding 1000.

---

## Output

Print two integers in a single line:

- The **height of the tallest Mystic Tower**.  
- The **total number of towers** Vasya builds.

---

## Constraints

- 1 ≤ N ≤ 1000  
- 1 ≤ lᵢ ≤ 1000  

---

## Example 1

**Input**
```
3
1 2 3
```

**Output**
```
1 3
```