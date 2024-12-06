#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Funzione di supporto per verificare se una coppia di parentesi è valida
bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

// Funzione principale richiesta
bool isValid(char* s) {
    int len = strlen(s);
    char* stack = (char*)malloc(len * sizeof(char));
    if (!stack) return false;
    int top = -1;
    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        if (c == '(' || c == '{' || c == '[') {
            stack[++top] = c; 
        } 
        else if (c == ')' || c == '}' || c == ']') {
            if (top == -1 || !isMatchingPair(stack[top], c)) {
                free(stack);
                return false;
            }
            top--;
        } 
        else {
            free(stack);
            return false;
        }
    }
    bool isValid = (top == -1);
    free(stack);
    return isValid;
}
