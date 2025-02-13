#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//The theoretical motivation of the reason you need a stack to achive this type of problem is in the Pumping Lemma and 
//the difference betwen an FSA (Finite State Automata) and a PA (Pushdown automata)

//Return true if the parenthesis are the same
bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') || (open == '[' && close == ']') || (open == '{' && close == '}');
}

bool isValid(char* s) {
    int len = strlen(s);
    char* stack = (char*)malloc(len * sizeof(char));                             //Allocate a stack in order to save the open parenthesis
    if (!stack) return false;                                                    //Prevent error allocation, usually not needed in the Leetcode compiler
    int top = -1;
    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        if (c == '(' || c == '{' || c == '[') {                                  //If it's an opening one, you put it on the top of the stack and
            stack[++top] = c;                                                    //increase the value of top, so that you know there is at least one open
        }                                                                        //also you need to know what is the last type of parenthesi opened
        else if (c == ')' || c == '}' || c == ']') {
            if (top == -1 || !isMatchingPair(stack[top], c)) {                   //If it's a closing one but there is nothing on the stack or it's not
                free(stack);                                                     //matching the last opened, it's wrong
                return false;
            }
            top--;
        } 
        else {
            free(stack);
            return false;
        }
    }
    bool isValid = (top == -1);                                                  //If the stack is free and they all matched, the value is true
    free(stack);
    return isValid;
}
