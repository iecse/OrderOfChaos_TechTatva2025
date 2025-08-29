
***

# The Oracle's Prophecy: The Summit of Eldoria

## Question Difficulty: Medium

### Description:

In the mystical land of Eldoria, the terrain is an **enchanted landscape** of glowing crystals, forming a vast mountain range. The stability of the entire realm is tied to the **magical energy** of these crystals, represented by their heights in a 2D **grid**.

The Oracle's Prophecy has evolved. To restore balance, you must now find a **Summit Crystal**. A Summit Crystal holds a position of true dominance, defined as a crystal whose magical energy is strictly greater than **all** of its adjacent neighbors (up, down, left, and right). Crystals on the edges or in the corners of the landscape have fewer neighbors to compare against.

Your new quest is to analyze this complex landscape, given as a 2D `heights` matrix, and find the coordinates of any single Summit Crystal.

---

### Input:

The input will be provided directly to a function, which receives:
- A 2D integer array (a matrix), `heights`.

---

### Output:

Return an array or tuple of two integers: `[row, col]`, representing the coordinates of any Summit Crystal.

---

### Constraints

* **Landscape Dimensions (`rows`, `cols`):** The landscape will contain between $1$ and $500$ rows and columns.
* **Crystal Heights:** The magical energy of a crystal can range from $-2^{31}$ to $2^{31} - 1$.
* **Guaranteed Summit:** It is guaranteed that a Summit Crystal always exists within the landscape.

---

### Examples

#### Example 1

**Input:**
`heights = [[1, 4, 3], [2, 5, 2], [1, 3, 1]]`

**Output:**
`[1, 1]`

**Explanation:**
The crystal at coordinates `[1, 1]` has a height of `5`. Its neighbors are:
-   Up: `4` (at `[0, 1]`)
-   Down: `3` (at `[2, 1]`)
-   Left: `2` (at `[1, 0]`)
-   Right: `2` (at `[1, 2]`)
Since `5` is greater than all its neighbors, `[1, 1]` is a valid Summit Crystal.

#### Example 2

**Input:**
`heights = [[1, 2, 3], [2, 3, 4], [1, 2, 1]]`

**Output:**
`[1, 2]`

**Explanation:**
The crystal at coordinates `[1, 2]` has a height of `4`. As it's on the edge, it only has three neighbors:
-   Up: `3` (at `[0, 2]`)
-   Down: `1` (at `[2, 2]`)
-   Left: `3` (at `[1, 1]`)
Since `4` is greater than all its neighbors, `[1, 2]` is a valid Summit Crystal.

---

### *Question designed by Kushal [rkushell](https://github.com/rkushell)*