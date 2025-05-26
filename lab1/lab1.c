#include <stdio.h>
#include <string.h>

int main() {
  char buffer[32];
  char *b = buffer;
  size_t bufsize = 32;
  size_t characters;

  printf("Please enter some text: ");
  characters = getline(&b, &bufsize, stdin);

  printf("Tokens:\n");

  char *token;
  char *saveptr;

  token = strtok_r(b, " ", &saveptr);
  while (token != NULL) {
    printf("  %s\n", token);
    token = strtok_r(NULL, " ", &saveptr);
  }

  return 0;
}
