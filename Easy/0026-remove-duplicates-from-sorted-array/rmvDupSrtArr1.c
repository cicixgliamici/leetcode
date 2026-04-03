int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) { // Verifica se l'array è vuoto
        return 0;
    }
    int k = 1; // Indice per tracciare la posizione dell'ultimo elemento unico
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[k - 1]) { // Se l'elemento corrente è diverso dall'ultimo unico
            nums[k] = nums[i]; // Aggiorna la posizione dell'elemento unico
            k++; // Incrementa il contatore degli elementi unici
        }
    }
    return k; // Restituisce il numero di elementi unici
}