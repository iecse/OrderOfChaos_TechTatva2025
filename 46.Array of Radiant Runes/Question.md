# Array of Radiant Stars
## Description
A star in the array is called radiant if it shines brighter than all the stars to its right. 

Given an array of mystical integers `nums`, return a list of all radiant stars in the original order they appear in the array.


### Input

Each test contains multiple test cases.

The first line contains a single integer t (1 ≤ t ≤ 500) — the number of test cases.

The description of the test cases follows.

For each test case:

The first line contains a single integer n (1 ≤ n ≤ 10^5) — the size of the array.

The second line contains n integers nums1, nums2, …, numsn (−10^9 ≤ numsi ≤ 10^9) — the array of runes.

It is guaranteed that the sum of n over all test cases does not exceed 10^5.

### Output

For each test case, output a single line containing the sequence of radiant stars in the original order.

---

## Example

**Input:**

```
3
6
3 7 1 7 8 4
5
5 3 20 15 8
5
1 2 3 4 5
```
**Output:**
```
8 4
20 15 8
5
```

