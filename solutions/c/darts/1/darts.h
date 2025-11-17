#ifndef DARTS_H
#define DARTS_H

#include <stdint.h>
#endif

typedef struct {
    float x;
    float y;
} coordinate_t;

uint8_t score(coordinate_t landing_position);

int in_circle_of_radius(coordinate_t position, int radius);
