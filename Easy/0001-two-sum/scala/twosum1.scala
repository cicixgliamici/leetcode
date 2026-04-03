object TwoSum {
  def twoSum(nums: Array[Int], target: Int): Array[Int] = {
    // Generate all index pairs (i, j) with i < j, then find the first that matches.
    val maybePair: Option[(Int, Int)] =
      nums.indices
        .flatMap(i => (i + 1 until nums.length).map(j => (i, j)))
        .find { case (i, j) => nums(i) + nums(j) == target }

    // Return indices if found, otherwise empty array (same behavior as your Java code).
    maybePair match {
      case Some((i, j)) => Array(i, j)
      case None         => Array.emptyIntArray
    }
  }
}
