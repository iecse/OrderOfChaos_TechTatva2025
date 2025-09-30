## The Alchemist's Array: A Quest for Balance

In a dimly lit laboratory, a master alchemist works with an array of **magical potions**. Each potion is identified by an integer representing its core essence. The alchemist's ultimate goal is to create the most potent and stable concoction possible.

Stability is achieved in a **balanced potion mix**, which is defined as a contiguous subarray of potions where the essences are in near-perfect harmony. This harmony occurs if, within the subarray, the count of the most frequent essence and the count of the least frequent essence differ by **at most 1**.

Your task is to help the alchemist by analyzing the array of potions and finding the length of the **longest** possible **balanced potion mix** that can be formed.

-----

### Input Format

-   The first line contains an integer $T$, the number of test cases.
-   The first line of each test case contains an integer $N$ — the number of magical potions.
-   The second line of each test case contains $N$ space-separated integers $a_1, a_2, \dots, a_n$ — the essence value of each potion.

-----

### Constraints

-   $1 \le N \le 2 \cdot 10^5$
-   $1 \le a_i \le 10^5$
-   The sum of $N$ over all test cases will not exceed $2 \cdot 10^5$.
-----

## Output Format

For each test case, print a single integer on a new line: the length of the longest balanced potion mix found.

-----

## Example 1

**Input**

```
1
7
2 2 1 1 5 3 3
```

**Output**

```
7
```

-----

## Example 2

**Input**

```
1
6
1 1 1 2 2 2
```

**Output**

```
6
```

-----

## Example 3

**Input**

```
1
8
1 2 3 1 2 3 1 2
```

**Output**

```
8
```

-----

## Example 4

**Input**

```
1
8
1 1 2 2 1 3 4 5
```

**Output**

```
5
```

-----

*Question designed by Kushal [rkushell](https://github.com/rkushell)*