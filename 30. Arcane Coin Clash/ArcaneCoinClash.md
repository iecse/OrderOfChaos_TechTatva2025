# Arcane Coin Clash
## Question Difficulty – Hard

Two wizards, **Titli** and **Babli**, have discovered two rows of **arcane crystals**, each containing `n` crystals. Each crystal stores a certain amount of **magical energy**.

To determine how many **arcane coins** they must spend for their upcoming ritual, they decide to play a strategic game on these crystals.


### Game Rules

1. The game lasts for **`k` rounds**.
2. In each round:
   - **Titli** chooses two distinct indices `i` and `j` (1 ≤ i < j ≤ n).  
   - **Babli**, the trickster, may **rearrange the four selected crystals** `{a[i], a[j], b[i], b[j]}` in **any way**:
     - He can swap crystals **between rows**.
     - He can also leave them **unchanged**.
3. After all `k` rounds, the **ritual cost** is computed as:

$$
v = \sum_{i=1}^{n} |a_i - b_i|
$$


### Objectives

- **Titli** wants to **minimize** the ritual cost `v` (spend fewer coins).  
- **Babli** wants to **maximize** the ritual cost `v` (spend as many coins as possible).  

Both wizards play **optimally**, considering the best strategy of the other.


## Input Format

- The first line contains an integer `t` (1 ≤ t ≤ 10^4) — the number of scenarios.  
- Each scenario consists of three lines:
  1. Two integers `n` and `k` (2 ≤ n ≤ 2·10^5, 1 ≤ k ≤ n) — the number of crystals in each row and the number of rounds.  
  2. `n` integers `a_1, a_2, …, a_n` (1 ≤ a_i ≤ 10^9) — the energies of Titli’s crystals.  
  3. `n` integers `b_1, b_2, …, b_n` (1 ≤ b_i ≤ 10^9) — the energies of Babli’s crystals.

**Constraints:**

- The sum of all `n` over all test cases does not exceed 2·10^5.

## Output Format

For each scenario, output a single integer — the **final ritual cost** in arcane coins after both wizards play optimally.

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
   - Titli must choose the only possible pair `(1, 2)`.  
   - Babli rearranges `{1, 7, 3, 5}` to maximize the sum of differences.  
   - The cost becomes `|7 − 3| + |1 − 5| = 4 + 4 = 8`.

2. **Scenario 2** (`n=3, k=2`):  
   - Titli tries to minimize, but Babli keeps the arrays unchanged to maintain optimal differences.  
   - Final cost: `|1 − 6| + |5 − 2| + |3 − 4| = 5 + 3 + 1 = 9`.

3. **Scenario 3** (`n=5, k=4`):  
   - Babli uses his freedom to rearrange four rounds to maximize mismatches, reaching a cost of `30`.

4. **Scenario 4** (`n=4, k=1`):  
   - With limited rounds, Titli restricts Babli’s power, resulting in a cost of `16`.

5. **Scenario 5** (`n=10, k=10`):  
   - Babli has full control and maximizes every mismatch, yielding `312` arcane coins.
