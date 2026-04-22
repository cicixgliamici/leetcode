# 66. Plus One

## Problem

You are given a large integer represented as an integer array `digits`, where each `digits[i]` is the `i`-th digit of the integer.

The digits are ordered from most significant to least significant, and the large integer does not contain any leading zero.

Increment the large integer by one and return the resulting array of digits.

## Example

### Input

```text
digits = [1, 2, 3]
```

### Output

```text
[1, 2, 4]
```

## Approach

Process the array from right to left, just like manual addition.

At each position:

- if the digit is smaller than `9`, increment it and return immediately
- if the digit is `9`, set it to `0` and continue carrying to the left

If every digit was `9`, the carry goes beyond the most significant digit, so we create a new array starting with `1`.

## Complexity

- Time: `O(n)` in the worst case
- Space: `O(1)` extra space, ignoring the returned array

## Notes

This is a simple carry-propagation problem on an array representation of an integer.
