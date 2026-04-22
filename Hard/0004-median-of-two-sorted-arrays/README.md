# 4. Median of Two Sorted Arrays

## Problem

Given two sorted arrays `nums1` and `nums2` of size `m` and `n`, return the median of the two sorted arrays.

The overall run time complexity should be `O(log (m + n))`.

## Example

### Input

```text
nums1 = [1, 3], nums2 = [2]
```

### Output

```text
2.0
```

## Approach

The key idea is to partition the two arrays so that:

- the left partition contains half of the total elements
- every element on the left is less than or equal to every element on the right

To do that efficiently, we run binary search on the smaller array.

For a candidate partition:

- `partition1` splits `nums1`
- `partition2` is derived so the left side has the correct total size
- we compare the border values around those partitions

If the left border of one side is greater than the right border of the other, the partition is not valid and we move the binary search window.

Once the partition is correct:

- if the total length is odd, the median is the maximum element on the left
- if the total length is even, the median is the average of the two middle values

## Complexity

- Time: `O(log(min(m, n)))`
- Space: `O(1)`

## Notes

This is one of the classic binary-search-on-answer-boundary problems. The implementation in this repository searches only on the smaller array to keep the bounds simple and efficient.
