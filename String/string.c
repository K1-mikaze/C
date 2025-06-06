#include "string.h"
#include "c_str_fucn.h"
#include <stdlib.h>

String *string(const char *str) {
  String *string = malloc(sizeof(String));
  string->lenght = c_string_size(str);
  string->capacity = string->lenght + 1;
  string->data = malloc(string->capacity);

  string->data = str;
  return string;
}

String *stringconcat(const String *str1, const String *str2) {
  String *string = malloc(sizeof(String));
  string->lenght = c_string_size(str1->data) + c_string_size((str2->data));
  string->capacity = string->lenght + 1;
  string->data = malloc(string->capacity);

  string->data = c_string_concat(str1->data, str2->data);
  return string;
}
