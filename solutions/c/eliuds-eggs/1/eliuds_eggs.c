#include "eliuds_eggs.h"
#include <stdint.h>

unsigned int egg_count(unsigned int display_number){
    unsigned int egg_count = 0;
        while (display_number != 0){
            if (display_number & 1)
                egg_count ++;
            display_number >>= 1;
        }
    return egg_count;
}
