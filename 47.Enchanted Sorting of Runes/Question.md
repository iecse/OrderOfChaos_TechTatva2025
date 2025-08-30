# Enchanted Sorting of Runes

You are given an array of mystical runes `nums`.  
Your task is to perform a **dual enchantment:**
- **Even runes** must be aligned in **ascending order of power** (weakest to strongest).
- **Odd runes** must be aligned in **descending order of power**.(strongest to weakest).
- But beware! Each rune must **remain bound to its original slot** in the array — even runes only swap with other even runes, and odd runes only with other odd runes.
---

## Example 1:

**Input:**  
```txt
runes = [5, 2, 8, 7, 1, 4]
```

**Output**
```
[7, 2, 4, 5, 1, 8] 
```
---

## Example 2

**Input:**  
```cpp
runes = [9, 4, 1, 6, 3, 8]
```
**Onput:**
```
[9, 4, 3, 6, 1, 8]
```
## Example 3

**Input:**  
```cpp
runes = [10, 21, 32, 43, 54]
```
**Onput:**
```
[10, 43, 32, 21, 54]
```