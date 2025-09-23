# Rain Water With Cursed Leaks

You are given two mystical arrays `height` and `leak` of length `n`:

- `height[i]` — the height of the stone pillar at position `i`.  
- `leak[i]` — whether the pillar is cursed with a leak rune (`0` = no curse, water stays; `1` = cursed, water seeps away)  

Rainwater may be captured **between taller pillars**, forming magical pools.However, if a pillar is**cursed**, then **o water can rest upon it**— the enchanted liquid drains away.  

Return the **total units of enchanted water** trapped after raining.  

---

## Input

- `height` → `vector<int>` of size `n` (stone pillars)
- `leak` → `vector<int>` of size `n` (curse runes) 

---

## Output

- Single integer — total units of **enchanted water** trapped

---

## Example 1

**Input:**  
```
height = [0,1,0,2,1,0,1,3,2,1,2,1];
leak   = [0,0,0,0,0,0,0,0,0,0,0,0];
```
**Onput:**
```
6
```
**Explanation:**  
- No pillars are cursed → the rain behaves like a **normal enchanted rainfall.**

- The water pools between the stone pillars, capturing **6 units of magic essence.**
## Example 2
**Input:**  
```
height = [0,1,0,2,1,0,1,3,2,1,2,1];
leak   = [0,0,1,0,0,0,0,0,0,0,0,0];
```
**Onput:**
```
5
```
**Explanation:**
- The pillar at index 2 is cursed with a **leak rune**.

- Any enchanted water above it seeps away into the void.

- The pools lose **1 unit of magic essence** → 6 → 5.