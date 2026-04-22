# 9. Palindrome Number

## Problem

Given an integer `x`, return `true` if `x` is a palindrome, and `false` otherwise.

An integer is a palindrome when it reads the same backward as forward.

## Example

### Input

```text
x = 121
```

### Output

```text
true
```

## Approach

Negative numbers cannot be palindromes because the minus sign only appears on the left.

For non-negative numbers, one simple approach is:

- keep a copy of the original value
- reverse the digits one by one
- compare the reversed number with the original

This repository uses that direct numeric approach instead of converting the number to a string.

Some language implementations also guard against integer overflow while building the reversed value.

## Complexity

- Time: `O(d)`, where `d` is the number of digits
- Space: `O(1)`

## Notes

This is a good warm-up problem for digit manipulation and overflow awareness in fixed-width integer languages.
