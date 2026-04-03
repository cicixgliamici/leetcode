#include <stdbool.h>
#include <limits.h>

bool isPalindrome(int x) {
    //The question is tricky, but the example 2 helps you 
    if (x < 0) {
        return false;
    }
    // We want to save the original number and reverse it
    int original = x;
    int reversed = 0;
    while (x > 0) {
        int lastDigit = x % 10;                                 //Extract the last digit of a number, because the % will give us
                                                                //the rest of the division -> 12 % 10 = 1 rest 2
        if (reversed > (INT_MAX-lastDigit)/10) {                //On the first submission I got the error "signed integer overflow"
            return false;                                       //So we need to consider it, not because a "big number" cannot be palindrome
        }                                                       //but because during the process we will overflow it
      
        reversed=reversed*10 + lastDigit;                       //We add a 0 to the reversed number by multiplying for 10, then adding in that "empty" space
        x /= 10;                                                //the digit we found from the %10, hence we cut the original number of one digit
    }
    return original == reversed;                                //If the original number and the reversed are equal we'll have True
}

/* An example:
   Data
       original=1234
       reversed=0
   First iteration:
       lastDigit=> 1234 % 10= 123 with rest 4 so lastDigit=4
       reversed=0*10 +4= 4
       original= original/10= 123
   Second iteration:
       lastDigit=> 123 % 10= 3
       reversed=4*10 +3= 43
       original= original/10= 12
   Third iteration:
       lastDigit=> 12 % 10= 2
       reversed=43*10 +2= 432
       original= original/10= 1
   Last iteration:
       lastDigit=> 1 % 10= 1
       reversed=432*10 +1= 4321
       original= original/10= 0
   Comparison:
       original == reversed ? -> 1234 != 4321 so 1234 is not palindrome
*/
