# Crystal Resonance

**Question Difficulty: Easy**

## Description:

In the mystical realm of Aethermoor, where magic flows like rivers through crystalline caverns, Wizard Elara has discovered an ancient art of crystal resonance. Deep within the Luminous Sanctum, she has found a collection of enchanted crystals, each pulsing with its own unique power signature. Legend speaks of a perfect harmonic arrangement - a resonance chain that can channel raw magical energy with flawless precision.

The ancient texts reveal that when crystals are arranged in sequence, magical energy cascades from one to the next, transforming according to the sacred ratio of their power levels. Elara knows that for her spell to succeed, she must achieve perfect equilibrium - where the energy that enters the chain equals the energy that emerges, creating a closed loop of magical harmony.

Master Theron, her mentor from the Academy of Ethereal Arts, once taught her that true magical mastery lies not in raw power, but in understanding the delicate balance between beginning and end. Each successful resonance chain represents a moment where the cosmos aligns, where the first crystal's essence perfectly mirrors the last, creating a bridge between potential and manifestation.

Your task is to help Elara determine which combinations of her crystals can achieve this mystical resonance, unlocking the secrets hidden within each magical array.

## Input:

The first line contains a single integer t (1 ≤ t ≤ 1000) - the number of crystal collections Elara must examine.

For each crystal collection:

- First line contains n (2 ≤ n ≤ 100) - the number of crystals in this collection
- Second line contains n integers p₁, p₂, ..., pₙ (2 ≤ pᵢ ≤ 100) - the power level of each crystal

## Output:

For each crystal collection, output "YES" if Elara can rearrange the crystals to create a perfect resonance chain where exactly 1 unit of energy emerges when 1 unit enters, and "NO" otherwise.

A perfect resonance occurs when two crystals with identical power levels can be placed at the beginning and end of the chain, allowing the magical energy to complete its circuit in perfect harmony.

## Constraints:

- Number of test cases: 1 ≤ t ≤ 1000
- Crystals per collection: 2 ≤ n ≤ 100
- Crystal power levels: 2 ≤ pᵢ ≤ 100
- Each power level represents the mystical frequency of that crystal

## Example:

### Input:

```
5
2
7 7
4
8 4 8 12
2
3 5
7
42 14 18 14 14 12 24
5
3 6 12 24 48
```

### Output:

```
YES
YES
NO
YES
NO
```

## Sample Explanation:

**Test Case 1:** Elara can arrange the crystals as [7, 7]. The resonance achieves perfect balance with matching endpoints.

**Test Case 2:** Multiple crystals share power level 8, allowing for perfect resonance alignment.

**Test Case 3:** No two crystals share the same power signature - resonance impossible.

**Test Case 4:** Several crystals have power level 14, enabling various resonance configurations.

**Test Case 5:** All crystals have unique power levels - the magical frequencies cannot achieve harmony.

---

_Question designed by [Abhyuday-Gupta912](https://github.com/Abhyuday-Gupta912)_
