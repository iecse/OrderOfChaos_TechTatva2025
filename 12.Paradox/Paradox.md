# The Chronomancer's Paradox
## Question Difficulty: Medium

### Description

You are a **Chronomancer**, a master of time, tasked with analyzing the **Great Timeline**. This timeline is a vast array of **aetherial energy readings**, one for each moment since the dawn of magic.

For each recorded moment `i`, your spell must determine how many moments must pass until a future moment `j` (where `j > i`) occurs with a **strictly stronger** aetherial reading.

Peering into the future from any given moment causes a "**Temporal Ripple**." A crude, brute-force technique of scanning forward from each point would accumulate into a paradox, shattering the timeline itself. You must devise a more elegant spell—an arcane technique that can derive all the answers by processing the entire timeline in a **single, fluid pass**, thus keeping temporal ripples to a minimum.

---

### Input

This problem is presented in a function-style format. Your function receives:

- `int[] readings` — an array representing the aetherial energy at each moment in the timeline.

---

### Output

Return an array of integers of the same size, where the element at index `i` is the number of moments one must wait from moment `i` to find the next moment with a strictly greater reading. If no such future moment exists, the wait time is `0`.

---

### Constraints

- `1 ≤ readings.length ≤ 5 * 10^5`
- `1 ≤ readings[i] ≤ 10^6`

---

### Notes

- A brute-force solution with nested loops will be far too slow and result in a "Temporal Paradox" (Time Limit Exceeded).
- The "single, fluid pass" nature of an efficient solution strongly hints at using an auxiliary data structure like a **Monotonic Stack** to keep track of past moments waiting for a stronger future one.

---

### Examples from the Grimoire

#### A Glimpse into the Timeline
**Input**
`readings = [89, 91, 95, 87, 85, 90, 97]`

**Output**
`[1, 1, 4, 2, 1, 1, 0]`

**Explanation**
-   **Moment 0 (89):** Next moment (1) has reading 91 (> 89). Wait = `1 - 0 = 1`.
-   **Moment 1 (91):** Next moment (2) has reading 95 (> 91). Wait = `2 - 1 = 1`.
-   **Moment 2 (95):** We must wait until moment 6 for reading 97 (> 95). Wait = `6 - 2 = 4`.
-   **Moment 3 (87):** We must wait until moment 5 for reading 90 (> 87). Wait = `5 - 3 = 2`.
-   **Moment 4 (85):** Next moment (5) has reading 90 (> 85). Wait = `5 - 4 = 1`.
-   **Moment 5 (90):** Next moment (6) has reading 97 (> 90). Wait = `6 - 5 = 1`.
-   **Moment 6 (97):** No future moment is stronger. Wait = `0`.

---

#### The Fading Echo
**Input**
`readings = [100, 90, 80, 70]`

**Output**
`[0, 0, 0, 0]`

**Explanation**
The timeline is strictly decreasing. For each moment, no future moment has a stronger aetherial reading, so the wait time is always `0`.

---

### *Question designed by Kushal [rkushell](https://github.com/rkushell)*