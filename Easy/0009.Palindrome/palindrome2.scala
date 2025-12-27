object PalindromeHalfReverse {

  def isPalindrome(x: Int): Boolean = {
    // Negative numbers are not palindromes.
    // Also, numbers ending with 0 are not palindromes unless the number is exactly 0
    // (because a palindrome can't start with 0).
    if (x < 0 || (x % 10 == 0 && x != 0)) return false

    @annotation.tailrec
    def loop(n: Int, revHalf: Int): Boolean = {
      // Stop when we've reversed at least half of the digits.
      if (n <= revHalf) {
        // Even length: n == revHalf
        // Odd length:  n == revHalf / 10 (skip the middle digit)
        n == revHalf || n == revHalf / 10
      } else {
        val lastDigit = n % 10
        loop(n / 10, revHalf * 10 + lastDigit)
      }
    }

    loop(x, 0)
  }
}
