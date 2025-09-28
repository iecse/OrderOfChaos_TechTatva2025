## Scroll of Requirement

You are a **mage** mid-duel, holding a **spell scroll `S`**, a long ribbon of runes. Your opponent’s **counter-curse** requires a specific multiset of **runes `T`** to be chanted exactly once within a single breath. The shorter your chant, the sooner it finishes—and the better your chance to win.

Your task is to find the **shortest contiguous snippet** of the scroll that contains all runes from the **requirements `T`** with their required counts. If multiple such snippets are equally short, you must use the leftmost one.

-----

## Input Format

The first line contains the number of test cases

The input for each test case consists of two lines:

1.  The first line contains the string **`S`**, the spell scroll.
2.  The second line contains the string **`T`**, the required runes.

-----

## Output Format

For each test case, print the result on a new line.

  * If a valid window exists, output the exact substring of `S` that is the shortest valid window.
  * Otherwise, output the string `IMPOSSIBLE`.

-----

## Constraints

- $1 \le |S| \le 2 \cdot 10^5$  
- $1 \le |T| \le 10^5$  
- The sum of $|S|$ across all test cases does not exceed $2 \cdot 10^5$  
- The sum of $|T|$ across all test cases does not exceed $10^5$  
- Characters are case-sensitive

-----

## Example 1

**Input**

```
1
ADOBECODEBANC
ABC
```

**Output**

```
BANC
```

-----

## Example 2

**Input**

```
1
aAaAa
AaA
```

**Output**

```
aAaAa
```

-----

*Question designed by Kushal [rkushell](https://github.com/rkushell)*