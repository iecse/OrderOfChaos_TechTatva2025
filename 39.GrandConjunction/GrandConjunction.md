
***

# The Grand Conjunction: Runic Rotation

## Question Difficulty: Easy

### Description:

In the highest chamber of the Astral Tower, an ancient artifact is kept: a chain of **magical runes**, structured as a **doubly linked list**. Each rune is etched with an integer value, representing a fragment of cosmic power.

During the Grand Conjunction, which occurs once every millennium, the runes realign themselves in a powerful magical shift. This alignment is a precise **clockwise rotation** of the entire chain by `k` positions.

As the Keeper of the Tower, your sacred duty is to predict the outcome of this event. Given the head of the runic chain and a rotation amount `k`, you must perform this magical rotation efficiently and determine the new head of the chain.

---

### Input:

The input will be provided directly to a function, which receives:
- `head`: The head node of a doubly linked list of runes.
- `k`: An integer representing the number of positions to rotate.

*(A pre-defined `DoublyListNode` class or struct will be available.)*

---

### Output:

Return the `head` of the doubly linked list after it has been rotated.

---

### Constraints

* **Number of Runes (`n`):** The list will contain between $1$ and $2 \times 10^5$ runes.
* **Rune Values:** The value of a rune can range from $-10^4$ to $10^4$.
* **Rotation Amount (`k`):** The rotation amount `k` can range from $0$ to $10^9$.

---

### Examples

#### Example 1

**Input:**
`head` of list `10 ↔ 20 ↔ 30 ↔ 40 ↔ 50`
`k = 2`

**Output:**
The `head` of the new list `40 ↔ 50 ↔ 10 ↔ 20 ↔ 30`

**Explanation:**
The original chain is `10-20-30-40-50`. Rotating it clockwise by 2 positions means the last two runes (`40`, `50`) move to the front. The new order becomes `40-50-10-20-30`.



#### Example 2

**Input:**
`head` of list `1 ↔ 2 ↔ 3 ↔ 4 ↔ 5 ↔ 6`
`k = 4`

**Output:**
The `head` of the new list `3 ↔ 4 ↔ 5 ↔ 6 ↔ 1 ↔ 2`

**Explanation:**
Rotating the chain of 6 runes by 4 positions shifts the last four runes (`3`, `4`, `5`, `6`) to the front of the list.

---

### *Question designed by Kushal [rkushell](https://github.com/rkushell)*