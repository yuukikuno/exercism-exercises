#include "resistor_color.h"
#include <stdint.h>

static resistor_band_t all_colors[] = {COLORS};

uint16_t color_code(resistor_band_t band_color) { return band_color; }

resistor_band_t *colors() { return all_colors; }
