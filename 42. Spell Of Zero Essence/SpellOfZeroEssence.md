# Spell of Zero Essence  
## Question Difficulty – Hard  

The archmage **Zerath** is experimenting with **magical runes**. He has two sequences of rune energies, **`A`** and **`B`**, each containing **`n` magical units**.  

Zerath wants to create a new sequence of **enchanted runes** **`C`** as follows:  

- Choose a **real magical multiplier** `d` (it doesn’t have to be an integer).  
- For each rune `i` from `1` to `n`, set:  

$$C_i = d \cdot A_i + B_i$$  

Zerath’s goal is to maximize the number of **runes in `C` that have zero essence**.  

Your task is to determine the **largest number of zeroes** that can appear in `C` if `d` is chosen optimally.  


## Input Format  
1. The first line contains an integer `t` — the number of magical trials (test cases).  
2. For each trial:  
   - The first line contains an integer `n` — the number of magical runes.  
   - The second line contains `n` integers `A_1, A_2, ..., A_n` — the energies of the first sequence of runes.  
   - The third line contains `n` integers `B_1, B_2, ..., B_n` — the energies of the second sequence of runes.  

### Constraints
- $1 \le n \le 2 \cdot 10^5$  
- $-10^9 \le A_i, B_i \le 10^9$  


## Output Format  
For each trial, print a single integer — the **maximum number of zeroes** in the sequence `C` that Zerath can achieve by choosing `d` optimally.  


## Example  

**Input:**  
```
4
5
1 2 3 4 5
2 4 7 11 3
3
13 37 39
1 2 3
4
0 0 0 0
1 2 3 4
3
1 2 -1
-6 -12 6
```

**Output**
```
2
2
0
3
```


**Explanation:**  
- **Trial 1**: By choosing `d = -2`, two runes in `C` become zero.  
- **Trial 2**: By choosing `d = -1/13`, two runes in `C` become zero.  
- **Trial 3**: No matter which `d` we choose, we cannot obtain any zero in `C`.  
- **Trial 4**: By choosing `d = 6`, all three runes in `C` become zero.  
