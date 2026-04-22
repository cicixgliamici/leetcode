# 1. Two Sum

## Problem

Given an array of integers `nums` and an integer `target`, return the indices of the two numbers such that they add up to `target`.

You may assume that each input has exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

## Example

### Input

```text
nums = [2, 7, 11, 15], target = 9
```

### Output

```text
[0, 1]
```

## Approach

The straightforward solution checks every pair of indices, but that costs `O(n^2)` time.

A better approach uses a hash map while scanning the array from left to right:

- for each value `x`, compute `target - x`
- check whether that complement has already been seen
- if yes, return the stored index together with the current index
- if not, store the current value and its index

This works because by the time we process position `i`, the map contains exactly the earlier values that could form a valid pair with `nums[i]`.

## Complexity

- Time: `O(n)`
- Space: `O(n)`

## Notes

This problem is a classic introduction to hash-map-based lookup. The repository includes multiple implementations, including a brute-force variant and an optimized hash-table solution.
