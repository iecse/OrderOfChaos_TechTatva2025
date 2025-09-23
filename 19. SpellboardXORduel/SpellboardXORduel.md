# Spellboard XOR duel (Hard)
## Array, Game theory
-Mahika
## Problem statement 
You are given an array of integers runes representing the magical runes inscribed on an ancient Spellboard. The archmages Gandalf the Grey and Morgana the Enchantress take turns erasing exactly one rune from the Spellboard, with Gandalf starting first. If erasing a rune causes the combined magical resonance (the bitwise XOR of all remaining runes) to become 0, then that mage loses immediately, as the spell collapses on them.
If any mage begins their turn and the combined magical resonance is already 0, then that mage wins instantly, since the spell has aligned in their favor.
Return true if and only if Gandalf (the first mage) can guarantee victory, assuming both mages play with perfect magical strategy.

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


Explanation:
Gandalf has two choices:
If he erases the rune 1, the Spellboard becomes [1,2]. The resonance is 1 XOR 2 = 3. Morgana can then erase whichever rune she wants, and Gandalf will be forced to erase the final rune, collapsing the spell and losing.

If Gandalf erases the rune 2, the Spellboard becomes [1,1]. The resonance is 1 XOR 1 = 0. Gandalf loses immediately.

Thus, Gandalf cannot win.

## Example 2

Input: runes = [0,1]  
Output: true


## Example 3

Input: runes = [1,2,3]  
Output: true

## Constraints

1 <= runes.length <= 1000

0 <= runes[i] < 2^16
