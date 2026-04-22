# 28. Find the Index of the First Occurrence in a String

## Problem

Given two strings `haystack` and `needle`, return the index of the first occurrence of `needle` in `haystack`, or `-1` if `needle` is not part of `haystack`.

## Example

### Input

```text
haystack = "sadbutsad", needle = "sad"
```

### Output

```text
0
```

## Approach

This repository uses the straightforward substring search approach.

For each possible starting index in `haystack`:

- take the substring of length `len(needle)`
- compare it with `needle`
- return the first index where they match

If no match is found after checking all valid starting positions, return `-1`.

## Complexity

- Time: `O(n * m)` in the worst case
- Space: `O(1)` extra space

Here `n` is the length of `haystack` and `m` is the length of `needle`.

## Notes

This is the naive pattern-matching solution. It is simple and perfectly acceptable for this problem size, even though more advanced algorithms such as KMP exist.
