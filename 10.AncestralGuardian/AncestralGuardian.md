## The Seal of the Ancestral Guardian

In a hidden grove, the **Great Deku Tree** preserves the lineage of ancient forest spirits. This lineage is represented as a sacred binary tree, where each spirit is a node identified by a unique `ID`.

A magical corruption seeps into the grove. To protect the lineage, certain spirits can manifest a powerful ward, becoming **"sealed"** guardians. A spirit is a guardian if its `ID` is a **prime number**. These guardians form a seal, blocking any corrupting influence from passing through them to their descendants.

You are a druid tasked with a critical mission. For any two given spirits, you must find their ultimate protector—the highest-ranking guardian that watches over both of them. This is the first spirit on the ancestral path from their lowest common ancestor up to the root of the Great Deku Tree that is a guardian.

---

### Input Format

1. The first line contains an integer **`n`** — the total number of spirits in the tree.  
2. The next **`n`** lines describe the tree's structure. Each line provides three integers: **`id`**, **`left_id`**, and **`right_id`**. A value of **-1** for **`left_id`** or **`right_id`** indicates the absence of a child.  
3. The next line contains an integer **`q`** — the number of queries.  
4. The following **`q`** lines each contain two distinct integers **`id1`** and **`id2`**, representing the two spirits for a query.  

---

### Output Format

For each query, print a single integer on a new line: the `ID` of the first common ancestral guardian. If no such guardian exists, print `-1`.

---

### Constraints

- $1 \le t \le 100$  
- $2 \le n \le 10^4$  
- $1 \le q \le 10^4$  
- $1 \le \text{id}, \text{id1}, \text{id2} \le 10^5$  
- The sum of **`n`** over all test cases will not exceed $10^4$.  
- The sum of **`q`** over all test cases will not exceed $10^4$.  
- The provided input for each test case is guaranteed to form a valid binary tree.  
- All queried IDs are guaranteed to exist within the tree.  

---

### Example

**Input**

```
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

**Output**

```
3
-1
19
```

---

*Question designed by Kushal [rkushell](https://github.com/rkushell)*
