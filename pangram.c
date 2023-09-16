#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

bool ispangram(char *s) {
  // TODO implement this!
  int bitset = 0;
  for (char *i=s; *i; i++){
        char c = tolower(*i);
        if (c <'a' || c>'z') continue;
        bitset |= 1 << (c -'a');
      }
        return bitset == 0x03ffffff;
  }

int main() {
  size_t len;
  ssize_t read;
  char *line = NULL;
  while ((read = getline(&line, &len, stdin)) != -1) {
    if (ispangram(line))
      printf("%s", line);
  }

  if (ferror(stdin))
    fprintf(stderr, "Error reading from stdin");

  free(line);
  fprintf(stderr, "ok\n");
}