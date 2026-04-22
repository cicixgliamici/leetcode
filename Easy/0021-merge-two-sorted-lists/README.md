# 21. Merge Two Sorted Lists

## Problem

You are given the heads of two sorted linked lists `list1` and `list2`.

Merge the two lists into one sorted list and return the head of the merged list.

The merged list should be made by splicing together the nodes of the first two lists.

## Example

### Input

```text
list1 = [1, 2, 4], list2 = [1, 3, 4]
```

### Output

```text
[1, 1, 2, 3, 4, 4]
```

## Approach

Use a dummy head node and a moving tail pointer.

At each step:

- compare the current nodes of the two lists
- attach the smaller node to the merged list
- advance the pointer in the list that provided that node

When one list is exhausted, attach the remaining nodes of the other list.

The dummy node keeps the head-management logic simple and avoids special cases for the first insertion.

## Complexity

- Time: `O(n + m)`
- Space: `O(1)` extra space

## Notes

This is a standard linked-list merging pattern that appears often in divide-and-conquer problems as well.
