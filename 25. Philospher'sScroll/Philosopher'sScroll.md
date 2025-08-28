# Philosopher's Scroll (med)
-Mahika
## Problem Statement
The great Philosopher's Scroll is written in a magical code. Each spell is inscribed as:

```k[spell]```


where k is the number of times the spell must be chanted, and the part inside the brackets is the incantation itself.

For example, 3[fire]2[ice] means chanting "firefirefireiceice".
The scroll may also contain nested enchantments, like 2[a3[b]], which becomes "abbbabbb".

Your task as the Apprentice Wizard is to fully decode the scroll and reveal the ancient spell.

## Input

A string s representing the magical encoded scroll.

Valid symbols: lowercase letters (spells), digits (repeat counts), and brackets [].

## Output

The fully decoded chant (a string).

## Example Spells

Input: 3[a]2[bc]
Output: aaabcbc

Input: 3[a2[c]]
Output: accaccacc

Input: 2[abc]3[cd]ef
Output: abcabccdcdcdef
