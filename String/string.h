#ifndef STRING_H
#define STRING_H

typedef struct {
  const char *data;
  unsigned int capacity;
  unsigned int lenght;
} String;

String *string(const char *str);

String *stringconcat(const String *str1, const String *str2);

#endif // !STRING_H
