# The Archon's Aetherium Attunement 
## Question Difficulty: Medium

### Description

In the celestial realm of **Eldoria**, a rare cosmic convergence is imminent. You are an **Archon**, master of arcane energies, tasked with a ritual of paramount importance: absorbing power from scattered **Aetherium Caches** to fortify the realm’s fading wards.

You have located `N` caches. The `i`-th cache contains `caches[i]` units of raw Aetherium.  
The ritual window lasts exactly **`H` Lunar Cycles**.

Your attunement strength is an integer **`k`** (the **Attunement Factor**). In a single Lunar Cycle you may focus on **one** cache and siphon **up to `k` units** from it. If a cache has `≤ k` units when you work on it, you completely drain and seal that cache in that cycle.

Your life force is finite; you must find the **minimum integer `k`** such that **all** caches can be fully drained within `H` cycles.

Return this faintest possible attunement factor.

---

### Input

This problem is presented in a function-style format. Your function receives:

- `int[] caches` — an array where `caches[i]` is the amount of Aetherium in the `i`-th cache.
- `long H` — the number of available Lunar Cycles.

---

### Output

Return a single integer — the **minimum integer `k`** such that all caches can be emptied within `H` Lunar Cycles when, in each cycle, you may work on **at most one** cache and siphon **up to `k`** units from it.

---

### Constraints

- `1 ≤ N = caches.length ≤ 10^4`  
- `1 ≤ caches[i] ≤ 10^9`  
- `1 ≤ H ≤ 10^9`

---

### Notes

- Draining a cache of size `x` with attunement `k` consumes exactly `ceil(x / k)` cycles (not necessarily consecutive), since you can only work on **one** cache per cycle.
- The total cycles required for a given `k` is `sum( ceil(caches[i] / k) )`.  
- The answer is monotonic in `k` (larger `k` never requires more cycles), which hints at a **binary search on `k`**.

---

### Examples from the Grimoire

#### Scroll 1
**Input**  
`caches = [3, 6, 7, 11]`, `H = 8`

**Output**  
`4`

**Explanation**  
Cycles needed with `k = 4`:
- `3 → ⌈3/4⌉ = 1`  
- `6 → ⌈6/4⌉ = 2`  
- `7 → ⌈7/4⌉ = 2`  
- `11 → ⌈11/4⌉ = 3`  
Total `= 1 + 2 + 2 + 3 = 8` cycles — exactly on time.  
With `k = 3`, total cycles would be `10` (> `H`), so `4` is minimal.

---

#### Scroll 2
**Input**  
`caches = [30, 11, 23, 4, 20]`, `H = 5`

**Output**  
`30`

**Explanation**  
With only `5` cycles for `5` caches, each cache must be finished in **one** cycle.  
Thus `k` must be at least the maximum cache size, `30`.

---

#### Scroll 3
**Input**  
`caches = [30, 11, 23, 4, 20]`, `H = 6`

**Output**  
`23`

**Explanation**  
With one extra cycle, the minimal `k` drops.  
`k = 23` yields total cycles `= ⌈30/23⌉ + ⌈11/23⌉ + ⌈23/23⌉ + ⌈4/23⌉ + ⌈20/23⌉ = 2 + 1 + 1 + 1 + 1 = 6`.  
No smaller `k` can meet the deadline.

---

### *Question designed by Kushal [rkushell](https://github.com/rkushell)*