
-----

# Chronomancer's Time-Shift: The Corruption Spread

## Question Difficulty: Hard

### Description:

A powerful Chronomancer oversees the **fabric of time**, which is represented as a 2D **grid**. Each cell in the grid is a distinct moment that can exist in one of three states:

  - `1`: A **corrupted** moment, a tear in time that actively spreads its influence.
  - `0`: A **stable** moment, a normal point in time that is vulnerable to corruption.
  - `-1`: An **anchored** moment, a fixed point in history that is immune to corruption and blocks its spread.

The corruption spreads with each passing minute (or **tick** of the cosmic clock). In a single tick, any **stable** moment that is adjacent (up, down, left, or right) to a **corrupted** moment also becomes corrupted. This process happens simultaneously for all corrupted moments.

You are tasked with helping the Chronomancer predict the future. You must determine the minimum number of ticks required until no stable moments remain. If there is any stable moment that can never be reached by the corruption, the situation is unsalvageable.

-----

### Input:

The input will be a 2D integer array, `grid`, representing the fabric of time.

-----

### Output:

Return a single integer:

  - The minimum number of **ticks** (minutes) required to corrupt all stable moments.
  - `0` if there are no stable moments to begin with.
  - `-1` if it's impossible to corrupt every stable moment.

-----

### Constraints

  - The grid will have `rows` and `cols` between `1` and `500`.
  - `grid[i][j]` will only be `0`, `1`, or `-1`.

-----

### Examples

#### Example 1

**Input Grid:**

```
[
  [1, 0, 0],
  [0, -1, 0],
  [1, 0, 0]
]
```

**Output:**
`2`

**Explanation:**
The corruption starts at `(0,0)` and `(2,0)`.

  - **After 1 tick:** The stable moments at `(0,1)`, `(1,0)`, and `(2,1)` become corrupted. The grid looks like `[[1,1,0], [1,-1,0], [1,1,0]]`.
  - **After 2 ticks:** The remaining stable moments at `(0,2)`, `(1,2)`, and `(2,2)` are corrupted by their newly corrupted neighbors.
    All stable moments are corrupted after 2 ticks.

-----

#### Example 2

**Input Grid:**

```
[
  [1, 0, 0],
  [-1, -1, 0],
  [0, 0, 0]
]
```

**Output:**
`6`

**Explanation:**
The corruption starts at `(0,0)` and must navigate around the anchored `(-1)` wall. All stable moments are reachable, but it takes several ticks.

  - **Tick 0:** The cell at `(0,0)` is corrupted.
  - **Tick 1:** Corruption spreads to `(0,1)`.
  - **Tick 2:** It spreads from `(0,1)` to `(0,2)`.
  - **Tick 3:** It spreads from `(0,2)` to `(1,2)`.
  - **Tick 4:** It spreads from `(1,2)` down to `(2,2)`.
  - **Tick 5:** It spreads from `(2,2)` left to `(2,1)`.
  - **Tick 6:** Finally, it spreads from `(2,1)` to `(2,0)`.
    At this point, all initially stable moments have been corrupted. The last one was reached at the 6-minute mark, so the minimum time required is **6**.

-----

#### Example 3

**Input Grid:**

```
[
  [-1, 1],
  [1, 1]
]
```

**Output:**
`0`

**Explanation:**
There are no stable (`0`) moments in the initial grid. Therefore, no time needs to pass.

-----

### *Question designed by Kushal [rkushell](https://github.com/rkushell)*
