## The Enchanted Forest: Path of Power

In the heart of an ancient, **Enchanted Forest**, the trees are imbued with raw magic. This magic is stored in the **magical fruits** that grow on their branches. The entire forest is represented as a sacred **binary tree**, where each node is a branch holding a fruit with a specific **magic power** (an integer value).

A **magical path** is a connection between any two branches (nodes) in the tree. The total power of a path is the sum of the magic power of all fruits along that path. As the guardian of this forest, you are tasked with a profound challenge: to discover the single most powerful magical path that exists.

Your quest is to find the **maximum magical power** that can be drawn from any possible path within the forest's tree structure. Note that a path must contain at least one node and does not need to pass through the root.

-----

## Input Format

First line contains number of test cases

For each test case:

1. The first line contains an integer **`n`** ($1 \le n \le 10^5$) — the number of branches (nodes) in the tree.  
2. The next `n` lines describe the nodes, indexed from 1 to `n`. The `i`-th of these lines contains three integers: `val_i`, `left_i`, and `right_i`.  
   - `val_i` ($-1000 \le val_i \le 1000$) is the magic power of the fruit at node `i`.  
   - `left_i` and `right_i` are the 1-based indices of the left and right children, respectively. A value of `0` indicates that a child does not exist.  

The node with index `1` is always the root of the tree. The sum of **`n`** over all test cases will not exceed $10^5$.

-----

## Output Format

For each test case, print a single integer on a new line: the maximum magical power found among all possible paths in the tree.

-----

## Example 1

**Input**

```
1
3
1 2 3
2 0 0
3 0 0
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
5
-10 2 3
9 0 0
20 4 5
15 0 0
7 0 0
```

**Output**

```
42
```

-----

## Example 3

**Input**

```
1
4
-3 2 0
5 3 4
-1 0 0
4 0 0
```

**Output**

```
8
```

-----

*Question designed by Kushal [rkushell](https://github.com/rkushell)*