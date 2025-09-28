## The Wizard’s Wand: Spell of Reversal

A powerful wizard channels magical energy through a special wand, constructed from a sequence of **beads**. These beads, arranged in an array, each possess a specific power level, which can be positive, negative, or zero.

The effectiveness of the wand is determined by its **magical segment**—a contiguous subarray of beads whose combined power sum is the **maximum possible**. To amplify the wand's power, the wizard can perform a single, potent spell: reversing exactly one contiguous subarray of beads. This spell rearranges the flow of energy, potentially creating a new, more powerful magical segment.

Your mission is to assist the wizard by determining the absolute maximum power the wand can achieve. You must find the maximum possible sum of a magical segment after performing at most one **reversal** spell.

-----

## Input Format

The first line contains the number of test cases

The input for a single test case is as follows:

1. The first line contains an integer **`n`** ($1 \le n \le 2 \cdot 10^5$) — the number of beads on the wand.  
2. The second line contains `n` space-separated integers $a_1, a_2, \dots, a_n$ ($-10^9 \le a_i \le 10^9$) — the power values of the beads.

-----

## Output Format

For each test case, print a single integer on a new line: the maximum sum of a magical segment achievable after performing at most one reversal.

-----

## Example 1

**Input**

```
1
5
2 -3 -1 4 -2
```

**Output**

```
6
```

-----

## Example 2

**Input**

```
1
4
-5 -2 -3 -4
```

**Output**

```
-2
```

-----

## Example 3

**Input**

```
1
5
1 2 3 4 5
```

**Output**

```
15
```

-----

## Example 4

**Input**

```
1
6
8 -1 -20 15 4 -3
```

**Output**

```
27
```

-----

*Question designed by Kushal [rkushell](https://github.com/rkushell)*