#include <stdio.h>
#include <stdlib.h>

typedef struct Player {

  char *name;
  struct Hand *hand;

} Player;

typedef struct Hand {

  int size;
  struct Card **cards;

} Hand;

void freePlayer(Player *player) {

  // Frees the playerresources
  free(player->hand->cards);
  free(player->hand);
  free(player);

}