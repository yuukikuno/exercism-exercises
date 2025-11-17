#include "resistor_color_trio.h"
#include <math.h>
#include <stdio.h>

resistor_value_t color_code(resistor_band_t bands[3]) {
  resistor_value_t result;
  int value = (bands[0] * 10 + bands[1]);
  result.unit = OHMS;
  for (int i = 1; i <= (int) bands[2]; i++){
      // printf("%d", i);
      value *= 10;
      if (value % 1000 == 0) {
          value /= 1000;
          result.unit ++;
      }
  }
  result.value = value;
  return result;
}
