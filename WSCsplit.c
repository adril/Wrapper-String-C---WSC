#include "WStringC.h"

//INFO: split functions

int is_sep(char c, char *separator)
{
  int i = 0;

  while (separator[i] != '\0')
    {
      if (separator[i++] == c)
	{
	  return TRUE;
	}
    }
  return FALSE;
}


int count_nb_sep(char *separator, WStringC *string_in)
{
  int res = 1;
  List *tmp = string_in->string;

  while (tmp != NULL)
    {
      if (is_sep(tmp->character->c, separator) == TRUE)
	{
	  res++;
	}
      tmp = tmp->next;
    }
  return res;
}

WStringC **split(char *separator, WStringC *string_in)
{
  List *tmp = string_in->string;
  WStringC **splitList = malloc((count_nb_sep(separator, string_in) + 1) * sizeof(*splitList));
  int ellem = 0;

  splitList[ellem] = String("");
  while (tmp != NULL)
    {
      if (is_sep(tmp->character->c, separator) == TRUE)
	{
	  ellem++;
	  //splitList = realloc(splitList, (ellem + 1) * sizeof(*splitList));
	  splitList[ellem] = String("");
	}
      else
	{
	  splitList[ellem]->append(tmp->character->c, splitList[ellem]);
	}
      tmp = tmp->next;
    }
  ellem++;
  splitList[ellem] = NULL;
  return splitList;
}

