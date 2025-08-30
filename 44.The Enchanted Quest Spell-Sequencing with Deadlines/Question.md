# Problem: The Enchanted Quest: Spell Sequencing with Deadlines

You are given `n` mystical spells (jobs). Each spell holds:  
- a Rune of Identity  **id**(unique id)
- a **Deadline Sigil** (the job must be completed on or before this deadline)  
- a **Treasure Value** (if the spell is completed before the deadline).  

Each job takes **1 unit of cosmic time** to complete.  
Only **one spell** can be scheduled at a time.  

Your mission, young sorcerer, is to maximize your **Treasure** Collection by selecting and scheduling **spells** wisely.  


---

## Example 1:
**Input:**  
n = 4  
Spells = [[1, 4, 20], [2, 1, 10], [3, 1, 40], [4, 1, 30]]  

**Output:**  
[3, 1], 60  

**Explanation:**  
- Spell 3 (Treasure 40, deadline 1) is scheduled at time Rune 1.  
- Spell 1 (Treasure 20, deadline 4) is scheduled at time Rune 4.  
- Total Treasure = 40 + 20 = **60**.  

---

## Example 2:
**Input:**  
n = 5  
Spells = [[1, 2, 100], [2, 1, 19], [3, 2, 27], [4, 1, 25], [5, 1, 15]]  

**Output:**  
[1, 3], 127  

**Explanation:**  
- Spell 1 (profit 100, deadline 2) is scheduled at time Rune 2.  
- Spell 3 (profit 27, deadline 2) is scheduled at time Rune 1.  
- Total Treasure = 127.  

---

## Example 3:
**Input:**  
n = 3  
Spells = [[1, 3, 15], [2, 2, 20], [3, 1, 30]]  

**Output:**  
[3, 2, 1], 65  

**Explanation:**  
- Spell 3 (Treasure 30, deadline 1) is scheduled at time Rune 1.  
- Spell 2 (Treasure 20, deadline 2) is scheduled at time Rune 2.  
- Spell 1 (Treasure 15, deadline 3) is scheduled at time Rune 3.  
- Total Treasure = 30 + 20 + 15 = **65**.  
