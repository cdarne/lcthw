#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>

#include "object.h"
#include "game.h"
#include "../utils.h"

Object RoomProto;
Object MonsterProto;
Object MapProto;

int Map_init(void *self) {
  assert(self != NULL);
  Map *map = self;

  // make some rooms for a small 
  Room *hall = NEW(Room, "The great Hall");
  Room *throne = NEW(Room, "The throne room");
  Room *arena = NEW(Room, "The arena, with the minotaur");
  Room *kitchen = NEW(Room, "Kitchen, you have a knife now");

  // put the bad guy in the arena
  arena->bad_guy = NEW(Monster, "The evil minotaur");

  // setup the map rooms
  hall->north = throne;

  throne->west = arena;
  throne->east = kitchen;
  throne->south = hall;

  arena->east = throne;
  kitchen->west = throne;

  // start the map and the character off in the hall
  map->start = hall;
  map->location = hall;

  return 1;
}


int main(int argc, char *argv[]) {
  USE(argc);
  USE(argv);

  MapProto.init = Map_init;

  // simple way to setup the randomness
  srand(time(NULL));

  // make our map to work with
  Map *game = NEW(Map, "The Hall of the Minotaur.");

  printf("You enter the ");

  game->location->_(describe)(game->location);

  while(process_input(game)) {
  }

  return 0;
}
