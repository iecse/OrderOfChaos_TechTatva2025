## The Celestial Forge: Lyra's Crystal Blade

In a realm where magic and artistry intertwine, the master blacksmith Lyra is forging a legendary **Celestial Blade**. The blade's core must be crafted from a single, contiguous segment of enchanted crystals, which are laid out in a row. Each crystal possesses a specific level of magical energy, represented by an integer.

To create a blade of immense power, the **sum of the magical energies** from the chosen crystal segment must meet or exceed a required threshold, `K`.

However, the forging process is a delicate dance of power. The stability of the forge is paramount, and it is threatened by fluctuations in magic. The **instability** of a chosen segment is defined as the **maximum absolute difference** between the magical energies of any two adjacent crystals within it. A segment with only one crystal is perfectly stable, having an instability of `0`.

Lyra seeks to forge a blade that is not only powerful but also perfectly stable. Your quest is to help her find a contiguous segment of crystals that meets the energy requirement `K` while having the **minimum possible instability**.

-----

## Input Format

The first line consists of number of test cases.

For each test case:
1. The first line contains an integer **`n`** ($1 \le n \le 10^5$) and a long long integer **`K`** ($1 \le K \le 10^{14}$) — the number of crystals and the required energy threshold.  
2. The second line contains `n` space-separated integers $C_1, C_2, \dots, C_n$ ($1 \le C_i \le 10^9$) — the energy of each crystal.  

The sum of **`n`** over all test cases will not exceed $10^5$.

-----

## Output Format

For each test case, print a single integer on a new line representing the **minimum possible instability**. If no segment of crystals can meet the energy requirement `K`, print `-1`.

-----

## Example

**Input**

```
1
5 20
8 3 10 1 9
```

**Output**

```
7
```

**Explanation**
We must find a contiguous subarray with a sum of at least `20`. Let's examine the valid options:

  * **Subarray `[8, 3, 10]`**:

      * Sum: `8 + 3 + 10 = 21` (≥ 20, valid).
      * Adjacent differences: `|8 - 3| = 5`, `|3 - 10| = 7`.
      * The maximum difference is `7`, so the **instability is 7**.

  * **Subarray `[10, 1, 9]`**:

      * Sum: `10 + 1 + 9 = 20` (≥ 20, valid).
      * Adjacent differences: `|10 - 1| = 9`, `|1 - 9| = 8`.
      * The maximum difference is `9`, so the **instability is 9**.

Comparing all valid subarrays, the minimum instability we can achieve is `7`.

-----

*Question designed by Kushal [rkushell](https://github.com/rkushell)*