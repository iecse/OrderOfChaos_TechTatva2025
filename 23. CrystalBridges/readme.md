# The Crystal Bridges  

**Question Difficulty: Medium**  

## Description:  

In the kingdom of **Lumora**, there are **n floating islands** connected by magical crystal bridges.  
Each bridge has a **stability value** (an integer). The higher the value, the more stable the bridge.  

Every day, the storm winds of Lumora weaken the bridges:  
- All bridges lose **1 stability point** at the end of the day.  
- If a bridge’s stability becomes **0**, it collapses forever.  

You are a traveler who must journey from **Island 1** to **Island n**.  
Each day, you may cross **at most one bridge** between two islands, but only if that bridge is still standing.  

You need to determine whether it is possible to reach **Island n** before all the required bridges collapse.  

---

## Input:  

The first line contains a single integer `t` (1 ≤ t ≤ 1000) — the number of test cases.  

For each test case:  
- The first line contains two integers `n` and `m` (2 ≤ n ≤ 100, 1 ≤ m ≤ n·(n−1)/2) — the number of islands and bridges.  
- The next `m` lines each contain three integers `u`, `v`, `s` (1 ≤ u, v ≤ n, 1 ≤ s ≤ 100), meaning there is a bridge between island `u` and island `v` with stability `s`.  

---

## Output:  

For each test case, print **YES** if you can reach Island `n` starting from Island `1` before the required bridges collapse, otherwise print **NO**.  

---

## Example:  

### Input:
```
2
4 4
1 2 3
2 3 2
3 4 2
1 4 1
3 2
1 2 1
2 3 1
```

### Output:
YES <br>
NO


---

## Sample Explanation:  

**Test Case 1:**  
- Path: `1 → 2 → 3 → 4`.  
  - Day 1: Cross `1–2` (stability 3 → 2 left for later).  
  - Day 2: Cross `2–3` (stability 2 → 1 left).  
  - Day 3: Cross `3–4` (stability 2 → 1 left).  
You safely reach island `4` → **YES**.  

**Test Case 2:**  
- Bridges have stability 1.  
- You can only cross one bridge per day.  
- By the time you need the second bridge, it has already collapsed.  
So the answer is **NO**.  

---
~ <a href=https://github.com/r1shu-R> Rishabh </a>