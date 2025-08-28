# The Seal of the Ancestral Guardian

## Question Difficulty: Medium

### Description:

In a hidden grove, the **Great Deku Tree** preserves the lineage of **ancient forest spirits**. This lineage is represented as a sacred **binary tree**, where each spirit is a node identified by a unique **spirit `ID`**.

A magical corruption seeps into the grove, threatening the lineage. To protect themselves, certain spirits can manifest a powerful ward, becoming **"sealed"** guardians. A spirit is a **guardian** if its `ID` is a **prime number**. These guardians form a seal, blocking any corrupting influence from passing through them to their descendants.

You are a druid tasked with a critical mission. For any **two spirits**, you must find their ultimate protector—the highest-ranking guardian that watches over both their lineages. This requires you to identify their **first common ancestor** that is a guardian. If their immediate common ancestor isn't a guardian, you must look to its parent, and so on, up the ancestral line to the root of the Great Deku Tree itself.

Your task is to trace the lineage and report the `ID` of the first ancestral guardian that protects both spirits.

-----

### Input:

The input will be provided directly to a function, which receives:

  - The `root` of a binary tree, where each node represents a spirit and has a unique `ID`.
  - An integer `id1`, the `ID` of the first spirit.
  - An integer `id2`, the `ID` of the second spirit.

-----

### Output:

Return a single integer: the `ID` of the first common ancestor of the two spirits (on the path from their direct LCA to the root, inclusive) that is a guardian.

If no such guardian ancestor exists along this entire ancestral path, return `-1`.

-----

### Constraints

  - Number of nodes in the tree: 2 ≤ `n` ≤ 10^4
  - Node `ID` values: 1 ≤ `Node.ID` ≤ 10^5
  - `id1` and `id2` are guaranteed to exist in the tree and will be different.

-----

### Examples

The following tree is used for the examples:

```
      30
     /  \
    8    19
   / \   / \
  3   6 15  22
 / \
5   7
```

#### Example 1

**Input**
`id1 = 5`, `id2 = 7`

**Output**
`3`

**Explanation**
The direct Lowest Common Ancestor (LCA) of spirits `5` and `7` is the spirit with `ID = 3`. Since 3 is a prime number, it is a guardian. Therefore, it is the answer.

-----

#### Example 2

**Input**
`id1 = 3`, `id2 = 6`

**Output**
`-1`

**Explanation**
The LCA of spirits `3` and `6` is the spirit with `ID = 8`. The number 8 is not prime. We then check its parent, which is `30`. The number 30 is also not prime. Since there are no more ancestors, no guardian was found on the path.

-----

#### Example 3

**Input**
`id1 = 15`, `id2 = 22`

**Output**
`19`

**Explanation**
The LCA of spirits `15` and `22` is the spirit with `ID = 19`. Since 19 is a prime number, it is a guardian and the correct answer.

-----

### *Question designed by Kushal [rkushell](https://github.com/rkushell)*