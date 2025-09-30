## The Grand Conjunction: Runic Rotation

In the highest chamber of the Astral Tower, an ancient artifact is kept: a chain of **magical runes**, structured as a **doubly linked list**. Each rune is etched with an integer value, representing a fragment of cosmic power.

During the Grand Conjunction, which occurs once every millennium, the runes realign themselves in a powerful magical shift. This alignment is a precise **clockwise rotation** of the entire chain by `k` positions.

As the Keeper of the Tower, your sacred duty is to predict the outcome of this event. Given the runic chain and a rotation amount `k`, you must perform this magical rotation efficiently and determine the new order of the runes.

-----

### Input Format

-   The first line contains an integer $T$, the number of test cases.
-   The first line of each test case contains two integers, $N$ and $K$ — the number of runes and the rotation amount, respectively.
-   The second line of each test case contains $N$ space-separated integers $r_1, r_2, \dots, r_n$ — the values of the runes in their initial order.

-----

### Constraints

-   $1 \le N \le 2 \cdot 10^5$
-   $0 \le K \le 10^9$
-   $-10^4 \le r_i \le 10^4$
-   The sum of $N$ over all test cases will not exceed $2 \cdot 10^5$.

-----

## Output Format

For each test case, print a single line containing `n` space-separated integers representing the values of the runes after the rotation, starting from the new head.

-----

## Example 1

**Input**

```
1
5 2
10 20 30 40 50
```

**Output**

```
40 50 10 20 30
```

-----

## Example 2

**Input**

```
1
6 4
1 2 3 4 5 6
```

**Output**

```
3 4 5 6 1 2
```

-----

*Question designed by Kushal [rkushell](https://github.com/rkushell)*