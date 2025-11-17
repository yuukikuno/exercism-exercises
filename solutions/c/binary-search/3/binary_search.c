#include "binary_search.h"
#include <stddef.h>
#include <stdio.h>

const int *binary_search(int value, const int *arr, size_t length) {
  size_t left = 0, right = length;
  while (left < right) {
    size_t mid = left + (right - left) / 2;
    if (arr[mid] == value)
      return &arr[mid];
    if (value < arr[mid])
        right = mid;
    else
        left = mid +1;
  }
  return NULL;
}
