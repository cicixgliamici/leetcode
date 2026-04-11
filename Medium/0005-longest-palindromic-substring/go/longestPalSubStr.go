package main

func longestPalindrome(s string) string {
	if len(s) < 1 {
		return ""
	}

	start, end := 0, 0
	// Itera su ogni carattere come potenziale centro
	for i := 0; i < len(s); i++ {
		// Palindromi dispari (centro in i)
		l1, r1 := expand(s, i, i)
		// Palindromi pari (centro tra i e i+1)
		l2, r2 := expand(s, i, i+1)

		// Aggiorna gli indici del palindromo più lungo
		if r1-l1 > end-start {
			start, end = l1, r1
		}
		if r2-l2 > end-start {
			start, end = l2, r2
		}
	}
	return s[start : end+1] // Estrae la sottostringa
}

// Funzione helper per espandere intorno a un centro
func expand(s string, l int, r int) (int, int) {
	for l >= 0 && r < len(s) && s[l] == s[r] {
		l--
		r++
	}
	// Regola gli indici all'ultimo palindromo valido
	return l + 1, r - 1
}
