#  Magical Binary Spell
## Difficulty - Hard

In the realm of magic, spells are woven from sequences of **light runes (`1`)** and **shadow runes (`0`)**.  
A spell is called **balanced** if it satisfies the following two conditions:

1. The number of **light runes (`1`)** equals the number of **shadow runes (`0`)**.  
2. In every prefix of the spell, the number of light runes is **at least** the number of shadow runes.  

You are given a balanced spell `s`.

The wizard can perform the following magical operation any number of times:  
- Choose two consecutive, non-empty, balanced substrings of `s`, and **swap them**.

Two substrings are consecutive if the last rune of the first is exactly before the first rune of the second.

The goal is to return the **lexicographically strongest spell** (largest string) that can be formed after performing any number of such magical operations.

---

## Input
- First line: integer `T` — number of test cases.  
- Next `T` lines: each line contains one string `s`, a balanced spell.  

## Output
- For each test case, print the lexicographically strongest balanced spell possible.  

---

## Constraints
- `1 <= T <= 1000`  
- `1 <= s.length <= 50`  
- `s[i]` is either `'0'` (shadow rune) or `'1'` (light rune).  
- Each `s` is guaranteed to be a balanced spell.  

---

## Example 1

**Input**  
```
2
11011000
10
```

**Output**  
```
11100100
10
```

**Explanation**  
- For the first spell, it can be split into `10` and `1100`. Swapping them gives `11100100`, the strongest spell.  
- For the second spell, no better rearrangement is possible.




