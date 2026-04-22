# 11. Container With Most Water

## Problem

You are given an integer array `height` of length `n`.

There are `n` vertical lines drawn such that the two endpoints of the `i`-th line are `(i, 0)` and `(i, height[i])`.

Find two lines that together with the x-axis form a container such that the container contains the most water.

Return the maximum amount of water a container can store.

You may not slant the container.

## Example

### Input

```text
height = [1, 8, 6, 2, 5, 4, 8, 3, 7]
```

### Output

```text
49
```

## Intuition

The area of a candidate container depends on:

- the width between the two chosen indices
- the shorter of the two heights

So the area is:

```text
(right - left) * min(height[left], height[right])
```

Checking every pair works, but it is too slow for large inputs.

## Optimal Approach

Use two pointers:

- `left` at the beginning
- `right` at the end

At each step:

- compute the current area
- update the best answer
- move the pointer that points to the shorter line

Why move the shorter line?

Because the shorter line is the limiting height of the current container. Moving the taller line only reduces the width and does not remove the bottleneck.

## Complexity

- Time: `O(n)`
- Space: `O(1)`

## Notes

This problem is a standard two-pointer pattern. The important insight is that shrinking the window is only useful when we try to replace the current limiting height.
