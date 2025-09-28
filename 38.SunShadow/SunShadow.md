## The Celestial Duel: Convergence of Sunfire and Moonshadow

In the mystical realm of Aethel, two opposing schools of magic, **Sunfire** and **Moonshadow**, are locked in an eternal struggle. You are a Celestial Arbiter, tasked with observing the outcome of their magical duels along a **sacred ley line**.

The duel is represented by a sequence of spells, each with a specific power:

  * **Sunfire Spells** are cast from the left and travel right. Their power is a **positive** integer.
  * **Moonshadow Spells** are cast from the right and travel left. Their power is a **negative** integer.

When a spell is cast, it travels along the ley line until it either exits or collides with an opposing spell. The rules of collision are precise:

1.  A collision occurs when a right-moving Sunfire spell meets a left-moving Moonshadow spell.
2.  When they collide, the spell with the lower absolute power is **dissipated**. The more powerful spell's energy is **diminished** by the power of the one that was dissipated.
3.  If two opposing spells of equal absolute power collide, they **annihilate** each other, and both are removed.
4.  Spells of the same type (e.g., two Sunfire spells) never collide and continue along the ley line in formation.

After all collisions have resolved, the duel's outcome is judged. If the final sequence of spell powers on the ley line is a **palindrome**, the outcome is **Harmonious**. Otherwise, it is **Chaotic**. Your task is to simulate the duel and predict the outcome.

-----

## Input Format

The first lines contains number of Test cases.

For each test case:

1. The first line contains an integer **`n`** ($1 \le n \le 10^5$) — the number of spells.  
2. The second line contains `n` space-separated integers $s_1, s_2, \dots, s_n$ ($-1000 \le s_i \le 1000$, $s_i \ne 0$) — the power of each spell.  

The sum of **`n`** over all test cases will not exceed $10^5$.

-----

## Output Format

For each test case, print a single string, `"Harmonious"` or `"Chaotic"`, on a new line.

-----

## Example 1

**Input**

```
1
4
5 10 -8 5
```

**Output**

```
Harmonious
```

-----

## Example 2

**Input**

```
1
5
10 6 -4 -8 5
```

**Output**

```
Chaotic
```

-----

*Question designed by Kushal [rkushell](https://github.com/rkushell)*