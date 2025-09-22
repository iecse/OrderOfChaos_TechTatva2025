# Scroll of Balance (Medium)
-Mahika

In the land of Bharatavarsha, two mages wandered: Arjun, the Harmonizer, and Aarambh, the Trickster. Arjun carried the calm light of the moon, seeking balance. Aarambh carried the fire of mischief, twisting spells for chaos.
One summer, they discovered two ancient scrolls of runes, Scroll A and Scroll B, each holding n runes. They agreed to play a magical game lasting k rounds.

In each round:
-Aarav chose two rune positions i and j (1 ≤ i < j ≤ n).
-Bhavesh rearranged the four runes a[i], a[j], b[i], b[j] in any way, even swapping between scrolls.
-At the end of all k rounds, the imbalance between the scrolls was measured:
v = Σ |a[i] − b[i]|
This imbalance became the number of destiny coins. Arjun wished to minimize v, while Aarambh wished to maximize it. You must determine the final number of coins if both play optimally.

## Input

-The first line contains an integer t: the number of test cases.

For each test case:
-The first line contains two integers n and k: the number of runes and rounds.
-The second line contains n integers a[1..n]: runes in Scroll A.
-The third line contains n integers b[1..n]: runes in Scroll B.

## Output

For each test case, output a single integer — the final number of destiny coins.

## Constraints

1 ≤ t ≤ 1000

1 ≤ n ≤ 50

0 ≤ k ≤ n

1 ≤ a[i], b[i] ≤ 100

## Example
Input
```
2
3 1
1 2 3
3 2 1
4 2
1 2 3 4
10 11 12 13
```
Output
```
2
28
```
