#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "ex19.h"
#include "../utils.h"

int Monster_attack(void *self, int damage) {
	Monster *monster = self;

	printf("You attack %s!\n", monster->_(description));
	monster->hit_points -= damage;

	if(monster->hit_points > 0) {
		printf("It is still alive.\n");
		return 0;
	} else {
		printf("It is dead!\n");
		return 1;
	}
}

int main(int argc, char *argv[]) {
	USE(argc);
	USE(argv);

	return 0;
}
