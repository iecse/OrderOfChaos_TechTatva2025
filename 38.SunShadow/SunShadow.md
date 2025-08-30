
***

# The Celestial Duel: Convergence of Sunfire and Moonshadow

## Question Difficulty: Medium

### Description:

In the mystical realm of Aethel, two opposing schools of magic, **Sunfire** and **Moonshadow**, are locked in an eternal struggle. You are a Celestial Arbiter, tasked with observing the outcome of their magical duels along a **sacred ley line**.

The duel is represented by a sequence of spells, `spells`, each with a specific power:
* **Sunfire Spells** are cast from the left and travel right. Their power is a **positive** integer.
* **Moonshadow Spells** are cast from the right and travel left. Their power is a **negative** integer.

When a spell is cast, it travels along the ley line until it either exits or collides with an opposing spell. The rules of collision are precise:

1.  A collision occurs when a right-moving Sunfire spell meets a left-moving Moonshadow spell.
2.  When they collide, the spell with the lower absolute power is **dissipated**. The more powerful spell's energy is **diminished** by the power of the one that was dissipated.
3.  If two opposing spells of equal absolute power collide, they **annihilate** each other, and both are removed.
4.  Spells of the same type (e.g., two Sunfire spells) never collide and continue along the ley line in formation.

After all collisions have resolved, the duel's outcome is judged. If the final sequence of spell powers on the ley line is a **palindrome**, the outcome is **Harmonious**. Otherwise, it is **Chaotic**. Your task is to simulate the duel and predict the outcome.

---

### Input:

The input will be provided directly to a function, which receives:
- A 1D integer array, `spells`.

---

### Output:

Return a single string: `"Harmonious"` or `"Chaotic"`.

---

### Constraints

* **Number of Spells (`N`):** The number of spells will be between $1$ and $10^5$.
* **Spell Power:** The power of each spell will be in the range $[-1000, 1000]$ and will not be zero.

---

### Examples

#### Example 1

**Input:**
`spells = [5, 10, -8, 5]`

**Output:**
`"Harmonious"`

**Explanation:**
The simulation proceeds as follows:
1.  A `5` (Sunfire) spell is cast. Active spells on the ley line: `[5]`
2.  A `10` (Sunfire) spell is cast. It moves right and joins the formation. Active spells: `[5, 10]`
3.  A `-8` (Moonshadow) spell is cast. It moves left and collides with `10`.
    * Since $|10| > |-8|$, the `-8` spell is dissipated.
    * The `10` spell's power is reduced by `8`, becoming `10 - 8 = 2`.
4.  Active spells are now: `[5, 2]`
5.  A `5` (Sunfire) spell is cast. It joins the formation. Active spells: `[5, 2, 5]`

All spells have been cast and collisions resolved. The final sequence of powers is `[5, 2, 5]`, which is a palindrome. Therefore, the outcome is **Harmonious**.

#### Example 2

**Input:**
`spells = [10, 6, -4, -8, 5]`

**Output:**
`"Chaotic"`

**Explanation:**
1.  Active spells start as `[10, 6]`.
2.  A `-4` (Moonshadow) spell collides with `6`. Since $|6| > |-4|$, `6` becomes `6 - 4 = 2`. Active spells: `[10, 2]`.
3.  A `-8` (Moonshadow) spell collides with `2`. Since $|-8| > |2|$, `2` is destroyed. `-8` becomes `-8 + 2 = -6`.
4.  The weakened `-6` spell continues left and collides with `10`. Since $|10| > |-6|$, `-6` is destroyed. `10` becomes `10 - 6 = 4`. Active spells: `[4]`.
5.  A `5` (Sunfire) spell is cast. Active spells: `[4, 5]`.

The final sequence is `[4, 5]`, which is not a palindrome. The outcome is **Chaotic**.

---

### *Question designed by Kushal [rkushell](https://github.com/rkushell)*