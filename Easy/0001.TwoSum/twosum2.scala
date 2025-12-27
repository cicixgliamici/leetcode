object TwoSumFast {
  def twoSum(nums: Array[Int], target: Int): Array[Int] = {
    // We'll keep:
    // - seen: Map[value -> index] for values we've already scanned
    // - ans: Option[(i, j)] once we find the solution
    val (_, ans) =
      nums.iterator.zipWithIndex.foldLeft((Map.empty[Int, Int], Option.empty[(Int, Int)])) {
        case ((seen, ans @ Some(_)), _) =>
          // If we've already found an answer, just carry it through unchanged.
          (seen, ans)

        case ((seen, None), (x, i)) =>
          val complement = target - x
          seen.get(complement) match {
            case Some(j) =>
              // Found the earlier index j such that nums(j) + x == target
              (seen, Some((j, i)))
            case None =>
              // Store current value with its index and continue
              (seen.updated(x, i), None)
          }
      }

    // Return indices if found, otherwise empty array (same behavior as your Java code).
    ans match {
      case Some((i, j)) => Array(i, j)
      case None         => Array.emptyIntArray
    }
  }
}
