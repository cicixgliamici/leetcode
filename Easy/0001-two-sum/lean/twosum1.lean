def twoSum (nums : Array Int) (target : Int) : Array Nat := Id.run do
  /-
    We scan all pairs of indices (i, j) with i < j.
    As soon as we find a pair such that:

        nums[i] + nums[j] = target

    we return the two indices.
  -/

  for i in [0:nums.size] do
    /-
      Fix the first index i, then search for a second index j
      starting from i + 1.
    -/
    for j in [i + 1:nums.size] do
      /-
        `nums[i]!` and `nums[j]!` access the elements at positions
        i and j.

        The `!` means:
        "use this index directly; trust that it is valid".

        Here it is safe because:
        - i ranges in [0, nums.size)
        - j ranges in [i+1, nums.size)
      -/
      if nums[i]! + nums[j]! = target then
        /-
          Found a valid pair of indices.
          We immediately return them as an array.
        -/
        return #[i, j]

  /-
    If no pair is found, return the empty array.
    On LeetCode this case usually does not happen,
    because the problem guarantees exactly one solution.
  -/
  return #[]
