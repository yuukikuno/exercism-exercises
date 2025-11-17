#include "resistor_color.h"
#include <stdint.h>

static const resistor_band_t all_colors[] = {BLACK, BROWN, RED,    ORANGE, YELLOW,
                      GREEN, BLUE,  VIOLET, GREY,   WHITE};

uint16_t color_code(resistor_band_t band_color) { return band_color; }

const resistor_band_t* colors() { return all_colors; }
