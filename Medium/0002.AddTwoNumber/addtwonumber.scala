// LeetCode-style definition:
class ListNode(var x: Int = 0) {
  var next: ListNode = null
}

object Solution {
  def addTwoNumbers(l1: ListNode, l2: ListNode): ListNode = {

    // Recursive helper: builds the result list from current nodes + carry.
    def loop(a: ListNode, b: ListNode, carry: Int): ListNode = {
      // Base case: nothing left to add
      if (a == null && b == null && carry == 0) null
      else {
        val av = if (a != null) a.x else 0
        val bv = if (b != null) b.x else 0

        val sum = av + bv + carry
        val node = new ListNode(sum % 10)        // Current digit
        node.next = loop(
          if (a != null) a.next else null,
          if (b != null) b.next else null,
          sum / 10                                // Next carry
        )
        node
      }
    }

    loop(l1, l2, 0)
  }
}
