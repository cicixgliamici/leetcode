# 20. Valid Parentheses

## Problem

Given a string `s` containing just the characters `()[]{}`, determine if the input string is valid.

A string is valid if:

- open brackets are closed by the same type of brackets
- open brackets are closed in the correct order
- every closing bracket has a corresponding opening bracket

## Example

### Input

```text
s = "()[]{}"
```

### Output

```text
true
```

## Approach

This is a classic stack problem.

Scan the string from left to right:

- push opening brackets onto the stack
- when a closing bracket appears, the stack must be non-empty and its top must be the matching opening bracket
- if any mismatch occurs, return `false`

At the end, the stack must be empty.

The stack models the nesting structure of the brackets, which is exactly what we need to validate proper ordering.

## Complexity

- Time: `O(n)`
- Space: `O(n)`

## Notes

This is one of the standard introductory uses of a stack in interview-style problems.
