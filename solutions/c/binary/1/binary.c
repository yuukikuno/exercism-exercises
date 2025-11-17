#include "binary.h"
#include <string.h>

int convert(const char *input){
    int result = 0;
    int weight = 1;
    for (size_t i = strlen(input); i-- > 0; ) {
        if (input[i] != '0' && input[i] != '1'){
            return INVALID;
        }
        if (input[i] == '1')
            result += weight;
        weight *= 2;
    }
    return result;
}
