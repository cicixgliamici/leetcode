# 67. Add Binary

## Problem

Given two binary strings `a` and `b`, return their sum as a binary string.

## Example

### Input

```text
a = "11", b = "1"
```

### Output

```text
"100"
```

## Approach

Use two pointers starting from the end of the strings and simulate binary addition.

At each step:

- read the current bit from `a` if available
- read the current bit from `b` if available
- add those bits together with the carry
- append the resulting bit to the answer
- update the carry

Because the result is built from least significant bit to most significant bit, the implementations reverse the accumulated output at the end.

## Complexity

- Time: `O(n)`, where `n` is the maximum length of the two strings
- Space: `O(n)` for the output

## Notes

This is the binary-string analogue of elementary column addition and is a good exercise in pointer-style string traversal.
