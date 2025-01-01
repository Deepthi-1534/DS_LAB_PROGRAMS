#include <stdio.h>
#include <string.h>

char* removeDigit(char* number, char digit) {
    int len = strlen(number);
    
    for (int i = 0; i < len - 1; i++) {
        if (number[i] == digit && number[i] < number[i + 1]) {
            memmove(&number[i], &number[i + 1], len - i); 
            return number;
        }
    }

    
    for (int i = len - 1; i >= 0; i--) {
        if (number[i] == digit) {
            
            memmove(&number[i], &number[i + 1], len - i); 
            return number;
        }
    }

    return number; 
}
