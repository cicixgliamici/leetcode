# 11. Container With Most Water

## Problem

You are given an integer array `height` of length `n`.

There are `n` vertical lines drawn such that the two endpoints of the `i-th` line are `(i, 0)` and `(i, height[i])`.

Find two lines that together with the x-axis form a container such that the container contains the most water.

Return the maximum amount of water a container can store.

You may not slant the container.

---

## Example

### Input

```
height = [1,8,6,2,5,4,8,3,7]
```

### Output

```
49
```

### Explanation

The best container is formed by the lines at indices `1` and `8`:

* width = `8 - 1 = 7`
* height = `min(8, 7) = 7`
* area = `7 * 7 = 49`

---

## Intuition

To form a container, we choose two lines:

* one on the left
* one on the right

The amount of water stored depends on:

* the **width** between the two lines
* the **smaller height** of the two lines

So the formula is:

```
area = (right - left) * min(height[left], height[right])
```

A brute force solution would try every possible pair of lines, but that would be too slow.

---

## Brute Force Approach

We could check every pair `(i, j)`:

* compute the width
* compute the minimum height
* compute the area
* keep the maximum

This works, but it takes:

* **O(n²)** time
* **O(1)** extra space

For large inputs, this is not efficient enough.

---

## Optimal Approach: Two Pointers

We use two pointers:

* `left` starting at the beginning
* `right` starting at the end

At each step:

1. compute the current area
2. update the maximum area
3. move the pointer that points to the **shorter** line

### Why do we move the shorter line?

Because the shorter line is the one limiting the current container height.

If we move the taller line instead:

* the width becomes smaller
* the limiting height does not improve for sure

So moving the shorter line is the only move that may lead to a better result.

---

## Algorithm

1. Initialize `left = 0` and `right = n - 1`
2. While `left < right`:

   * compute the width
   * compute the current height using the smaller line
   * compute the area
   * update the answer
   * move the pointer of the shorter line
3. Return the maximum area found

---

## Correctness Idea

At every step, the current area is determined by:

* the current width
* the shorter of the two heights

If we keep the shorter height and reduce the width, the area cannot improve reliably.

Therefore, to search for a better solution, we discard the shorter line and hope to find a taller one.

This greedy choice is what makes the two-pointer solution correct and efficient.

---

## Complexity

### Brute Force

* **Time:** `O(n²)`
* **Space:** `O(1)`

### Two Pointers

* **Time:** `O(n)`
* **Space:** `O(1)`

---

## Key Takeaway

This problem is a classic **two pointers** pattern.

The important insight is that the area is limited by the **shorter line**, so the only useful move is to advance the pointer on the smaller height.
