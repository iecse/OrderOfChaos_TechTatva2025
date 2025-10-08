#  Hidden Multiplication of the Arcane Scroll
## Difficulty : 
Long ago, the sage Artem discovered a secret of the Arcane Scroll of Numbers.
He chose a hidden number x and, to mask its true form, he performed two mystical acts:

- He summoned a power of ten (10^k, with k ≥ 1).

- He multiplied x by this power and then bound the two numbers together into one:
```
n = x + (x ⋅ 10^k)
n = x ⋅ (1 + 10^k)
```

## Input  

- The first line contains an integer t  — the number of test cases.

- Each of the next t lines contains a single integer n .

## Output  
For each test case, output:

- 0 if no such x exists.

- Otherwise, first print the number of possible x values, followed by the values in ascending order.  


## Example  

**Input**  

```
2
121
1100
```
**Output**  

```
1 11
1 100
```
### Constrain
- 1 ≤ t ≤ 10^4<br>
- 11 ≤ n ≤ 10^18