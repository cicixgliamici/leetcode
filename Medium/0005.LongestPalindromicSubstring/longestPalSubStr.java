public class Solution {
    public String longestPalindrome(String s) {
        if (s == null || s.length() < 1) return "";
        int start = 0, end = 0;
        
        // Itera su ogni carattere come potenziale centro
        for (int i = 0; i < s.length(); i++) {
            // Palindromi dispari (centro in i)
            int[] odd = expand(s, i, i);
            // Palindromi pari (centro tra i e i+1)
            int[] even = expand(s, i, i + 1);
            
            // Aggiorna gli indici del palindromo più lungo
            if (odd[1] - odd[0] > end - start) {
                start = odd[0];
                end = odd[1];
            }
            if (even[1] - even[0] > end - start) {
                start = even[0];
                end = even[1];
            }
        }
        // Estrae la sottostringa (end+1 perché substring esclude l'indice finale)
        return s.substring(start, end + 1);
    }
    
    // Funzione helper per espandere intorno a un centro
    private int[] expand(String s, int l, int r) {
        while (l >= 0 && r < s.length() && s.charAt(l) == s.charAt(r)) {
            l--;
            r++;
        }
        // Regola gli indici all'ultimo palindromo valido
        return new int[]{l + 1, r - 1};
    }
}