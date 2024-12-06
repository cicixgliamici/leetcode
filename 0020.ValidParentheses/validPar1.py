class Solution:
    def isValid(self, s: str) -> bool:
        # Dizionario per le parentesi corrispondenti
        matching_pairs = {')': '(', '}': '{', ']': '['}
        stack = []  # Usato come stack
        # Itera attraverso i caratteri della stringa
        for char in s:
            if char in matching_pairs.values():
                # Se è una parentesi aperta, aggiungila allo stack
                stack.append(char)
            elif char in matching_pairs.keys():
                # Se è una parentesi chiusa, controlla lo stack
                if not stack or stack[-1] != matching_pairs[char]:
                    return False
                stack.pop()  # Rimuovi l'ultima parentesi aperta
            else:
                # Carattere non valido (non necessario per LeetCode, ma può essere aggiunto)
                return False
        # Se lo stack è vuoto alla fine, la stringa è valida
        return not stack
