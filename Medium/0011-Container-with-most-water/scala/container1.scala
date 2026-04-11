object Solution {
  def maxArea(height: Array[Int]): Int = {
    // Start with two pointers at the extremes of the array
    var left = 0
    var right = height.length - 1

    // This variable stores the maximum area found so far
    var maxWater = 0

    // Continue until the two pointers meet
    while (left < right) {
      // The width is the distance between the two lines
      val width = right - left

      // The container height is limited by the shorter line
      val currentHeight = math.min(height(left), height(right))

      // Compute the current area
      val currentWater = width * currentHeight

      // Update the maximum area if needed
      maxWater = math.max(maxWater, currentWater)

      // Move the pointer corresponding to the shorter line
      // because only that move can potentially improve the result
      if (height(left) < height(right)) {
        left += 1
      } else {
        right -= 1
      }
    }

    // Return the best area found
    maxWater
  }
}
