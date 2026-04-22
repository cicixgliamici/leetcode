# 35. Search Insert Position

## Problem

Given a sorted array of distinct integers and a target value, return the index if the target is found.

If not, return the index where it would be if it were inserted in order.

You must write an algorithm with `O(log n)` runtime complexity.

## Example

### Input

```text
nums = [1, 3, 5, 6], target = 5
```

### Output

```text
2
```

## Approach

Use binary search on the sorted array.

At each step:

- check the middle element
- if it equals the target, return its index
- if it is smaller than the target, continue on the right half
- otherwise, continue on the left half

When the search ends without an exact match, the `left` pointer indicates the correct insertion position.

## Complexity

- Time: `O(log n)`
- Space: `O(1)`

## Notes

This is a standard binary-search variant where the final search boundary is itself the answer.
