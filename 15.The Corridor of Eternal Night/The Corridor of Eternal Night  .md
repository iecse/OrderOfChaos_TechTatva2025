#  The Corridor of Eternal Night  
## Difficulty: 
Arun the Wanderer must journey through the Corridor of Eternal Night, where n Stones of Light line the path, numbered from 1 to n.

- A stone may shine (0) or be shattered (1).

- If a stone shines, Arun may safely step beneath it in 1 second.

- If a stone is shattered, the darkness forbids him from stepping forward.

But Arun carries an Ancient Lantern, imbued with a single flash sigil.

- When invoked, the lantern banishes the shadows for the next x seconds.

- During this time, Arun may walk as if all stones shine, even the shattered ones.

- Once the sigil’s power fades, the lantern becomes nothing more than an empty husk, never to glow again.

Your mission: Determine whether Arun can reach the end of the corridor (past stone n) without being trapped forever in the abyss.

##  Input  
The first line reveals an integer t  — the number of trials.

Each trial contains:

- Two integers n, x  — the number of stones and the lifespan of the lantern’s sigil.

- A sequence of n integers a1, a2, …, an  — the fate of each stone.

    - 0 → shining stone.

    - 1 → shattered stone.

It is foretold that every trial holds at least one shattered stone.

## Output  
For each trial, whisper “YES” if Arun can escape the Corridor of Eternal Night, or “NO” if the darkness devours him.


##  Example  

**Input**  

```
2
5 2
0 1 1 0 0
4 1
0 1 1 1

```
**Output**  


```
YES
NO
```
### Constrain
- 1 ≤ n, x ≤ 10<br>
- 1 ≤ t ≤ 1000<br>
- ai ∈ {0,1}