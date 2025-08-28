# The Lever of Divergia
## Question Difficulty: Easy



In the mystical realm of **Divergia**, two enchanted arrays of numbers exist:  
- The **Array of Flame** (`a`)  
- The **Array of Frost** (`b`)  

Both arrays contain exactly `n` numbers each.  

---

## The Ritual of the Lever
The ancient artifact known as **The Lever** iterates through magical steps. In each iteration, it performs the following ritual:

1. The Lever seeks an index `i` where the **Flame rune** is **greater** than the Frost rune (`a[i] > b[i]`).  
   - If such an index exists, the Lever **reduces** the Flame rune (`a[i] = a[i] - 1`).  
   - If no such index exists, this step is ignored.  

2. The Lever then seeks an index `i` where the **Flame rune** is **less** than the Frost rune (`a[i] < b[i]`).  
   - If such an index exists, the Lever **increases** the Flame rune (`a[i] = a[i] + 1`).  
   - If no such index exists, this step is ignored.  

3. After each iteration, if Step 1 was ignored (i.e., no Flame rune was greater than its Frost counterpart), the Lever’s magic ceases and the ritual ends.  

---

## The Task
Given the two enchanted arrays `a` and `b`, determine the **exact number of iterations** the Lever will perform before its power fades.  

It is foretold that this number is **unique** and does not depend on which runes the Lever chooses in each step.

---

## Input
- The first line contains the number of test cases `t` (`1 ≤ t ≤ 10^4`).  
- For each test case:  
  - The first line contains an integer `n` (`1 ≤ n ≤ 10`).  
  - The second line contains `n` integers, the **Array of Flame** `a` (`1 ≤ a[i] ≤ 10`).  
  - The third line contains `n` integers, the **Array of Frost** `b` (`1 ≤ b[i] ≤ 10`).  

---

## Output
For each test case, return the **number of iterations** that the Lever performs before halting.  

## Example

**Input**  
```
2
3
5 2 3
2 2 4
4
1 5 3 2
2 2 3 5
```

**Output**  
```
3
3
```



---

### Explanation of Example

- **Test Case 1**:  
  - Arrays: `a = [5,2,3]`, `b = [2,2,4]`  
  - Differences: `(5→2 needs 3 decrements)`, `(3→4 needs 1 increment)`  
  - Total iterations = `3`.  

- **Test Case 2**:  
  - Arrays: `a = [1,5,3,2]`, `b = [2,2,3,5]`  
  - Differences: `(5→2 needs 3 decrements)`; other elements only need increments (which don’t affect termination).  
  - Total iterations = `3`.  

---
~ <a href=https://github.com/r1shu-R> Rishabh </a>
