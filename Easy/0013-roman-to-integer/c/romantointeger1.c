#include <stdio.h>

//We need to read at least one character at the time, but we may want to read the next one 
//if there is a "subtraction" like in IV
int romanToInt(char* s) {
    int total = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'I') {
            if (s[i+1] == 'V') {
                total += 4;
                i++;                          //If we read 2 characters, than we must skip two position of the string
            } else if (s[i+1] == 'X') {
                total += 9;
                i++;
            } else {
                total += 1;
            }
        } else if (s[i] == 'V') {
            total += 5;
        } else if (s[i] == 'X') {
            if (s[i+1] == 'L') {
                total += 40;
                i++;
            } else if (s[i+1] == 'C') {
                total += 90;
                i++;
            } else {
                total += 10;
            }
        } else if (s[i] == 'L') {
            total += 50;
        } else if (s[i] == 'C') {
            if (s[i+1] == 'D') {
                total += 400;
                i++;
            } else if (s[i+1] == 'M') {
                total += 900;
                i++;
            } else {
                total += 100;
            }
        } else if (s[i] == 'D') {
            total += 500;
        } else if (s[i] == 'M') {
            total += 1000;
        }
    }
    return total;
}
