# The Enchanted Pathfinder's Quest

**Question Difficulty: Medium**

## Description:

Lara the sorceress has discovered two magical crystal formations α and β, each containing n crystals arranged in a line. Each crystal can be either **Fire** (represented by 1) or **Ice** (represented by 0). The two formations dynamically create a mystical n × n energy grid where the energy at position (i,j) equals αᵢ ⊕ βⱼ (where ⊕ denotes the magical XOR resonance).

Lara's familiar, a wise phoenix, always starts its journey at the top-left corner (1,1) of the energy grid. From any cell (i,j), the phoenix can only fly down to (i+1,j) or right to (i,j+1). The phoenix can successfully complete its journey to any cell only if there exists a valid path where **all cells on the path, including (1,1), have energy value 0**.

Before beginning her quest, Lara can perform the following **Crystal Transmutation** ritual any number of times:

- Choose one crystal position 1 ≤ i ≤ n, and flip either αᵢ or βᵢ (Fire becomes Ice, Ice becomes Fire). The entire energy grid will magically reconfigure accordingly.

Let g(x,y) denote the minimum number of Crystal Transmutations required so that the phoenix can reach cell (x,y). You must determine the sum of g(x,y) over all 1 ≤ x,y ≤ n.

Note that each of the n² destination cells is independent, meaning you need to assume the crystal formations are in their original state for each case (i.e., no actual transmutations are permanently performed).

## Input:

The first line contains a single integer t (1 ≤ t ≤ 10⁴) - the number of test cases.

For each test case:

- The first line contains one integer n (1 ≤ n ≤ 2×10⁵) - the number of crystals in each formation
- The second line contains a binary string α (|α| = n, αᵢ ∈ {0,1}) - the crystal formation α
- The third line contains a binary string β (|β| = n, βᵢ ∈ {0,1}) - the crystal formation β

It is guaranteed that the sum of n over all test cases does not exceed 2×10⁵.

## Output:

For each test case, output one integer — the sum of minimum transmutations over all possible destination cells.

## Constraints:

- Number of test cases: 1 ≤ t ≤ 10⁴
- Crystals per formation: 1 ≤ n ≤ 2×10⁵
- Crystal types: αᵢ, βᵢ ∈ {0,1}
- Total crystals across all cases: ≤ 2×10⁵

## Example:

### Input:

```
3
2
11
00
2
01
01
4
1010
1101
```

### Output:

```
5
4
24
```

## Notes:

- The phoenix can only traverse through cells where Fire and Ice energies are perfectly balanced (energy = 0)
- Crystal Transmutation allows strategic alteration of individual crystals to create safe passages
- Each destination analysis assumes the crystal formations reset to their original state
- Movement is restricted to downward and rightward directions only

---

_Question designed by [Abhyuday-Gupta912](https://github.com/Abhyuday-Gupta912)_
