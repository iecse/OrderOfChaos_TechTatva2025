# Mystical Ritual Circles

**Question Difficulty: Medium**

## Description:

In the forgotten depths of the Whispering Citadel, where time itself seems to bend and warp around crystalline formations, Archmage Zara has uncovered the legendary Axis of Eternal Resonance - an ancient mystical circle with nodes of pure magical energy arranged in perfect linear harmony. Each node pulses with its own unique frequency, some radiating brilliant light while others seem to drink in the very essence of magic itself, creating a delicate balance between creation and void.

The sacred texts of the Elder Conclave speak of ritual sequences hidden within these arrangements - contiguous pathways where the total harmonic energy aligns with cosmic forces, while the peak resonance reaches but never exceeds the threshold of dimensional stability. Legend tells that when Zara channels her power through such a sequence, reality itself bends to her will, but only if the magical equilibrium is maintained with absolute precision.

Master Kaelen, the last surviving member of the Order of Harmonic Weavers, once warned her that exceeding the peak threshold would tear holes in the fabric of existence itself, while failing to reach it would leave the ritual powerless and dormant. Each valid sequence represents a fragment of the ancient knowledge, a key to unlocking the deepest mysteries of the arcane arts that have been lost for millennia.

Your task is to help Zara identify all the sacred pathways within each mystical formation, counting every contiguous sequence that achieves perfect harmonic balance while maintaining dimensional stability.

## Input:

The first line contains a single integer t (1 ≤ t ≤ 10⁴) - the number of mystical formations Zara must analyze.

For each mystical formation:

- First line contains three integers n, s, and p (1 ≤ n ≤ 2×10⁵, −2×10¹⁴ ≤ s ≤ 2×10¹⁴, −10⁹ ≤ p ≤ 10⁹) - the number of nodes, the required total harmonic energy, and the maximum allowed peak resonance
- Second line contains n integers e₁, e₂, ..., eₙ (−10⁹ ≤ eᵢ ≤ 10⁹) - the energy level of each mystical node

It is guaranteed that the sum of n across all formations does not exceed 2×10⁵.

## Output:

For each mystical formation, output a single integer representing the number of sacred pathways (contiguous sequences) where the total energy equals s and the peak energy equals exactly p.

A sacred pathway exists when nodes form a contiguous sequence with:

- Total harmonic energy summing to exactly s
- Peak resonance reaching exactly p (not exceeding it, as this would destabilize reality)
- At least one node achieving the peak resonance level p

## Constraints:

- Number of formations: 1 ≤ t ≤ 10⁴
- Nodes per formation: 1 ≤ n ≤ 2×10⁵
- Required total energy: −2×10¹⁴ ≤ s ≤ 2×10¹⁴
- Maximum peak resonance: −10⁹ ≤ p ≤ 10⁹
- Node energy levels: −10⁹ ≤ eᵢ ≤ 10⁹
- Total nodes across all formations: ≤ 2×10⁵

## Example:

### Input:

```
9
1 0 0
0
1 -2 -1
-2
3 -1 -1
-1 1 -1
6 -3 -2
-1 -1 -1 -2 -1 -1
8 3 2
2 2 -1 -2 3 -1 2 2
9 6 3
1 2 3 1 2 3 1 2 3
13 7 3
0 -1 3 3 3 -2 1 2 2 3 -1 0 3
2 -2 -1
-2 -1
2 -2 -1
-1 -2
```

### Output:

```
1
0
2
0
2
7
8
0
0
```

## Explanation:

**Test Case 1:** The sequence [0] has sum 0 and max 0. ✓

**Test Case 3:** The valid sequences are [−1] (position 1) and [−1] (position 3). Both have sum −1 and max −1.

**Test Case 5:** The valid sequences are [2, 2] (positions 1-2) and [2, 2] (positions 7-8). Both have sum 4... wait, that doesn't match. Let me recalculate: we need sum 3 and max 2. Valid sequences include [2] at various positions and [2, 2, -1] which sums to 3 with max 2.

**Test Case 6:** Multiple contiguous sequences work, including several single-element sequences with value 3, and some multi-element sequences that sum to 6 with maximum value 3.

---

## Notes:

- A sequence is valid only if it contains at least one node with energy level exactly _p_
- No node in the sequence can have energy level greater than _p_ (this would destabilize the ritual)
- The total energy must sum to exactly _s_ for the ritual to work
- Negative energy levels represent nodes that absorb magical energy rather than emit it

---

_Question designed by [Abhyuday-Gupta912](https://github.com/Abhyuday-Gupta912)_
