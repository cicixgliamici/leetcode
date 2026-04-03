/*
 * Merges two sorted linked lists (list1 and list2) into a single sorted list.
 * Returns the head of the merged list.
 *
 * Time Complexity: O(n+m), where n is the length of list1 and m is the length of list2.
 *    - Each node is processed exactly once.
 * Space Complexity: O(1), as the merging is done in place without creating additional data structures.
 */

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val  int
 *     Next *ListNode
 * }
 */

func mergeTwoLists(list1 *ListNode, list2 *ListNode) *ListNode {
    // If one of the lists is empty, simply return the other
    if list1 == nil {
        return list2
    }
    if list2 == nil {
        return list1
    }

    // Create a dummy node to easily build the merged list
    dummy := &ListNode{}
    tail := dummy

    // Compare the current nodes of both lists and attach the smaller one to the merged list
    for list1 != nil && list2 != nil {
        if list1.Val <= list2.Val {
            tail.Next = list1
            list1 = list1.Next
        } else {
            tail.Next = list2
            list2 = list2.Next
        }
        tail = tail.Next
    }

    // Attach any remaining nodes from list1 or list2
    if list1 != nil {
        tail.Next = list1
    } else {
        tail.Next = list2
    }

    // Return the head of the merged list (dummy.Next)
    return dummy.Next
}
