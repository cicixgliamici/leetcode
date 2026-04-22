# 13. Roman to Integer

## Problem

Given a Roman numeral, convert it to an integer.

Roman numerals are usually written from largest to smallest from left to right, with a few subtraction cases such as:

- `IV = 4`
- `IX = 9`
- `XL = 40`
- `XC = 90`
- `CD = 400`
- `CM = 900`

## Example

### Input

```text
s = "MCMXCIV"
```

### Output

```text
1994
```

## Approach

Scan the string from left to right.

For each position:

- if the current numeral is smaller than the next one, they form a subtraction pair
- otherwise, add the current numeral directly

This repository includes two styles of implementation:

- direct case handling for known subtraction pairs
- a hash-map approach that converts symbols into values and compares adjacent characters

## Complexity

- Time: `O(n)`
- Space: `O(1)`

## Notes

This problem is a good small exercise in sequential parsing and careful handling of adjacent characters.
