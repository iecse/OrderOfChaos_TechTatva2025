# The Enchanted Quest: Spell Sequencing with Deadlines

You are given `n` mystical spells (jobs). Each spell holds:  
- a Rune of Identity  id (unique id)
- a Deadline Sigil (the job must be completed on or before this deadline)  
- a Treasure Value (if the spell is completed before the deadline).  

Each job takes 1 unit of cosmic time to complete.  
Only one spell can be scheduled at a time.  

Your mission, young sorcerer, is to maximize your Treasure Collection by selecting and scheduling spells wisely.  


---
## Input

- The first line contains an integer t (1 ≤ t ≤ 500)  the number of test cases.

- The description of each test case follows.

- The first line of each test case contains a single integer n (1 ≤ n ≤ 10^5) — the number of spells.

- The next n lines each contain three integers:

    - id — the Rune of Identity (1 ≤ id ≤ n, unique),

    - deadline — the Deadline Sigil (1 ≤ deadline ≤ n),

    - treasure — the Treasure Value (1 ≤ treasure ≤ 10^4).

- It is guaranteed that the sum of n over all test 
cases does not exceed 10^5.
## Output

For each test case, output two things:

- The sequence of spell IDs scheduled in the order of their cosmic execution.

- The total Treasure Value collected.
## Example :
**Input:**  
3
4
1 4 20
2 1 10
3 1 40
4 1 30
5
1 2 100
2 1 19
3 2 27
4 1 25
5 1 15
3
1 3 15
2 2 20
3 1 30

**Output:**  
3 1
60
1 3
127
3 2 1
65

