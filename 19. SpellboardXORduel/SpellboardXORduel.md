# Spellboard XOR duel (Hard)
## Array, Game theory
-Mahika

Two kingdoms, Eldoria and Drakoria, are fighting over a magical Spellboard filled with numbers. Eldoria always moves first, and then they take turns erasing exactly one number from the board. If erasing a number makes the XOR of all the remaining numbers equal to zero, the player who made that move loses immediately. On the other hand, if it is the beginning of a player’s turn and the XOR of all numbers is already zero, that player wins instantly without making a move. Your task is to determine whether Eldoria, the first kingdom, can always guarantee victory if both kingdoms play with perfect strategy.

## Input

The first line contains an integer t (1 ≤ t ≤ 10⁴) — the number of test cases.

The first line of each test case contains an integer n (1 ≤ n ≤ 1000) — the number of numbers on the Spellboard.

The second line contains n integers a₁, a₂, …, aₙ (0 ≤ aᵢ < 2¹⁶) — the numbers on the Spellboard.

## Output

For each test case, print YES if Eldoria can guarantee victory, otherwise print NO.

## Example

Input

```
3
3
1 1 2
2
0 1
3
1 2 3
```

Output

```
NO
YES
YES
```
## Constraints

1 <= runes.length <= 1000

0 <= runes[i] < 2^16
