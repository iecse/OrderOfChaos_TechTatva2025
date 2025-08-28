# The Wizard's Potion Challenge

## Question Difficulty: Medium


In the mystical land of **Eldoria**, a group of wizards are attempting to brew the **most potent potion**. Each wizard possesses a tall, magical vial containing a certain amount of **magical essence** (numbers in an array `vials`).

---

## The Rules of the Brew

* The wizards must select **two vials** to combine their essence into a potion.
* The **strength of the potion** is determined by the **shorter vial** (since it limits how much essence can flow) multiplied by the **distance between the two vials** (longer distance allows more mixing magic).
* The goal is to find the **pair of vials** that yields the **strongest potion**.



---

## Input

* `vials` → an array of integers representing the magical essence in each vial.

---

## Output

* The **maximum potion strength** that can be brewed by any pair of vials.

---

## Example

**Input:**

```
vials = [1,8,6,2,5,4,8,3,7]
```

![alt text](image.png)

**Output:**

```
49
```

---

## Explanation

* The wizards select the vial with 8 units of essence at position 1 and the vial with 7 units at position 8.

* No other pair of vials produces a stronger potion.

---
~ <a href=https://github.com/r1shu-R> Rishabh </a>