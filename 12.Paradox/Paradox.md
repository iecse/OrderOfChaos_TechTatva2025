## The Chronomancer's Paradox

You are a **Chronomancer**, a master of time, tasked with analyzing the **Great Timeline**. This timeline is a vast array of **aetherial energy readings**, one for each moment since the dawn of magic.

For each recorded moment `i`, your spell must determine how many moments must pass until a future moment `j` (where `j > i`) occurs with a **strictly stronger** aetherial reading.

Peering into the future from any given moment causes a "**Temporal Ripple**." A crude, brute-force technique would shatter the timeline itself. You must devise an elegant spell—an arcane technique that can derive all the answers by processing the entire timeline in a single, fluid pass, thus keeping temporal ripples to a minimum.

-----

### Input Format

The first line of each test case contains a single integer **`n`** ($1 \le n \le 5 \cdot 10^5$) — the number of moments in the timeline.

The second line of each test case contains `n` space-separated integers $r_1, r_2, \dots, r_n$ ($1 \le r_i \le 10^6$) — the aetherial energy readings.

The sum of **`n`** over all test cases will not exceed $5 \cdot 10^5$.

-----

### Output Format

For each test case, print a single line containing `n` space-separated integers. The `i`-th integer should be the number of moments one must wait from moment `i` to find the next moment with a strictly greater reading. If no such future moment exists, the wait time is `0`.

-----

### Example

**Input**

```
1
7
89 91 95 87 85 90 97
```

**Output**

```
1 1 4 2 1 1 0
```

-----

*Question designed by Kushal [rkushell](https://github.com/rkushell)*