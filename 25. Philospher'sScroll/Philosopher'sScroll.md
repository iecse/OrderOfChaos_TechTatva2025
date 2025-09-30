# Philosopher's Scroll (Medium)
## String, Stack
-Mahika
## Problem Statement
The great Philosopher's Scroll is written in a magical code. Each spell is inscribed as:

```k[spell]```


where k is the number of times the spell must be chanted, and the part inside the brackets is the incantation itself.

For example, 3[fire]2[ice] means chanting "firefirefireiceice".
The scroll may also contain nested enchantments, like 2[a3[b]], which becomes "abbbabbb".

Your task as the Apprentice Wizard is to fully decode the scroll and reveal the ancient spell.

## Input

- The first line contains an integer t (1 ≤ t ≤ 100) — the number of test cases.
- Each of the next t lines contains a non-empty string s, the encoded scroll.
- The string s consists of lowercase English letters, digits, and square brackets [].
- It is guaranteed that the input is always valid and properly encoded.

## Output

For each test case, print the fully decoded chant as a string.

## Constraints

- 1 ≤ t ≤ 100
- 1 ≤ |s| ≤ 1000 (length of each encoded scroll)
- 1 ≤ k ≤ 300 (repeat count for any spell)
- The encoded string s contains only lowercase English letters, digits, and square brackets [].
- It is guaranteed that all encoded strings are valid and properly nested.

## Example

Input
```
3
3[a]2[bc]
3[a2[c]]
2[abc]3[cd]ef
```

Output

```
aaabcbc
accaccacc
abcabccdcdcdef
```


