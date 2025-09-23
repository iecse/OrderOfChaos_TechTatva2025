#  The Corridor of Eternal Night  

Arun the Wanderer must journey through the **Corridor of Eternal Night**, where `n` **Runestones of Light** line the path, numbered from `1` to `n`.  

- A runestone may **shine** (`0`) or be **shattered** (`1`).  
- If a runestone shines, Arun may safely step beneath it in **1 heartbeat**.  
- If a runestone is shattered, the darkness forbids him from stepping forward.  

But Arun carries an **Ancient Lantern**, imbued with a single **flash rune**.  
- When invoked, the lantern **banishes the shadows** for the next `x` heartbeats.  
- During this time, Arun may walk as if all runestones shine, even the shattered ones.  
- Once the rune’s power fades, the lantern becomes nothing more than an empty husk, never to glow again.  

Your mission: Determine whether Arun can reach the **end of the corridor** (past runestone `n`) without being trapped forever in the abyss.  

---

##  Input  
- The first line reveals an integer `t` (`1 ≤ t ≤ 1000`) — the number of trials.  
- Each trial contains:  
  - Two integers `n, x` (`1 ≤ n, x ≤ 10`) — the number of runestones and the lifespan of the lantern’s rune.  
  - A sequence of `n` integers `a1, a2, …, an` (`ai ∈ {0,1}`) — the fate of each runestone.  
    - `0` → shining runestone.  
    - `1` → shattered runestone.  

It is foretold that every trial holds at least one shattered runestone.  

---

## Output  
For each trial, whisper **“YES”** if Arun can escape the Corridor of Eternal Night, or **“NO”** if the darkness devours him.  

---

##  Example  

**Input**  
---
```
5 2
0 1 1 0 0
4 1
0 1 1 1
```
**Output**  

---
```
YES
NO
```
---

##  Prophecy Explained  
- In the **first trial**, Arun strides until runestone 2. The shadows gather — he invokes the lantern. For 2 heartbeats, even shattered runestones appear radiant, letting him step over runestones 2 and 3. By the time the rune fades, he stands at runestone 4, which shines on its own. The path is safe → **YES**.  

- In the **second trial**, 3 shattered runestones bar the way, yet the lantern shines only for 1 heartbeat. The abyss wins → **NO**.  

---