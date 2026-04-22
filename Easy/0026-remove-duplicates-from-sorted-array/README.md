# 26. Remove Duplicates from Sorted Array

## Problem

Given an integer array `nums` sorted in non-decreasing order, remove the duplicates in place such that each unique element appears only once.

Return the number of unique elements `k`.

The relative order of the elements should be kept the same.

## Example

### Input

```text
nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]
```

### Output

```text
5
```

## Approach

Because the array is already sorted, duplicates always appear next to each other.

Use a write pointer `k` to track the position where the next unique value should go:

- the first element is always unique
- scan the array from left to right
- when `nums[i]` differs from the last written unique value, copy it to `nums[k]`
- increment `k`

After the pass, the first `k` elements are the deduplicated array.

## Complexity

- Time: `O(n)`
- Space: `O(1)`

## Notes

This is a classic in-place two-pointer pattern on sorted arrays.
