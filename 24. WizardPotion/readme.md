# The Wizard's Potion Challenge

## Question Difficulty: Medium


In the mystical land of **Eldoria**, a group of wizards are attempting to brew the **most potent potion**. Each wizard possesses a tall, magical threshold containing a certain amount of **magical essence** (numbers in an array `threshold`).

---

## The Rules of the Brew

* The wizards must select **two thresholds** to combine their essence into a potion.
* The **strength of the potion** is determined by the **shorter threshold** (since it limits how much essence can flow) multiplied by the **distance between the two thresholds** (longer distance allows more mixing magic).
* The goal is to find the **pair of thresholds** that yields the **strongest potion**.



---

## Input

The first line contains a single integer t — the number of testcases.

For each testcase:

The first line contains an integer n — the number of thresholds.

The second line contains n integers — the array thresholds





## Constraints
- 1 ≤ t ≤ 1000

- 2≤n≤2000

- 1≤thresholds[i]≤10000

The sum of n over all test cases does not exceed $2$ x $10^5$.

## Output

The **maximum potion strength** that can be brewed by any pair of thresholds.

---

## Example

**Input:**

```
3
9
1 8 6 2 5 4 8 3 7
5
5 5 5 5 5
4
1 2 4 3
```


**Output:**

```
49
20
4
```

---
~ <a href=https://github.com/r1shu-R> Rishabh </a>