
-----

# The Sorcerer's Spellbook: The Curse of Annihilation

## Question Difficulty: Easy - Medium

### Description:

A master sorcerer stores powerful **spells** on an ancient, **enchanted scroll**. This scroll is represented as a string, where each character is a magical **rune** (a lowercase English letter).

However, the scroll is afflicted by a potent curse. When two identical, adjacent **runes** come into contact, they create a volatile reaction and instantly **annihilate** each other, vanishing from the scroll. This magical cancellation can bring two previously separated runes together, potentially triggering a **chain reaction** of further annihilations. This process continues until the scroll reaches a **stable state** where no adjacent runes are identical.

Your task is to foresee the final state of this cursed scroll after all possible annihilations have resolved.

-----

### Input:

The input will be a single string `s`, representing the initial sequence of runes on the scroll.

-----

### Output:

Return a single string representing the final, stable state of the scroll.

If the scroll becomes completely empty after all annihilations, return the string `"Empty Spellbook"`.

-----

### Constraints

  * **Length of the Scroll (`s`):** The scroll can contain between $1$ and $200,000$ runes, inclusive.
  * **Rune Alphabet:** The spells are composed exclusively of lowercase English letters (i.e., `a` through `z`).

-----

### Examples

#### Example 1

**Input**

```
abccba
```

**Output**
`Empty Spellbook`

**Explanation**
The annihilation process occurs in a chain reaction:

1.  The initial scroll is `abccba`.
2.  The two `c` runes in the middle are adjacent and annihilate, leaving the scroll as `abba`.
3.  This brings the two `b` runes together. They annihilate, leaving `aa`.
4.  Finally, the two `a` runes annihilate, leaving the scroll completely empty.

#### Example 2

**Input**

```
azxxzy
```

**Output**
`ay`

**Explanation**
The process unfolds as follows:

1.  The initial scroll is `azxxzy`.
2.  The `xx` runes annihilate, resulting in `azzy`.
3.  This brings the two `z` runes together. They annihilate, leaving `ay`.
4.  The scroll is now stable as no adjacent runes are identical.

#### Example 3

**Input**

```
aabcca
```

**Output**
`ba`

**Explanation**
The sequence of annihilations is:

1.  The initial scroll is `aabcca`.
2.  The `aa` runes at the start annihilate, leaving `bcca`.
3.  The `cc` runes are now adjacent. They annihilate, leaving `ba`.
4.  The scroll is now stable.

-----

### *Question designed by Kushal [rkushell](https://github.com/rkushell)*