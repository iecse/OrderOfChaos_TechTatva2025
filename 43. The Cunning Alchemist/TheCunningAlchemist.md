# The Cunning Alchemist 
## Question Difficulty – Easy  

The cunning alchemist **Zerathus** discovered a special type of **magical potion**. He realized that selling them cleverly could increase his profit.  

Now, he can create **$$3^x$$ potions** in a single batch, which can be sold for **$$3^{x+1} + x \cdot 3^{x-1}$$ gold coins**, where `x` is a non-negative integer. Each batch sale is called a **deal**.  

A hasty apprentice comes to buy exactly `n` potions, but he wants to make the **least number of deals** possible.  

Your task is to determine the **minimum number of gold coins** the apprentice must pay to buy exactly `n` potions using the fewest deals.  


## Input Format  
1. The first line contains an integer `t` — the number of magical trials (test cases).  
2. Each of the next `t` lines contains a single integer `n` — the exact number of potions the apprentice wants to buy.  

### Constraints
- $1 \le t \le 10^4$  
- $1 \le n \le 10^9$  


## Output Format  
For each trial, print a single integer — the **minimum gold coins** the apprentice must pay.  


## Example  

**Input:**  
```
7
1
3
8
2
10
20
260010000
```

**Output**
```
3
10
26
6
36
72
2250964728
```

## Explanation:

- Note that there is no point in creating or buying **more potions than needed**, so deals that exceed the required number are ignored.  

- The **first few deal options** are:  
  - Deal A: 1 potion → 3 gold coins  
  - Deal B: 3 potions → 10 gold coins  

- **Trial 1**: Buy 1 potion - only Deal A is possible - cost = 3 coins.  
- **Trial 2**: Buy 3 potions - use Deal B - cost = 10 coins.  
- **Trial 3**: Buy 8 potions - combine deals: 2 Deal A + 2 Deal B - total cost = 26 coins.  
- **Trial 4**: Buy 2 potions - 2 Deal A - cost = 6 coins.  
- **Trial 5**: Buy 10 potions - combine deals optimally - cost = 36 coins.  
- **Trial 6**: Buy 20 potions - combine deals optimally - cost = 72 coins.  
- **Trial 7**: Buy 260010000 potions - combine deals optimally - cost = 2250964728 coins.  

- The key idea is to **minimize the number of deals** while paying the **least coins**, without exceeding the required number of potions.
