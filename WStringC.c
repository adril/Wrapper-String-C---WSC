#include "WStringC.h"

WStringC* String(char const* str_string)
{
  WStringC *string = malloc(sizeof(*string));

  //INFO: main functions
  string->destroy = destroy;

  string->add = add;
  string->last = last;

  //INFO: append
  string->append = append;
  string->append_str_string = append_str_string;
  string->append_string = append_string;

  //INFO: split
  string->split = split;

  //INFO: compare
  string->compare = compare;
  string->compare_str = compare_str;
  string->compare_string = compare_string;

  //INFO: replace

  //INFO: misc functions
  string->show = show;
  string->get = get;

  //INFO: init
  string->size = 0;
  str_to_list(str_string, string);

  return string;
}

void destroy(WStringC *string)
{
  List *tmp = string->string;
  List *sav = NULL;

  while (tmp != NULL)
    {
      //printf("destroying: %c\n", tmp->character->c);
      sav = tmp;
      tmp = tmp->next;
      free(sav->character);
      free(sav);
    }
  free(string);
}

//INFO: display functions

void show(WStringC *string)
{
  List *tmp = string->string;

  while (tmp != NULL)
    {
      printf("%c", tmp->character->c);
      tmp = tmp->next;
    }
  printf("\n");
}

char *get(WStringC *string)
{
  List *tmp = string->string;
  char *res = malloc((string->size + 1) * sizeof(*res));
  //printf("size: %d\n", string->size);
  size_t i = 0;

  while (tmp != NULL)
    {
      res[i++] = tmp->character->c;
      tmp = tmp->next;
    }
  res[i] = '\0';
  return res;
}

//INFO: list functions

void str_to_list(char const* str_string, WStringC *string)
{
  int i = 0;

  if (strlen(str_string) > 0)
    {
      string->string = malloc(sizeof(*string->string));
      List *tmp = string->string;

      for (i = 0; i < strlen(str_string); i++)
	{
	  (*(string->add))(str_string[i], tmp);
	  //printf("add: str_string[%c] at index %d\n", str_string[i], i);
	  if (i == strlen(str_string) - 1)
	    {
	      tmp->next = NULL;
	    }
	  else
	    {
	      tmp->next = malloc(sizeof(*tmp->next));
	    }
	  tmp = tmp->next;
	}
    }
  string->size = i;
}

List* last(WStringC *string)
{
  List *last_string = NULL;
  List *tmp = string->string;
  size_t i = 0;

  while (tmp != NULL)
    {
      last_string = tmp;
      tmp = tmp->next;
    }
  return last_string;
}

void add(char c, List *string)
{
  //printf("[add]: %c\n", c);
  Character *character = malloc(sizeof(*character));

  character->c = c;
  string->character = character;
  string->next = NULL;
}

