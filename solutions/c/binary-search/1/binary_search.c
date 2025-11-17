#include "binary_search.h"
#include <stddef.h>
#include <stdio.h>

const int *binary_search(int value, const int *arr, size_t length) {
  if (length == 0)
    return NULL;
  size_t mid = length / 2;
  if (value < arr[mid]) {
    return binary_search(value, arr, mid);
  }
  if (value > arr[mid]) {
    return binary_search(value, arr + mid + 1, length - (mid + 1));
  }
  return &arr[mid];
}
