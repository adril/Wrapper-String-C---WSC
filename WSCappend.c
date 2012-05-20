#include "WStringC.h"

//INFO: append functions

void append(char c, WStringC *string)
{
  List *last = string->last(string);

  if (last != NULL)
    {
      //printf("last character: %c\n", last->character->c);
      last->next = malloc(sizeof(*last->next));
      string->add(c, last->next);
    }
  else
    {
      last = malloc(sizeof(*last));
      string->string = last;
      string->add(c, last);
    }
  string->size++;
}

void append_str_string(char const *str_string, WStringC *string)
{
  int i = 0;
  while (str_string[i] != '\0')
    {
      string->append(str_string[i++], string);
    }
}

void append_string(WStringC *src_string, WStringC *string)
{
  int i = 0;
  char *str_src_string = src_string->get(src_string);

  while (str_src_string[i])
    {
      string->append(str_src_string[i++], string);
    }
  free(str_src_string);
}
