#include "dnd_character.h"
#include "stdlib.h"
dnd_character_t make_dnd_character(void) {
  dnd_character_t character;
  character.strength = ability();
  character.dexterity = ability();
  character.constitution = ability();
  character.intelligence = ability();
  character.wisdom = ability();
  character.charisma = ability();
  character.hitpoints = modifier(character.constitution) + 10;
  return character;
}

int modifier(int score) {
  int n = score - 10;
  return n / 2 - (n < 0 && n % 2 != 0);
}

int ability(void) {
  int dice[4];
  int min_idx = 0;
  int sum = 0;
  for (int i = 0; i < 4; i++) {
    dice[i] = roll_die();
    if (dice[i] < dice[min_idx]) {
      min_idx = i;
    }
    sum += dice[i];
  }

  sum -= dice[min_idx];
  return sum;
}

int roll_die() { return (rand() % 6) + 1; }
