#include "rna_transcription.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *to_rna(const char *dna) {
    size_t len = strlen(dna);
  char *rna = malloc(strlen(dna) + 1);
  for (size_t i = 0; i < len; i++ ){
      rna[i] = to_rna_char(dna[i]);
  }
  rna[len] = '\0';
  return rna;
}

char to_rna_char(char dna_char) {
  switch (dna_char) {
  case 'G':
    return 'C';
  case 'C':
    return 'G';
  case 'T':
    return 'A';
  case 'A':
    return 'U';
  default:
    return EOF;
  }
}
