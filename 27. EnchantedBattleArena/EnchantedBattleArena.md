# The Enchanted Battle Arena

**Question Difficulty: Medium**

## Description:

In the mystical realm of Aethermoor, Grand Strategist Morgana has assembled an elite squadron of n magical warriors in her enchanted battle arena, each possessing unique arcane power levels. The i-th warrior channels aᵢ ≥ 0 units of magical energy, ready to unleash devastating spells upon her command.

When Morgana commands a warrior to cast their ultimate spell, a magnificent chain reaction occurs: the warrior releases all their stored energy to empower the next aᵢ warriors in the formation, each gaining exactly 1 additional power unit. However, this ultimate spell completely drains the casting warrior, reducing their power to 0. Warriors with 0 initial power cannot boost anyone, but they can still receive power from others' spells.

Morgana's ancient battle doctrine requires that **each warrior must cast their ultimate spell exactly once** during the engagement. The order of casting is entirely under her strategic control - she can command any warrior at any moment, as long as they haven't already cast their spell.

However, there's a crucial mystical constraint: the **Sacred Law of Ascending Power** demands that after all ultimate spells have been cast, the final power levels must form a **non-decreasing sequence**. This means for any i < j, the warrior at position i must not possess more power than the warrior at position j, lest the magical balance of the arena be shattered.

Your task is to help Morgana determine the maximum **Mystical Exclusion Number (MEN)** she can achieve with her optimal casting strategy.

The **MEN** of an array represents the smallest non-negative integer power level that is not present among any warrior in the final formation.

## Input:

The first line contains a single integer t (1 ≤ t ≤ 10⁴) - the number of battle scenarios Morgana must analyze.

For each battle scenario:

- The first line contains one integer n (1 ≤ n ≤ 10⁵) - the number of warriors in the formation
- The second line contains n integers a₁, a₂, ..., aₙ (0 ≤ aᵢ ≤ 10⁹) - the initial power levels of the warriors

It is guaranteed that the sum of n over all test scenarios does not exceed 10⁵.

## Output:

For each battle scenario, output a single integer - the maximum MEN that Morgana can achieve with her optimal strategy.

## Constraints:

- Number of scenarios: 1 ≤ t ≤ 10⁴
- Warriors per scenario: 1 ≤ n ≤ 10⁵
- Initial power levels: 0 ≤ aᵢ ≤ 10⁹
- Total warriors across all scenarios: ≤ 10⁵

## Example:

### Input:

```
8
2
1 2
4
2 1 0 0
10
5 9 3 7 1 5 1 5 4 3
10
1 1 1 1 1 1 1 1 1 1
10
3 2 1 0 3 2 1 0 3 2
5
5 2 0 5 5
1
1000000000
7
4 0 1 0 2 7 7
```

### Output:

```
2
3
7
4
5
4
1
3
```

## Explanation:

**Test Case 1:** With warriors [1, 2]:

- Initial state: [1, 2]
- Cast warrior 2's spell first: [1+2, 0] = [3, 0]
- Cast warrior 1's spell: [0, 0+1] = [0, 1]
- Final state: [0, 1], MEN = 2

**Test Case 2:** With warriors [2, 1, 0, 0]:

- Through optimal spell casting order, we can achieve a final formation like [0, 1, 2, 3] or similar
- The maximum MEN achievable is 3

**Test Case 4:** All warriors have power 1, so each can boost exactly one adjacent warrior. With optimal strategy, we can create a sequence containing power levels 0, 1, 2, 3, making MEN = 4.

---

## Notes:

- Warriors cast their ultimate spells based on Morgana's strategic timing
- The Sacred Law of Ascending Power must be maintained in the final formation
- Each ultimate spell empowers the next aᵢ warriors in the sequence (if they exist)
- Warriors beyond the formation boundary receive no power boosts
- The MEN represents the first "gap" in the power level sequence

---

_Question designed by [Abhyuday-Gupta912](https://github.com/Abhyuday-Gupta912)_
