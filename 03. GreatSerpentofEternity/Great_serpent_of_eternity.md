# Great Serpent of Eternity (EASY) 
## Linked list
-Mahika


## Problem Statement
The Great Serpent of Eternity is a mystical creature whose body is made up of enchanted scales, each linked one after another like a chain.

Each scale contains a rune (an integer). Given the head of the serpent (the first scale), your task is to return the Heart Rune of the serpent — the scale that lies exactly in the middle of its body.

If the serpent has an odd number of scales, the Heart Rune is the exact center.

If the serpent has an even number of scales, there are two middle scales, but the Heart Rune is defined as the second one.

Return the node that represents this Heart Rune.

## Input

1. The first line contains an integer n — the number of coils in the serpent.
2. The second line contains n integers a1, a2, …, an — the energy values of the coils.

## Output
If synchronization is impossible, print -1. Otherwise, print a single integer: the minimum number of energy transfers required to synchronize the serpent.

## Constraints

1 ≤ n ≤ 2 * 10^5
0 ≤ ai ≤ 10^9

## Example 1

Input: serpent = [10, 20, 30, 40, 50]
Output: 30

Explanation:
The serpent has 5 scales. The middle is the 3rd scale (value 30).

## Example 2

Input: serpent = [7, 13, 21, 34, 55, 89]
Output: 34

Explanation:
The serpent has 6 scales. The two middle scales are 21 and 34. By the serpent’s rule, we choose the second middle → 34.



