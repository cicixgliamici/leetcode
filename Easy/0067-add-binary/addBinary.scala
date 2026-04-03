import scala.collection.mutable.StringBuilder

object Solution {
  def addBinary(a: String, b: String): String = {
    var i = a.length - 1
    var j = b.length - 1
    var carry = 0

    val sb = new StringBuilder

    while (i >= 0 || j >= 0 || carry != 0) {
      var sum = carry

      if (i >= 0) { sum += a.charAt(i) - '0'; i -= 1 }
      if (j >= 0) { sum += b.charAt(j) - '0'; j -= 1 }

      sb.append(((sum & 1) + '0').toChar)
      carry = sum >> 1
    }

    sb.result().reverse
  }
}