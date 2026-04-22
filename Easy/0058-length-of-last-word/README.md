# 58. Length of Last Word

## Problem

Given a string `s` consisting of words and spaces, return the length of the last word in the string.

A word is a maximal substring consisting of non-space characters only.

## Example

### Input

```text
s = "Hello World"
```

### Output

```text
5
```

## Approach

The current implementations take a simple string-processing route:

- remove trailing spaces
- split the string into words
- take the last word
- return its length

This is easy to read and works well for the problem.

## Complexity

- Time: `O(n)`
- Space: `O(n)` because of the split

## Notes

An even more space-efficient version could scan backward from the end without splitting, but the current approach is concise and clear.
