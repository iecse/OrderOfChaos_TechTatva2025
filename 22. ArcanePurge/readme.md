# Arcane Purge

**Question Difficulty: Medium**

## Description:


In Eldoria, there are **n cursed relics**, each with an arcane weight. Archmage Kaelen must destroy them one by one.

If a relic’s weight is greater than the sacred limit `C`, Kaelen must spend **1 mana crystal** to destroy it.

Otherwise, it can be destroyed freely.

After each second, all remaining relics **double** in weight.

Find the **minimum number** of mana crystals needed to destroy all relics. 


---

## Input:

The first line contains a single integer `t`  — the number of cursed relic collections to be purified.  

For each relic collection:  

- The first line contains two integers `n` and `C`  — the number of relics and the sacred limit.  
- The second line contains `n` integers `a₁, a₂, …, aₙ`  — the initial arcane weight of each relic.  

---

## Output:

For each collection, output a single integer — the minimum number of mana crystals Kaelen must spend to purge all relics.  

---

## Constraints:

- 1 ≤ t ≤ 1000  
- 1 ≤ n ≤ 30  
- 1 ≤ aᵢ ≤ 10⁹  
- 1 ≤ C ≤ 10⁹  

---

## Example:

### Input:
```
4
5 10
10 4 15 1 8
3 42
1000000000 1000000000 1000000000
10 30
29 25 2 12 15 42 14 6 16 9
10 1000000
1 1 1 1 1 1 1 1 1 864026633
```


### Output:
```
2
3
6
1
```



---
~ <a href=https://github.com/r1shu-R> Rishabh </a>