func lengthOfLastWord(s string) int {
	// Trim trailing spaces to handle cases where there are spaces at the end
	s = strings.TrimRight(s, " ")
	
	// Split the string into words based on spaces
	words := strings.Split(s, " ")
	
	// The last word is the last element in the slice
	lastWord := words[len(words)-1]
	
	// Return the length of the last word
	return len(lastWord)
}
