# Spellboard XOR duel (Hard)
## Array, Game theory
-Mahika

Two kingdoms, Eldoria and Drakoria, are fighting over a magical Spellboard filled with numbers. Eldoria always moves first, and then they take turns erasing exactly one number from the board. If erasing a number makes the XOR of all the remaining numbers equal to zero, the player who made that move loses immediately. On the other hand, if it is the beginning of a player’s turn and the XOR of all numbers is already zero, that player wins instantly without making a move. Your task is to determine whether Eldoria, the first kingdom, can always guarantee victory if both kingdoms play with perfect strategy.

## Input
-The first line contains two integers n and m — the number of mages and the number of candidates.
-The next n lines each contain an integer x (1 ≤ x ≤ m), meaning that mage votes for candidate x.

## Output

Print two integers:
-The index of the winning candidate (1-indexed).
-The number of votes they received.

## Example 1

Input: runes = [1,1,2]  
Output: false

## Example 2

Input: runes = [0,1]  
Output: true


## Example 3

Input: runes = [1,2,3]  
Output: true

## Constraints

1 <= runes.length <= 1000

0 <= runes[i] < 2^16
