object Solution {
  def findMaxConsecutiveOnes(nums: Array[Int]): Int = {
    // currentCount = number of consecutive 1s in the current streak
    var currentCount = 0

    // maxCount = best result found so far
    var maxCount = 0

    for (num <- nums) {
      if (num == 1) {
        // Extend the current streak of 1s
        currentCount += 1

        // Update the maximum if needed
        if (currentCount > maxCount) {
          maxCount = currentCount
        }
      } else {
        // A 0 breaks the streak, so reset the counter
        currentCount = 0
      }
    }

    maxCount
  }
}
