
-----

# The Alchemist's Array: A Quest for Balance

## Question Difficulty: Hard

### Description:

In a dimly lit laboratory, a master alchemist works with an array of **magical potions**. Each potion is identified by an integer representing its core essence. The alchemist's ultimate goal is to create the most potent and stable concoction possible.

Stability is achieved in a **balanced potion mix**, which is defined as a contiguous subarray of potions where the essences are in near-perfect harmony. This harmony occurs if, within the subarray, the count of the most frequent essence and the count of the least frequent essence differ by **at most 1**.

Your task is to help the alchemist by analyzing the array of potions and finding the length of the **longest** possible **balanced potion mix** that can be formed.

-----

### Input:

  - The first line contains an integer `n`, the number of magical potions.
  - The second line contains `n` space-separated integers, representing the essence value of each potion.

-----

### Output:

Return a single integer: the length of the longest balanced potion mix found.

-----

### Constraints

- The total number of potions, `n`, will be between $1$ and $2 \cdot 10^5$, inclusive.  
- Each potion's essence value, $a[i]$, will be an integer between $1$ and $10^5$, inclusive.

### Examples

### Example 1

**Input**

```
7
2 2 1 1 5 3 3
```

**Output**
`7`

**Explanation**
The longest balanced mix is the **entire array** `[2, 2, 1, 1, 5, 3, 3]`. Let's analyze its essence counts:

  - Essence `1`: appears 2 times
  - Essence `2`: appears 2 times
  - Essence `3`: appears 2 times
  - Essence `5`: appears 1 time

The distinct frequencies of the essences are 2 and 1. The **most frequent** count is 2, and the **least frequent** is 1. The difference is $2 - 1 = 1$, which satisfies the balance condition. Therefore, the longest possible balanced subarray has a length of 7.

-----

#### Example 2

**Input**

```
6
1 1 1 2 2 2
```

**Output**
`6`

**Explanation**
The entire array represents a perfectly balanced potion mix. The essence counts are:

  - Essence `1`: appears 3 times
  - Essence `2`: appears 3 times

The most and least frequent counts are both 3. The difference is $3 - 3 = 0$, achieving perfect harmony. The length is 6.

-----

#### Example 3

**Input**

```
8
1 2 3 1 2 3 1 2
```

**Output**
`8`

**Explanation**
The entire array is also a balanced mix. The essence counts are:

  - Essence `1`: appears 3 times
  - Essence `2`: appears 3 times
  - Essence `3`: appears 2 times

The distinct frequencies are 3 and 2. The most frequent count is 3, and the least frequent is 2. The difference is $3 - 2 = 1$, which is a state of balance. The length is 8.

-----


### Example 4

**Input**

```
8
1 1 2 2 1 3 4 5
```

**Output**
`5`

**Explanation**
Let's analyze the two longest candidate subarrays:

1.  **The entire array `[1, 1, 2, 2, 1, 3, 4, 5]` (length 8):**

      - Essence `1`: appears 3 times
      - Essence `2`: appears 2 times
      - Essence `3`: appears 1 time
      - Essence `4`: appears 1 time
      - Essence `5`: appears 1 time
        The most frequent count is **3** (`1`), and the least frequent count is **1** (`3`, `4`, `5`). The difference is $3 - 1 = 2$. This is **unbalanced**.

2.  **The subarray `[1, 1, 2, 2, 1]` (length 5):**

      - Essence `1`: appears 3 times
      - Essence `2`: appears 2 times
        The most frequent count is **3** and the least frequent is **2**. The difference is $3 - 2 = 1$. This is **balanced**.

Since no balanced subarray of length 6 or 7 exists, the longest balanced mix is the subarray `[1, 1, 2, 2, 1]` with a length of **5**.

### *Question designed by Kushal [rkushell](https://github.com/rkushell)*