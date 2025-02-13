package main

import "fmt"

// strStr finds the index of the first occurrence of the string 'needle' in 
// the string 'haystack'. If 'needle' is not found in 'haystack', it returns -1.
//
// This function implements a straightforward approach by checking every 
// possible starting position in 'haystack'. Whenever the substring of length
// 'len(needle)' matches 'needle', the index is returned. Otherwise, it continues 
// to check subsequent positions.
func strStr(haystack string, needle string) int {
	// If needle is empty, by convention, we can return 0.
	if len(needle) == 0 {
		return 0
	}
	
	// If needle's length is greater than haystack's length,
	// needle cannot possibly be in haystack.
	if len(needle) > len(haystack) {
		return -1
	}

	// Loop through haystack until there's no enough room for needle to fit.
	for i := 0; i <= len(haystack)-len(needle); i++ {
		// Compare the substring of haystack with needle.
		if haystack[i:i+len(needle)] == needle {
			return i // First matching index.
		}
	}
	
	// If no match was found, return -1.
	return -1
}

/*
Algorithmic Complexity and Data Structures:

- Time Complexity: O(n*m), where:
  n is the length of haystack.
  m is the length of needle.

  In the worst case, we might compare almost every substring of length m in 
  haystack with needle. Each substring comparison can take O(m) in the worst
  case, leading to an overall O(n*m) time complexity.

- Space Complexity: O(1). We are not using any additional data structure 
  proportional to n or m. We are only performing string slicing and comparisons.

- Algorithm Used: This is the naive substring search algorithm. More efficient 
  algorithms for substring search include the Knuth-Morris-Pratt (KMP), 
  Rabin-Karp, or the Boyer-Moore algorithm, but for many practical cases (or 
  smaller input sizes), this straightforward approach is sufficient.
*/
