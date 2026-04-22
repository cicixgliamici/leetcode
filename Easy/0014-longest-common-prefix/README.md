# 14. Longest Common Prefix

## Problem

Write a function to find the longest common prefix string among an array of strings.

If there is no common prefix, return an empty string `""`.

## Example

### Input

```text
strs = ["flower", "flow", "flight"]
```

### Output

```text
"fl"
```

## Approach

Use the first string as a candidate prefix, then compare it with each remaining string.

Whenever the current string does not start with the candidate prefix:

- remove the last character from the prefix
- try again

If the prefix becomes empty, there is no common prefix.

This works because the final answer must be a prefix of the first string, so we can progressively shorten that candidate until it matches every string.

## Complexity

- Time: up to `O(n * L^2)` in the current shrinking-prefix implementation
- Space: `O(1)` extra space, ignoring the output

`n` is the number of strings and `L` is the length of the current prefix candidate.

## Notes

This is a straightforward horizontal-scanning solution. It is simple to read and good for an introductory string problem.
