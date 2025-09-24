# The Spell of Perfect Harmony

In the Realm of Binary Plains, an ancient path is paved with n glowing stones, each shining with either darkness (0) or light (1).

You possess a single spell of transformation:

- You may flip exactly one stone’s essence (turn 0 → 1 or 1 → 0).

Your quest is to determine the length of the longest continuous stretch of stones that radiate in perfect harmony (all glowing the same) after casting your spell.

---

## Input  
- The first line contains an integer t (1 ≤ t ≤ 10^4) — the number of trials.

- Each trial begins with an integer n (1 ≤ n ≤ 10^5) — the number of stones.

- The next line contains n integers a1, a2, …, an (ai ∈ {0,1}) — the glow of each stone.

It is guaranteed that the sum of n across all trials does not exceed 10^5.
## Output  
For each trial, output a single integer — the maximum length of a harmonious stretch possible after one transformation. 



## Examples  


**Input:**  

```
3
4
1 1 0 1
6
0 1 1 0 0 1
3
0 0 0
```
**Output:**  

```
4
4
3
```


