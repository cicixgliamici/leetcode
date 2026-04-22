# 27. Remove Element

## Problem

Given an integer array `nums` and an integer `val`, remove all occurrences of `val` in place.

Return the number of elements in `nums` which are not equal to `val`.

The order of the remaining elements may change, and anything beyond the returned length does not matter.

## Example

### Input

```text
nums = [3, 2, 2, 3], val = 3
```

### Output

```text
2
```

## Approach

Use a write pointer `k` to compact the array:

- scan every element from left to right
- when the current element is not equal to `val`, copy it into position `k`
- increment `k`

At the end, the first `k` positions contain exactly the elements we want to keep.

## Complexity

- Time: `O(n)`
- Space: `O(1)`

## Notes

This is very close to the previous sorted-array compaction problem, except here the array does not need to be sorted.
