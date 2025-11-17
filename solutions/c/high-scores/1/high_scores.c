#include "high_scores.h"
#include <stddef.h>

int32_t latest(const int32_t *scores, size_t scores_len) {
  return scores[scores_len - 1];
}

size_t personal_top_three(const int32_t *scores, size_t scores_len,
                          int32_t *output) {
  output[0] = 0;
  output[1] = 0;
  output[2] = 0;
  for (size_t i = 0; i < scores_len; i++) {
    int val = scores[i];
    if (val > output[0]) {
      output[2] = output[1];
      output[1] = output[0];
      output[0] = val;
    } else if (val > output[1]) {
      output[2] = output[1];
      output[1] = val;
    } else if (val > output[2]) {
      output[2] = val;
    }
  }
  return scores_len < 3 ? scores_len : 3;
}

int32_t personal_best(const int32_t *scores, size_t scores_len) {
  int max = 0;
  for (size_t i = 0; i < scores_len; i++){
      if (scores[i] > max) max = scores[i];
  }
  return max;
}
