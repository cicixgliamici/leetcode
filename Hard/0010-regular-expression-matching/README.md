# 10. Regular Expression Matching

## Problem

Given an input string `s` and a pattern `p`, implement regular expression matching with support for:

- `.`, which matches any single character
- `*`, which matches zero or more of the preceding element

The matching should cover the entire input string.

## Example

### Input

```text
s = "aab", p = "c*a*b"
```

### Output

```text
true
```

## Approach

This repository uses dynamic programming.

Let `dp[i][j]` mean whether the prefix `s[:i]` matches the prefix `p[:j]`.

There are two main cases:

- if `p[j - 1]` is a normal character or `.`, then we need a direct character match and `dp[i - 1][j - 1]`
- if `p[j - 1]` is `*`, we can either:
  - ignore the `x*` pair entirely and use `dp[i][j - 2]`
  - consume one more matching character and use `dp[i - 1][j]`

The DP table is initialized carefully so patterns like `a*` or `a*b*` can match the empty string.

## Complexity

- Time: `O(n * m)`
- Space: `O(n * m)`

## Notes

This is a good example of turning a recursive definition into a tabulated DP solution. The repository includes Python, C, and C++ implementations built around the same state transition.
