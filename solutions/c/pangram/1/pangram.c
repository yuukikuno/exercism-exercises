#include "pangram.h"
#include <stdio.h>
#include <string.h>

bool is_pangram(const char *sentence){
    if (sentence == NULL) return false;
    int found_mask = 0;
    int bit = 1;
    int index;
    while (*sentence){
        if (*sentence >= 'A' && *sentence <='Z'){
            index = *sentence - 'A';
            found_mask |= bit << index;
        } else if (*sentence >= 'a' && *sentence <= 'z'){
            index = *sentence - 'a';
            found_mask |= bit << index;
        }
        sentence ++;
    }
    printf("%d", found_mask);
    if (found_mask == (1 << 26 )- 1) return true;
    return false;
}
