# Spell of Twin Energies  
## Question Difficulty – Medium  

The great wizard **Rudra** has discovered a mysterious **magical crystal** containing **`c` units of pure energy**.  

According to ancient scrolls, this crystal can only be **stabilized** if its energy can be split into **two perfect magical squares**.  

In other words, Rudra must determine whether there exist two integers **`a`** and **`b`** such that:  

$a^2 + b^2 = c$  

where $a^2$ represents the energy of the **first spell rune** and $b^2$ represents the energy of the **second spell rune**.  


## Input Format  
1. The first line contains a single integer `t` — the number of test cases.  
2. Each of the next `t` lines contains a single integer `c`, the energy of the magical crystal.  

## Output Format  
For each test case, print:  
- `true` if Rudra can stabilize the crystal using two perfect spell squares.  
- `false` otherwise. 

## Example  

**Input:**  
```
2
5
3
```

**Output:**  
```
true
false
```

**Explanation:**  
- For `c = 5`: The crystal’s energy can be split as $1^2 + 2^2 = 5$. So Rudra succeeds.  
- For `c = 3`: No combination of magical runes adds up to **3**. The crystal remains unstable.  

## Constraints
- $1 \leq t \leq 10^3$  
- $0 \leq c \leq 2^{31} - 1$ 