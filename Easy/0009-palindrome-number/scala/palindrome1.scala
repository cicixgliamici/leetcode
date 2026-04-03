import scala.annotation.tailrec

object PalindromeNumber {

  def isPalindrome(x: Int): Boolean = {
    // Negative numbers are never palindromes because of the '-' sign.
    if (x < 0) return false

    val original = x

    @tailrec
    def reverseChecked(n: Int, rev: Int): Option[Int] = {
      // When n becomes 0, the reverse is complete.
      if (n == 0) Some(rev)
      else {
        val lastDigit = n % 10

        // Overflow guard:
        // if rev * 10 + lastDigit would exceed Int.MaxValue, we stop.
        if (rev > (Int.MaxValue - lastDigit) / 10) None
        else reverseChecked(n / 10, rev * 10 + lastDigit)
      }
    }

    // If reversing overflowed -> not safe to compare -> return false.
    // Otherwise compare original with reversed.
    reverseChecked(x, 0).contains(original)
  }
}
