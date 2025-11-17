#include "armstrong_numbers.h"
#include <stdio.h>
#include <stdlib.h>

bool is_armstrong_number(int candidate){
    int length = snprintf( NULL, 0, "%d", candidate );
    int sum = 0;
    int digit;
    int original = candidate;
    while (candidate != 0){
        digit = candidate % 10;
        sum += int_pow(digit, length);
        candidate /= 10;
    }
    return sum == original;
}

int int_pow(int x, int y){
    int result = x;
    for (int i = 1; i < y; i++){
        result *= x;
    }
    return result;
}
