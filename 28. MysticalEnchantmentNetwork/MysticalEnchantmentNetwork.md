# The Mystical Enchantment Network

**Question Difficulty: Hard**

## Description:

In the ancient kingdom of Aethermoor, the Royal Enchantress Seraphina has discovered a mystical network of n sacred crystals scattered across the realm. These crystals are connected by m magical ley lines, each ley line linking two crystals with powerful arcane energy. However, a dark prophecy warns that the network contains unstable magical resonances that could tear apart the fabric of reality itself.

To prevent catastrophe, Seraphina must perform the Ritual of Harmonic Balance. This ancient ritual requires her to sever exactly one ley line from the network, then enchant each crystal with either Solar magic (represented by red) or Lunar magic (represented by blue). The ritual succeeds only if no remaining ley line connects two crystals of the same magical affinity.

The Royal Court is desperate to know which ley lines can be severed while still allowing the Ritual of Harmonic Balance to succeed. Your task is to help Seraphina identify all such ley lines and save the kingdom from magical destruction.

## Input:

The first line contains two integers n and m (1 ≤ n ≤ 10⁴, 0 ≤ m ≤ 10⁴) - the number of sacred crystals and magical ley lines respectively.

The following m lines contain descriptions of the ley lines. Each line contains two integers v, u (1 ≤ v ≤ n, 1 ≤ u ≤ n) - the indices of crystals connected by this ley line. No ley line appears twice in the input.

## Output:

In the first line, output k - the number of ley lines that can be severed to allow the ritual to succeed.

In the second line, output k space-separated integers - the indices of these ley lines in ascending order. Each index should appear only once. Ley lines are numbered from 1 in input order.

## Constraints:

- Number of crystals: 1 ≤ n ≤ 10⁴
- Number of ley lines: 0 ≤ m ≤ 10⁴
- Crystal indices: 1 ≤ v, u ≤ n
- No duplicate ley lines in input

## Example:

### Input:

```
4 4
1 2
1 3
2 4
3 4
```

### Output:

```
4
1 2 3 4
```

### Input:

```
4 5
1 2
2 3
3 4
4 1
1 3
```

### Output:

```
1
5
```

## Explanation:

**Test Case 1:** The crystal network forms a simple square. After severing any single ley line, the remaining network can be enchanted with alternating Solar/Lunar magic such that no remaining ley line connects crystals of the same affinity.

**Test Case 2:** The network contains a cycle of odd length (1-2-3-4-1 forms a 4-cycle, but adding ley line 1-3 creates odd cycles). Only severing ley line 5 (connecting crystals 1 and 3) allows the remaining network to maintain harmonic balance.

---

## Notes:

- The Ritual of Harmonic Balance succeeds when the remaining network forms a bipartite graph
- Solar (red) and Lunar (blue) magic must alternate across connected crystals
- Each crystal must receive exactly one type of magical enchantment
- The mystical resonance patterns follow the ancient laws of graph theory

---

_Question designed by [Abhyuday-Gupta912](https://github.com/Abhyuday-Gupta912)_
