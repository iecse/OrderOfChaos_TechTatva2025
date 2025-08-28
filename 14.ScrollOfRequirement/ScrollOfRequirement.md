# Scroll of Requirement
## Question Difficulty: Hard

### Description

You are a **mage** mid-duel, holding a **spell scroll `S`**, a long ribbon of runes. Your opponent’s **counter-curse** requires a specific multiset of **runes `T`** to be chanted exactly once within a single breath. The shorter your chant, the sooner it finishes—and the better your chance to win.

Your task is to find the **shortest contiguous snippet** of the scroll that contains all runes from the **requirements `T`** with their required counts. If multiple such snippets are equally short, you must use the leftmost one. If no snippet works, the scroll fails you, and the duel is lost.

---

### Input

The input is provided via standard input in the following format:

-   Line 1: string `S` — the full spell scroll (the source of runes).
-   Line 2: string `T` — the requirements runes you must include (with multiplicities).

*Strings may contain any printable ASCII characters except newlines and will not have surrounding quotes.*

---

### Output

-   If a valid window exists: output the exact substring of `S` that is the shortest valid window.
-   Otherwise, output the string `IMPOSSIBLE`.
-   If multiple shortest windows exist, output the one with the smallest starting index (the leftmost one).

---

### Constraints

-   `1 ≤ length(S) ≤ 2 * 10^5`
-   `1 ≤ length(T) ≤ 10^5`
-   Characters are case-sensitive printable ASCII.

---

### Notes

-   "Contains all runes from `T`" means multiplicity matters. If `T = "AAB"`, a valid window must have at least two 'A's and one 'B'.
-   This problem can be efficiently solved using the **sliding window** technique with two pointers, allowing for a solution in `O(|S|)` time.
-   If `T` contains a rune that does not appear in `S`, the answer is always `IMPOSSIBLE`.

---

### Examples from the Grimoire

#### Incantation 1
**Input**
`ADOBECODEBANC`
`ABC`

**Output**
`BANC`

**Explanation**
The snippet `BANC` is the shortest part of `S` that contains at least one 'A', one 'B', and one 'C'. Other valid snippets like `ADOBEC` are longer.

---

#### Incantation 2
**Input**
`aAaAa`
`AaA`

**Output**
`AaA`

**Explanation**
The snippet `AaA` starting at index 1 is the shortest window containing two uppercase 'A's and one lowercase 'a'. The snippet `aAa` at index 0 is also valid but has the same length, so the leftmost one is chosen. The final `AaA` at index 2 is also a valid window.

---

#### Incantation 3
**Input**
`elixir-of-endless-mana`
`rune`

**Output**
`IMPOSSIBLE`

**Explanation**
The scroll `S` contains the runes 'r', 'u', 'n', and 'e', but the shortest snippet containing all of them is `r-of-endless-mana`. The prompt asks for a snippet containing all runes, not necessarily in order. The rune 'u' is missing from the scroll entirely.

---

#### Incantation 4
**Input**
`abbcac`
`abc`

**Output**
`bca`

**Explanation**
The snippet `bca` is a valid window of length 3. The snippet `abbc` is a valid window of length 4. The snippet `bcac` is a valid window of length 4. The shortest is `bca`.

---

### *Question designed by Kushal [rkushell](https://github.com/rkushell)*