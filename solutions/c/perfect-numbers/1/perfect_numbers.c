#include "perfect_numbers.h"
#include <stdio.h>

kind classify_number (int number){
    if (number <= 0) return ERROR;
    int a_sum = aliquot_sum(number);
    if (number < a_sum) return ABUNDANT_NUMBER;
    if (number > a_sum) return DEFICIENT_NUMBER;
    return PERFECT_NUMBER;
}

int aliquot_sum(int number){
    int sum = 0;
    for (int i = 1; i * 2 <= number; i++){
        if (number % i == 0) sum += i;
    }
    return sum;
}
