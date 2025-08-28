# Arcane Purge

**Question Difficulty: Medium**

## Description:

In the enchanted kingdom of **Eldoria**, Archmage Kaelen is tasked with cleansing the world of cursed relics scattered across the land. Each relic hums with unstable magic, measured by its **arcane weight**.  

To purify the world, Kaelen must destroy all relics one by one. But destroying relics comes at a price:  

- If a relic’s **arcane weight** is **greater than the sacred limit** `C`, Kaelen must expend **1 mana crystal** to shatter it.  
- Otherwise, the relic collapses freely without consuming any mana.  

Yet, the realm’s chaotic magic brings a terrible curse — **with every passing second, the power of all remaining relics doubles**. This makes waiting dangerous, as weak relics may grow beyond the sacred limit if left unchecked.  

Kaelen seeks your guidance: what is the **minimum number of mana crystals** he must spend to completely purge all relics?  

---

## Input:

The first line contains a single integer `t` (1 ≤ t ≤ 1000) — the number of cursed relic collections to be purified.  

For each relic collection:  

- The first line contains two integers `n` and `C` (1 ≤ n ≤ 30, 1 ≤ C ≤ 10⁹) — the number of relics and the sacred limit.  
- The second line contains `n` integers `a₁, a₂, …, aₙ` (1 ≤ aᵢ ≤ 10⁹) — the initial arcane weight of each relic.  

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

## Sample Explanation:

**Test Case 1:**  
Relics: `[10, 4, 15, 1, 8]`  
- Destroy relic with weight `10` freely (`10 ≤ 10`).  
- Destroy relic with weight `8` freely (`8 ≤ 10`).  
- Later, `32` becomes too strong (`> 10`), costing 1 mana crystal.  
- Finally, `240` also costs 1 mana crystal.  
Total = **2 mana crystals**.  

**Test Case 2:**  
Every relic’s weight (`10⁹`) is greater than the limit `42`, so **each one costs 1 mana crystal**.  
Total = **3 mana crystals**.  

---
~ <a href=https://github.com/r1shu-R> Rishabh </a>