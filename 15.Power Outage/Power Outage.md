# Power Outage

**time limit per test:** 1 second  
**memory limit per test:** 256 megabytes  

Arun lives in a building corridor with `n` light bulbs in a row, numbered from `1` to `n`. He needs to walk through the corridor from bulb `1` to bulb `n`, one step per second.  

Each bulb can either be working (`0`) or fused (`1`).  

- If a bulb is working, Arun can safely step under it in **1 second**.  
- If a bulb is fused, the corridor is dark and Arun **cannot step forward**.  

Luckily, Arun has a **flashlight** that he can switch on at most **once**.  
- When switched on, all fused bulbs appear lit for the next `x` seconds.  
- After that, the flashlight battery is dead, and Arun cannot turn it on again.  

Your task is to determine if Arun can walk through the whole corridor and reach the end (past bulb `n`).  

---

## Input
- The first line contains an integer `t` (`1 ≤ t ≤ 1000`) — the number of test cases.  
- Each test case contains:  
  - A line with two integers `n, x` (`1 ≤ n, x ≤ 10`) — the number of bulbs and the number of seconds the flashlight lasts.  
  - A line with `n` integers `a1, a2, …, an` (`ai ∈ {0,1}`) — the state of each bulb.  
    - `0` = working bulb.  
    - `1` = fused bulb.  

It is guaranteed that each test case contains at least one fused bulb.  

---

## Output
For each test case, print `"YES"` if Arun can reach the end of the corridor, and `"NO"` otherwise.  
You can print each letter in any case (upper or lower).  

---

## Example

**Input**  
```
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
---
## Explanation
- In the first test case: Arun can walk until bulb 2. At this point, he switches on the flashlight, which lasts 2 seconds. It lights up bulbs 2 and 3, letting him reach bulb 4, which is already working. Then he continues safely to bulb 5.   

- In the second test case: Even with the flashlight, Arun cannot pass through 3 consecutive fused bulbs because the flashlight only lasts 1 second. 
