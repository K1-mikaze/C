#include <stdlib.h>

unsigned int c_string_size(const char *c_string) {
  unsigned int counter = 0;
  while (c_string[counter] != '\0') {
    counter += 1;
  }
  return counter;
}

const char *c_string_concat(const char *cstr1, const char *cstr2) {
  int size = c_string_size(cstr1) + c_string_size(cstr2);
  char *newStr = malloc(sizeof(char) * size);
  for (unsigned short i = 0; i < c_string_size(cstr1); i++) {
    newStr[i] = cstr1[i];
  }
  int short counter = 0;
  for (unsigned short int i = c_string_size(cstr1); i < size; i++) {
    newStr[i] = cstr2[counter];
    counter++;
  }
  newStr[size] = '\0';
  return newStr;
}
