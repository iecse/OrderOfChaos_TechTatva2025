# Arcane Coin Clash
## Question Difficulty – Hard

Two wizards, **Titli** and **Babli**, have discovered two rows of **arcane crystals**, each containing `n` crystals. Each crystal stores a certain amount of **magical energy**.

To determine how many **arcane coins** they will spend for their ritual, they decide to play a strategic game on these crystals.

### Game Rules

1. The game lasts for **`k` rounds**.  
2. In each round:
   - **Titli** selects two distinct indices `i` and `j` (1 ≤ i < j ≤ n).  
   - **Babli** can then **rearrange the four selected crystals** `{a[i], a[j], b[i], b[j]}` in **any way**:
     - He can swap crystals **between rows**.
     - He can also leave them unchanged.  
3. After all `k` rounds, the **ritual cost** is calculated as:

$$
v = \sum_{i=1}^{n} |a_i - b_i|
$$

### Objectives

- **Titli** wants to **minimize** the ritual cost `v`.  
- **Babli** wants to **maximize** the ritual cost `v`.  

Both wizards play **optimally**, considering the best strategy of the other.

## Input Format

- The first line contains an integer `t` the number of scenarios.  
- Each scenario consists of three lines:
  1. Two integers `n` and `k` — the number of crystals in each row and the number of rounds.  
  2. `n` integers `a_1, a_2, …, a_n` — the energies of Titli’s crystals.  
  3. `n` integers `b_1, b_2, …, b_n` — the energies of Babli’s crystals.

## Output Format

For each scenario, output a single integer — the **final ritual cost** in arcane coins if both wizards play optimally.

## Example

**Input**  

```
5

2 1
1 7
3 5

3 2
1 5 3
6 2 4

5 4
1 16 10 10 16
3 2 2 15 15

4 1
23 1 18 4
19 2 10 3

10 10
4 3 2 100 4 1 2 4 5 5
1 200 4 5 6 1 10 2 3 4
```

**Output**
```
8
9
30
16
312
```
## Explanation

1. **Scenario 1** (`n=2, k=1`):  
   - Only possible pair `(1,2)` can be chosen.  
   - Babli rearranges `{1, 7, 3, 5}` to maximize differences: `a = [5,1], b = [3,7]`.  
   - Ritual cost: `|5-3| + |1-7| = 4 + 4 = 8`.

2. **Scenario 2** (`n=3, k=2`):  
   - Titli tries to minimize, but Babli keeps arrays unchanged to maximize differences.  
   - Cost: `|1-6| + |5-2| + |3-4| = 9`.

3. **Scenario 3** (`n=5, k=4`):  
   - Babli rearranges in 4 rounds to maximize mismatches.  
   - Cost: `30`.

4. **Scenario 4** (`n=4, k=1`):  
   - With only 1 round, Titli can limit Babli’s advantage.  
   - Cost: `16`.

5. **Scenario 5** (`n=10, k=10`):  
   - Babli has full control to maximize differences.  
   - Cost: `312`.

## Constraints
- 1 ≤ t ≤ $10^3$ — number of test cases  
- 1 ≤ n ≤ 2 × $10^5$ — number of coins in a scenario  
- 1 ≤ k ≤ n  
- 1 ≤ a[i], b[i] ≤ $10^9$  
- The sum of all n across all test cases does not exceed 2 × $10^5$  
