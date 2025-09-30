## The Sorcerer's Spellbook: The Curse of Annihilation

A master sorcerer stores powerful **spells** on an ancient, **enchanted scroll**. This scroll is represented as a string, where each character is a magical **rune** (a lowercase English letter).

However, the scroll is afflicted by a potent curse. When two identical, adjacent **runes** come into contact, they create a volatile reaction and instantly **annihilate** each other, vanishing from the scroll. This magical cancellation can bring two previously separated runes together, potentially triggering a **chain reaction** of further annihilations. This process continues until the scroll reaches a **stable state** where no adjacent runes are identical.

Your task is to foresee the final state of this cursed scroll after all possible annihilations have resolved.

-----

### Input Format

-   The first line contains an integer $T$, the number of test cases.
-   The first line of each test case contains a single string $s$ — the initial sequence of runes on the scroll.

-----

### Constraints

-   $1 \le |s| \le 2 \cdot 10^5$, where $|s|$ is the length of the string.
-   The string $s$ consists of only lowercase English letters.
-   The sum of $|s|$ over all test cases will not exceed $2 \cdot 10^5$.
-----

## Output Format

For each test case, print the final, stable state of the scroll on a new line.

If the scroll becomes completely empty after all annihilations, print the string `Empty Spellbook`.

-----

## Example 1

**Input**

```
1
abccba
```

**Output**

```
Empty Spellbook
```

-----

## Example 2

**Input**

```
1
azxxzy
```

**Output**

```
ay
```

-----

## Example 3

**Input**

```
1
aabcca
```

**Output**

```
ba
```

-----

*Question designed by Kushal [rkushell](https://github.com/rkushell)*