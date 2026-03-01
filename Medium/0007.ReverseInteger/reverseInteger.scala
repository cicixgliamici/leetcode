object Solution {
  def reverse(x: Int): Int = {
    var n = x
    var rev = 0

    while (n != 0) {
      val digit = n % 10   // last digit (keeps sign in Scala, like C/C++)
      n /= 10              // remove last digit (truncates toward zero)

      /*
       * We want to do: rev = rev * 10 + digit
       * but must avoid 32-bit overflow WITHOUT using 64-bit (Long).
       *
       * Int.MaxValue =  2147483647 -> last digit limit is 7
       * Int.MinValue = -2147483648 -> last digit limit is -8
       *
       * If rev > Max/10, then rev*10 overflows.
       * If rev == Max/10, then adding digit > 7 overflows.
       *
       * Similarly for the negative side:
       * If rev < Min/10, then rev*10 overflows.
       * If rev == Min/10, then adding digit < -8 overflows.
       */
      if (rev > Int.MaxValue / 10 || (rev == Int.MaxValue / 10 && digit > 7)) return 0
      if (rev < Int.MinValue / 10 || (rev == Int.MinValue / 10 && digit < -8)) return 0

      rev = rev * 10 + digit
    }

    rev
  }
}
