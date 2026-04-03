#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) {
        return "";                                                         //If the string's array size is 0, the prefix is obvious empty
    }
    char* prefix = strs[0];                                                //We assume as the LCP the first word in the array
    for (int i = 1; i < strsSize; i++) {                                 
        while (strncmp(prefix, strs[i], strlen(prefix)) != 0) {            //Then we compare the first word with the second one 
            prefix[strlen(prefix) - 1] = '\0';                             //and we reduce the first one of a char if they are not equal      
            if (strlen(prefix) == 0) {                                     //If we reduce it to zero, there is no common prefix
                return "";                                                 //else we continue the cycle with the prefix 
            }
        }
    }
    return prefix;
}

//The worst-case scenario complexity of this is O(strsSize*L^2)
//where L is the length of the longest string, because we cycle strsSize 
//times, shortening the prefix length each time so is strsSize*(L+(L-1)+L(-2)+...1)
