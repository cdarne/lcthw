#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Forward declarations
void print_letters(char arg[], size_t len);

void print_arguments(int argc, char *argv[]) {
  int i;

  for(i = 0; i < argc; i++) {
    print_letters(argv[i], strlen(argv[i]));
  }
}

void print_letters(char arg[], size_t len) {
  int i;

  for(i = 0; i < len; i++) {
    char ch = arg[i];

    if(isprint(ch)) {
      printf("'%c' == %d ", ch, ch);
    }
  }
  printf("\n");
}

int main(int argc, char * argv[]) {
  print_arguments(argc, argv);
  return 0;
}
