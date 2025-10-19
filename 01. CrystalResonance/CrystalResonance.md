# Crystal Resonance

**Question Difficulty: Easy**

## Problem

In the realm of Aethermoor, Wizard Elara experiments with arranging enchanted crystals. She wants to create a _resonance chain_ where the first and last crystals are identical, forming a closed magical loop.

Elara has several collections of crystals. For each collection, you must decide whether it is possible to rearrange the crystals so that **the first and last crystals in the sequence have the same power level**.

If such an arrangement is possible, the collection achieves _perfect resonance_.

## Input

- The first line contains an integer **t** (1 ≤ t ≤ 1000) — the number of test cases.
- For each test case:
  - The first line contains an integer **n** (2 ≤ n ≤ 100) — the number of crystals in the collection.
  - The second line contains **n integers** `p₁, p₂, …, pₙ` (2 ≤ pᵢ ≤ 100) — the power levels of the crystals.

## Constraints

- 1 ≤ t ≤ 1000
- 2 ≤ n ≤ 100
- 2 ≤ pᵢ ≤ 100

## Output

For each test case, output:

- `"YES"` if at least two crystals have the same power level (so Elara can place them at the beginning and end),
- `"NO"` otherwise.

## Example

### Input

```
5
2
7 7
4
8 4 8 12
2
3 5
7
42 14 18 14 14 12 24
5
3 6 12 24 48
```

### Output

```
YES
YES
NO
YES
NO
```

_Question designed by [Abhyuday-Gupta912](https://github.com/Abhyuday-Gupta912)_
