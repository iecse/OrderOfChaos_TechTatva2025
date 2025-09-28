# Energy Core Synchronization (MEDIUM)
## Greedy
-Mahika
## Problem statement
In the floating citadel of Elyndor, three Ancient Energy Cores (numbered 1, 2, and 3) must each be charged with exactly X units of arcane power in order to awaken the Celestial Gate.

At the beginning, all cores hold 0 energy. A wizard may perform a charging ritual, where in a single ritual he may add any positive amount of energy to one core of his choice.

However, the cores are bound by a Synchronization Seal: After every ritual action, for every pair of cores i, j, the following magical balance must hold:

energy[i] ≥ floor(energy[j] / 2)

Your task is to determine the minimum number of ritual actions required to charge all three cores to exactly X energy units.

## Input
The first line contains an integer t (1 ≤ t ≤ 10⁴) — the number of test cases.

Each of the next t lines contains an integer X (1 ≤ X ≤ 10⁹).

## Output
For each test case, output a single integer — the minimum number of ritual actions required.

## Examples

Input

```
5
1
5
14
2025
31415
```

Output
```
3
7
9
23
31
```
