#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

struct Person {
	char *name;
	int age;
	int height;
	int weight;
};

struct Person *Person_create(char *name, int age, int height, int weight)
{
	struct Person *who = malloc(sizeof(struct Person));
	assert(who != NULL);
	who->name = strdup(name);
	who->age = age;
	who->height = height;
	who->weight = weight;

	return who;
}

void Person_destroy(struct Person *who)
{
	assert(who != NULL);

	free(who->name);
	free(who);
}

void Person_print(struct Person *who)
{
	printf("Name: %s\n", who->name);
	printf("Age: %d\n", who->age);
	printf("Height: %d\n", who->height);
	printf("Weight: %d\n", who->weight);
}

int main(int argc, char *argv[])
{
	USE(argc);
	USE(argv);
	// make two people structures
	struct Person *joe = Person_create(
			"Joe Alex", 32, 64, 140);

	struct Person *ced = Person_create(
			"Ced", 28, 175, 75);

	printf("Joe is at memory location: %p\n", joe);
	Person_print(joe);

	printf("Ced is at memory location: %p\n", ced);
	Person_print(ced);

	// make everyone age 20 years and print them again
	joe->age += 20;
	joe->height -= 2;
	joe->weight += 40;
	Person_print(joe);

	ced->age += 20;
	ced->weight -= 5;
	Person_print(ced);

	// destroy them both so we clean up
	Person_destroy(joe);
	Person_destroy(ced);

	return 0;
}
