#include "grains.h"
#include <math.h>
#include <stdint.h>

uint64_t square(uint8_t index){
    return pow(2, index - 1);
}

uint64_t total(){
    return UINT64_MAX;
}
