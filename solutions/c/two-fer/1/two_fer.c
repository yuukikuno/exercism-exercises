#include "two_fer.h"
#include <string.h>

void two_fer(char *buffer, const char *name){
    strcpy(buffer, "One for ");
    if (!name){
        strcat(buffer, "you");
    } else {
        strcat(buffer, name);
    }
    strcat(buffer, ", one for me.");
    return;
}
