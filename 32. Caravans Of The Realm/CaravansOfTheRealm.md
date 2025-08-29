# Caravans Of The Realm
## Difficulty – Easy-Medium

The Grand Wizard **Chatur** is observing wizard caravans traveling toward the **Grand Wizard’s Tower**, located at mile `target`. There are `n` caravans, each with:  

- **Starting position** `position[i]` – representing the mile where the caravan begins.  
- **Speed** `speed[i]` – representing the caravan’s speed in miles per hour.  

A caravan **cannot magically pass another caravan**, but it can **catch up**. When it does, the caravans travel together at the **speed of the slower caravan**, forming a **wizard fleet**.  

Your task is to determine the **number of wizard fleets** that will arrive at the Grand Wizard’s Tower.


## Input 
- First line: integer `T` — the number of test cases.  
- For each test case:  
  1. First line: two integers `n` and `target` — number of caravans and the mile of the tower.  
  2. Second line: `n` space-separated integers — `position[i]` for each caravan.  
  3. Third line: `n` space-separated integers — `speed[i]` for each caravan.  


## Output
- For each test case, print a single line: the **number of wizard fleets** that reach the tower.  


### Constraints
- `1 <= T <= 100`  
- `1 <= n <= 10^5`  
- `0 < target <= 10^6`  
- `0 <= position[i] < target`  
- All `position[i]` are unique.  
- `0 < speed[i] <= 10^6`  


## Example

**Input**  
```
1
5 12
10 8 0 5 3
2 4 1 1 3
```

**Output**
```
3
```


## Explanation

- The caravans starting at mile 10 (speed 2) and mile 8 (speed 4) meet and form a fleet at mile 12.  
- The caravan starting at mile 0 (speed 1) does not meet any other caravan and is a fleet by itself.  
- The caravans at miles 5 (speed 1) and 3 (speed 3) form a fleet at mile 6 and move together at speed 1 until reaching the tower.  
