
# The Kingdom of Pataal Lok

## Question Difficulty: Easy


In the Kingdom of **Pataal Lok**, two enchanted scrolls of numbers exist:  
- The **Golden Scroll** (`nums1`)  
- The **Silver Scroll** (`nums2`)  

Each scroll contains **sorted magical numbers**. 

The Golden Scroll is powerful — it has enough empty slots (marked with `0`s) at the end to store all runes from both scrolls combined.  

---

## The Spell of Unification
The Great Wizard must **merge** the Silver Scroll into the Golden Scroll such that:  
- After the ritual, the Golden Scroll contains **all runes from both scrolls**.  
- The runes must be arranged in **ascending magical order**. 
- The Silver Scroll vanishes after merging — all its power flows into the Golden one.

---

## Input
- `nums1` → the Golden Scroll (an array of length `m + n`, with the first `m` runes filled and the last `n` slots empty).  
- `m` → the number of actual runes currently in the Golden Scroll.  
- `nums2` → the Silver Scroll (an array of length `n`).  
- `n` → the number of runes in the Silver Scroll.  

---

## Output
Transform the Golden Scroll (`nums1`) so that it holds **all runes** in sorted order, with the Silver Scroll’s runes properly infused.  

---

## Example
**Input:**

nums1 = `[1,2,3,0,0,0]`, m = `3`

nums2 = `[2,5,6]`, n = `3`


**Output:**
nums1 = `[1,2,2,3,5,6]`



---
~ <a href=https://github.com/r1shu-R> Rishabh </a>