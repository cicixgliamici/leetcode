# LeetCode-style definition:
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        # Dummy node to simplify head logic
        dummy = ListNode(0)
        cur = dummy
        carry = 0

        while l1 is not None or l2 is not None or carry != 0:
            s = carry

            if l1 is not None:
                s += l1.val
                l1 = l1.next

            if l2 is not None:
                s += l2.val
                l2 = l2.next

            carry = s // 10
            cur.next = ListNode(s % 10)
            cur = cur.next

        return dummy.next
