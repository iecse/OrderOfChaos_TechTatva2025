# The Enchanted Forest: Path of Power

## Question Difficulty: Medium

### Description:

In the heart of an ancient, **Enchanted Forest**, the trees are imbued with raw magic. This magic is stored in the **magical fruits** that grow on their branches. The entire forest is represented as a sacred **binary tree**, where each node is a branch holding a fruit with a specific **magic power** (an integer value).

A **magical path** is a connection between any two branches (nodes) in the tree. The total power of a path is the sum of the magic power of all fruits along that path. As the guardian of this forest, you are tasked with a profound challenge: to discover the single most powerful magical path that exists.

Your quest is to find the **maximum magical power** that can be drawn from any possible path within the forest's tree structure. Note that a path must contain at least one node and does not need to pass through the root.

-----

### Input:

The input will be provided directly to a function, which receives:

  - The `root` of a binary tree, where each node represents a branch and has a `val` attribute storing the fruit's magic power.

-----

### Output:

Return a single integer: the maximum magical power found among all possible paths in the tree.

-----

### Constraints

  - Number of nodes in the tree: 1 ≤ `n` ≤ 10^5
  - Node `val`: -1000 ≤ `Node.val` ≤ 1000

-----

### Examples

The following trees are used for the examples:

#### Example 1

**Tree Structure:**

```
      1
     / \
    2   3
```

**Input**
`root` of the tree above.

**Output**
`6`

**Explanation**
The optimal magical path connects branch `2` to branch `3` through the root, `1`. The total power is the sum of the fruit values: $2 + 1 + 3 = 6$.

-----

#### Example 2

**Tree Structure:**

```
     -10
     /   \
    9     20
         /  \
        15   7
```

**Input**
`root` of the tree above.

**Output**
`42`

**Explanation**
The path with the maximum magical power does not involve the root (`-10`). Instead, it is entirely within the right subtree, connecting branch `15` to branch `7` through `20`. The total power is $15 + 20 + 7 = 42$.

-----

#### Example 3

**Tree Structure:**

```
      -3
     /
    5
   / \
 -1   4
```

**Input**
`root` of the tree above.

**Output**
`8`

**Explanation**
The best path is from node `-1` to node `4`, passing through node `5`. The sum is $-1 + 5 + 4 = 8$. The root (`-3`) is not part of this optimal path because its negative value would reduce the total power.

-----

### *Question designed by Kushal [rkushell](https://github.com/rkushell)*