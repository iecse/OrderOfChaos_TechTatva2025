## The Seal of the Ancestral Guardian

### Problem Statement

In a hidden grove, the **Great Deku Tree** preserves the lineage of ancient forest spirits. This lineage is represented as a sacred binary tree, where each spirit is a node identified by a unique `ID`.

A magical corruption seeps into the grove. To protect the lineage, certain spirits can manifest a powerful ward, becoming **"sealed"** guardians. A spirit is a guardian if its `ID` is a **prime number**. These guardians form a seal, blocking any corrupting influence from passing through them to their descendants.

You are a druid tasked with a critical mission. For any two given spirits, you must find their ultimate protector—the highest-ranking guardian that watches over both of them. This is the first spirit on the ancestral path from their lowest common ancestor up to the root of the Great Deku Tree that is a guardian.

### Input Format

  - The first line of input will contain a single integer $T$, denoting the number of test cases.
  - The first line of each test case contains an integer $N$, the total number of spirits in the tree.
  - The next $N$ lines describe the tree's structure. Each line provides three integers: `id`, `left_id`, and `right_id`. A value of `-1` for `left_id` or `right_id` indicates the absence of a child.
  - The next line contains an integer $Q$, the number of queries.
  - The following $Q$ lines each contain two distinct integers, `id1` and `id2`, representing the two spirits for a query.

### Output Format

For each query, print a single integer on a new line: the `ID` of the first common ancestral guardian. If no such guardian exists, print `-1`.

### Constraints

  - $1 \le T \le 100$
  - $2 \le N \le 10^4$
  - $1 \le Q \le 10^4$
  - $1 \le \text{id}, \text{id1}, \text{id2} \le 10^5$
  - The sum of $N$ over all test cases will not exceed $10^4$.
  - The sum of $Q$ over all test cases will not exceed $10^4$.
  - The provided input for each test case is guaranteed to form a valid binary tree.
  - All queried IDs are guaranteed to exist within the tree.

### Sample Input

```
1
9
30 8 19
8 3 6
19 15 22
3 5 7
6 -1 -1
15 -1 -1
22 -1 -1
5 -1 -1
7 -1 -1
3
5 7
3 6
15 22
```

### Sample Output

```
3
-1
19
```

### Explanation

**Test Case 1:**
The tree structure is rooted at node 30.

  - **Query 1: `5 7`**

      - The Lowest Common Ancestor (LCA) of 5 and 7 is node 3.
      - We check the path from the LCA to the root: 3 -\> 8 -\> 30.
      - The first node on this path with a prime ID is 3. So, the output is `3`.

  - **Query 2: `3 6`**

      - The LCA of 3 and 6 is node 8.
      - We check the path from the LCA to the root: 8 -\> 30.
      - Neither 8 nor 30 is a prime number. No guardian exists on the ancestral path. So, the output is `-1`.

  - **Query 3: `15 22`**

      - The LCA of 15 and 22 is node 19.
      - We check the path from the LCA to the root: 19 -\> 30.
      - The first node on this path with a prime ID is 19. So, the output is `19`.
  
*Question designed by Kushal [rkushell](https://github.com/rkushell)*