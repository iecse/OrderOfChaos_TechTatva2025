# Great Serpent of Eternity (EASY)  
## Linked list  
-Mahika  

## Problem Statement  
The Great Serpent of Eternity is a mystical creature whose body is made up of enchanted scales, each linked one after another like a chain.  

Each scale contains a rune (an integer). Given the head of the serpent (the first scale), your task is to return the Heart Rune of the serpent — the scale that lies exactly in the middle of its body.  

If the serpent has an odd number of scales, the Heart Rune is the exact center.  

If the serpent has an even number of scales, there are two middle scales, but the Heart Rune is defined as the second one.  

Return the value of the Heart Rune.  

## Input  

- The first line contains an integer **t** — the number of testcases.  
- For each testcase:  
  - The first line contains an integer **n** — the number of coils in the serpent.  
  - The second line contains **n** integers a1, a2, …, an — the energy values of the coils.  

## Output  

For each testcase, output a single integer — the Heart Rune of the serpent.  

## Constraints  

- 1 ≤ t ≤ 10^2  
- 1 ≤ n ≤ 2 * 10^5  
- 0 ≤ ai ≤ 10^4  
- The sum of n across all testcases does not exceed 2 * 10^5.  

## Example  

**Input** 
```
2
5
10 20 30 40 50
6
7 13 21 34 55 89
```

**Output**
```
30
34
```

