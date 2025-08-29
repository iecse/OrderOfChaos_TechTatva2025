# The Wizard’s Wand: Spell of Reversal

## Question Difficulty: Hard

### Description:

A powerful wizard channels magical energy through a special wand, constructed from a sequence of **beads**. These beads, arranged in an array, each possess a specific power level, which can be positive, negative, or zero.

The effectiveness of the wand is determined by its **magical segment**—a contiguous subarray of beads whose combined power sum is the **maximum possible**. To amplify the wand's power, the wizard can perform a single, potent spell: reversing exactly one contiguous subarray of beads. This spell rearranges the flow of energy, potentially creating a new, more powerful magical segment.

Your mission is to assist the wizard by determining the absolute maximum power the wand can achieve. You must find the maximum possible sum of a magical segment after performing at most one **reversal** spell.

-----

### Input:

The input will be provided in the standard competitive programming format:

  - The first line contains an integer `n`, the number of beads on the wand.
  - The second line contains `n` space-separated integers, representing the power values of the beads.

-----

### Output:

Return a single integer: the maximum sum of a magical segment achievable after performing at most one reversal.

-----


### Constraints

-   Number of beads (`n`): $1 \le n \le 2 \cdot 10^5$
-   Bead power values: $-10^9 \le \text{power} \le 10^9$

-----

### Examples

#### Example 1

**Input**

```
5
2 -3 -1 4 -2
```

**Output**
`6`

**Explanation**
The maximum sum without any reversal is `4` (from the subarray `[4]`). However, if we reverse the subarray `[-3, -1, 4]`, the wand's bead sequence becomes `[2, 4, -1, -3, -2]`. The new maximum magical segment is `[2, 4]`, with a sum of `6`.

-----

#### Example 2

**Input**

```
4
-5 -2 -3 -4
```

**Output**
`-2`

**Explanation**
All bead powers are negative. The maximum sum is achieved by taking the single bead with the highest power, which is `-2`. Reversing any subarray will not create a positive sum, so the answer remains `-2`.

-----

#### Example 3

**Input**

```
5
1 2 3 4 5
```

**Output**
`15`

**Explanation**
The initial maximum sum is the sum of the entire array, `15`. Any reversal of a subarray will not result in a larger sum. Therefore, the best strategy is to perform no reversal.

-----

#### Example 4

**Input**

```
6
8 -1 -20 15 4 -3
```

**Output**
`23`

**Explanation**
The initial maximum sum is `19` (from subarray `[15, 4]`). By reversing the subarray `[-1, -20, 15]`, the wand's configuration changes to `[8, 15, -20, -1, 4, -3]`. The new maximum magical segment becomes `[8, 15]`, with a much greater sum of `23`.

-----

### *Question designed by Kushal [rkushell](https://github.com/rkushell)*