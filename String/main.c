#include "string.h"
#include <stdio.h>

int main() {
  String *str1 = string("hello");
  String *str2 = string("bye");

  String *str3 = stringconcat(str1, str2);

  printf("%s\n", str3->data);
  return 0;
}
