#include "darts.h"
#include <stdint.h>

uint8_t score(coordinate_t landing_position) {

    if (in_circle_of_radius(landing_position, 1))
        return 10;
    if (in_circle_of_radius(landing_position, 5))
        return 5;
    if (in_circle_of_radius(landing_position, 10))
        return 1;
    return 0;
}

int in_circle_of_radius(coordinate_t position, int radius){
    return (position.x * position.x +
            position.y * position.y <=
        (radius * radius));
}
