# Wizard’s Guests
## Question Difficulty - Medium

The young wizard **Chulbul** is expecting two guests: his **brother** and his **mother**. Each guest will stay for **`d` consecutive days** in his tower, numbered from day `1` to day `n`.  

Meanwhile, Chulbul has **`k` magical quests** scheduled, each lasting over a continuous range of days `[l_i, r_i]`. If a guest’s stay overlaps a quest, that quest may disturb them.  

Chulbul wants to choose the visit days carefully:

- **Brother** - should experience **as many quests as possible**  
- **Mother** - should experience **as few quests as possible**  

If multiple start days give the same result, choose the **earliest possible day**.  


## Input

- The first line contains a single integer `t` (1 ≤ t ≤ 10^4) — the number of scenarios.  
- Each scenario consists of:  
  - A line with three integers `n, d, k` (1 ≤ n ≤ 10^5, 1 ≤ d, k ≤ n) — total days, duration of each visit, and number of quests.  
  - Next `k` lines, each containing two integers `l_i, r_i` (1 ≤ l_i ≤ r_i ≤ n) — start and end day of each quest.  

It is guaranteed that the sum of all `n` over all test cases does not exceed 2·10^5.  


## Output

For each scenario, print **two integers**:  

1. The **earliest start day** for the brother’s visit  
2. The **earliest start day** for the mother’s visit  

Both visits must be entirely within days `1` to `n`.  


## Example

**Input**  
```
6
2 1 1
1 2
4 1 2
1 2
2 4
7 2 3
1 2
1 3
6 7
5 1 2
1 2
3 5
9 2 1
2 8
9 2 4
7 9
4 8
1 3
2 3
```

**Output**  
```
1 1
2 1
1 4
1 1
1 1
3 4
```


## Explanation

1. **Scenario 1**: Only 1 quest covers all days - both visits start on day 1.  
2. **Scenario 2**:  
   - Brother wants **max overlap** - day 2 overlaps 2 quests - starts on day 2  
   - Mother wants **min overlap** - day 1 overlaps only 1 quest - starts on day 1  
3. **Scenario 3**:  
   - Quests are on [1,2], [1,3], [6,7]  
   - Brother - days [1,2] - overlaps 2 quests  
   - Mother - days [4,5] - overlaps 0 quests  

The rest of the scenarios follow the same logic, always picking the **earliest day** for the required overlap.
