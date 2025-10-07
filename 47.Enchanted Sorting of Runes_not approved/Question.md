# Enchanted Sorting of Magic Stones
## Description:
You are given an array of mystical stones `nums`.  
Your task is to perform a dual enchantment:
- Even magic stone must be aligned in ascending order of power (weakest to strongest).
- Odd runes must be aligned in descending order of power.(strongest to weakest).
- But beware! Each stone must remain bound to its original slot in the array — even runes only swap with other even stones, and odd stones only with other odd stones.
---
## Input
- Each test contains multiple test cases.

- The first line contains a single integer t (1 ≤ t ≤ 500) — the number of test cases.

- The description of the test cases follows.

- For each test case:

- The first line contains a single integer n (1 ≤ n ≤ 10^5) — the size of the array.

- The second line contains n integers stone1, stone2, …, stonen (−10^9 ≤ stonei ≤ 10^9).

- It is guaranteed that the sum of n over all test cases does not exceed 10^5.
## Output

- For each test case, output the transformed array of stone on a single line.
## Example :

**Input:**  
```
3
6
5 2 8 7 1 4
6
9 4 1 6 3 8
5
10 21 32 43 54
```

**Output**
```
7 2 4 5 1 8
9 4 3 6 1 8
10 43 32 21 54
```
---

