# Problem: Array of Radiant Runes

A rune in the array is called **radiant** if it **shines brighter than all the runes to its right.**  

Given an array of mystical integers `nums`, return a list of all **radiant runes** in the **original order** they appear in the array.
---

## Input

- `nums` → `vector<int>` of size `n`(the array of runes)  
- `1 <= n <= 10^5`  
- `-10^9 <= nums[i] <= 10^9`  

---

## Output

- A `vector<int>` containing all radiant runes in the **original order**.  

---

## Example 1

**Input:**  
```cpp
nums = [3,7,1,7,8,4]
```
**Onput:**
```
[8,4]
```
---

## Example 2

**Input:**  
```cpp
nums = [5,3,20,15,8]
```
**Onput:**
```
[20,15,8]
```
---

## Example 3

**Input:**  
```cpp
nums = [1,2,3,4,5]
```
**Onput:**
```
[5]
```