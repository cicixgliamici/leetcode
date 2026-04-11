#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Funzione helper per espandere intorno a un centro e trovare il palindromo più lungo
void expand(char *s, int len, int l, int r, int *new_l, int *new_r) {
    // Continua a espandere finché i caratteri a sinistra e destra sono uguali
    while (l >= 0 && r < len && s[l] == s[r]) {
        l--;
        r++;
    }
    // Regola gli indici per tornare all'ultimo palindromo valido
    *new_l = l + 1;
    *new_r = r - 1;
}

char* longestPalindrome(char* s) {
    int len = strlen(s);
    if (len == 0) { // Caso stringa vuota
        char* result = (char*)malloc(1);
        result[0] = '\0';
        return result;
    }
    
    int start = 0, end = 0;
    for (int i = 0; i < len; i++) {
        // Palindromi di lunghezza dispari (centro in i)
        int l_odd, r_odd;
        expand(s, len, i, i, &l_odd, &r_odd);
        
        // Palindromi di lunghezza pari (centro tra i e i+1)
        int l_even, r_even;
        expand(s, len, i, i + 1, &l_even, &r_even);
        
        // Aggiorna gli indici del palindromo più lungo trovato
        if (r_odd - l_odd > end - start) {
            start = l_odd;
            end = r_odd;
        }
        if (r_even - l_even > end - start) {
            start = l_even;
            end = r_even;
        }
    }
    
    // Alloca memoria per il risultato e copia la sottostringa
    int result_len = end - start + 1;
    char* result = (char*)malloc(result_len + 1); // +1 per il terminatore nullo
    strncpy(result, s + start, result_len);
    result[result_len] = '\0';
    return result;
}