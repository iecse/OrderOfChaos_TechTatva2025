# Guild Of Magical Hiring
## Difficulty – Medium

The Grand Wizard **Chatur** is forming a special squad of apprentices. There are `n` wizards available. Each wizard has:  

- **Power level** `power[i]` – representing their magical strength.  
- **Minimum gold demand** `gold[i]` – the least gold they expect to join the squad.  

To hire a squad of **exactly `k` wizards**, the following rules must be satisfied:

1. Every wizard must receive **at least their demanded gold**.  
2. **Pay must be proportional to power levels**: if wizard A has double the power of wizard B, then wizard A must be paid double the gold of B.  

Your task is to determine the **minimum total gold** needed to hire a squad of `k` wizards satisfying these conditions.  

Answers within `10^-5` of the actual value will be accepted.


## Input 
- First line: integer `T` — the number of test cases.  
- For each test case:  
  1. First line: two integers `n` and `k` — number of wizards and squad size.  
  2. Second line: `n` space-separated integers — `power[i]` for each wizard.  
  3. Third line: `n` space-separated integers — `gold[i]` for each wizard.  


## Output 
- For each test case, print a single line: the **minimum total gold** needed to hire the squad of `k` wizards, rounded to **5 decimal places**.  


### Constraints
- `1 <= T <= 100`  
- `1 <= k <= n <= 10^4`  
- `1 <= power[i], gold[i] <= 10^4`  

## Example

**Input**  
```
2
3 2
10 20 5
70 50 30
5 3
3 1 10 10 1
4 8 2 2 7
```


**Output**  
```
105.00000
30.66667
```

## Explanation

**Test case 1:**  
- Hire the 0th and 2nd wizards.  
- Total gold = 70 + 35 = 105.00000.  

**Test case 2:**  
- Hire the 0th, 2nd, and 3rd wizards.  
- Total gold = 4 + 13.33333 + 13.33333 ≈ 30.66667.  
