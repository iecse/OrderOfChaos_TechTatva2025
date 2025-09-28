
# The Kingdom of Pataal Lok

## Question Difficulty: Easy


In the **Kingdom of Pataal Lok**, two enchanted scrolls exist:

The Golden Scroll (nums1)

The Silver Scroll (nums2)

Both scrolls contain sorted magical numbers. The Golden Scroll is special — it has enough empty slots (marked as 0s) to hold all numbers after merging.

## The Spell of Unification

The task is to merge the Silver Scroll into the Golden Scroll such that:

The final Golden Scroll contains all numbers in ascending order.

The Silver Scroll disappears after merging.


## Input

The first line contains a single integer t — the number of testcases.

- `nums1` → the Golden Scroll (an array of length `m + n`, with the first `m` runes filled and the last `n` slots empty).  
- `m` → the number of actual runes currently in the Golden Scroll.  
- `nums2` → the Silver Scroll (an array of length `n`).  
- `n` → the number of runes in the Silver Scroll.  

---

## Constraints

- `1 <= t <= 10^5`
- `nums1.length == m + n`  
- `nums2.length == n`  
- `0 <= m, n <= 200`  
- `1 <= m + n <= 200`  
- `-10^9 <= nums1[i], nums2[j] <= 10^9`  

---

## Output

Transform the Golden Scroll (`nums1`) so that it holds **all runes** in sorted order, with the Silver Scroll’s runes properly infused.  

---

## Example

**Input:**

```
3
3 3
1 2 3 0 0 0
2 5 6
2 2
1 5 0 0
2 4
4 1
1 2 3 4 0
5
```

**Output:**
```
1 2 2 3 5 6
1 2 4 5
1 2 3 4 5
```

---
~ <a href=https://github.com/r1shu-R> Rishabh </a>