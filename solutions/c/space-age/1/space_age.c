#include "space_age.h"

float age(planet_t planet, int64_t seconds) {
  if (orbital_period(planet) == -1)
    return -1;
  return ((float)seconds / (60 * 60 * 24 * 365)) / orbital_period(planet);
}

float orbital_period(planet_t planet) {
  switch (planet) {
  case MERCURY:
    return 0.2408467f;
  case VENUS:
    return 0.6151972f;
  case EARTH:
    return 1.0f;
  case MARS:
    return 1.8808158f;
  case JUPITER:
    return 11.862615f;
  case SATURN:
    return 29.447498f;
  case URANUS:
    return 84.016846f;
  case NEPTUNE:
    return 164.79132f;
  default:
    return -1.0f;
  }
}
