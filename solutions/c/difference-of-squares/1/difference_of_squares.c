#include "difference_of_squares.h"

unsigned int square_of_sum(unsigned int number){
    unsigned int sum = 0;
    while (number > 0){
        sum += number;
        number --;
    }
    return sum * sum;
}

unsigned int sum_of_squares(unsigned int number){
    unsigned int result = 0;
    while (number > 0){
        result += number * number;
        number --;
    }
    return result;
}

unsigned int difference_of_squares(unsigned int number){
    return square_of_sum(number) - sum_of_squares(number);
}
