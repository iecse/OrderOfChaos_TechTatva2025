# The Wizard's Potion Challenge

## Question Difficulty: Medium


In the mystical land of **Eldoria**, a group of wizards are attempting to brew the **most potent potion**. Each wizard possesses a tall, magical threshold containing a certain amount of **magical essence** (numbers in an array `threshold`).

---

## The Rules of the Brew

* The wizards must select **two thresholds** to combine their essence into a potion.
* The **strength of the potion** is determined by the **shorter threshold** (since it limits how much essence can flow) multiplied by the **distance between the two thresholds** (longer distance allows more mixing magic).
* The goal is to find the **pair of thresholds** that yields the **strongest potion**.



---

## Input

* `thresholds` → an array of integers representing the magical essence in each threshold.

---

## Output

* The **maximum potion strength** that can be brewed by any pair of thresholds.

---

## Example

**Input:**

```
thresholds = [1,8,6,2,5,4,8,3,7]
```


**Output:**

```
49
```

---
~ <a href=https://github.com/r1shu-R> Rishabh </a>