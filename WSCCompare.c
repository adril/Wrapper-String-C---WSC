#include "WStringC.h"

int compare(char c, WStringC *string)
{
  int res = 0;
  List *tmp = string->string;
  while (tmp != NULL)
    {
      if (tmp->character->c == c)
	{
	  res++;
	}
      tmp = tmp->next;
    }
  return res;
}

int compare_str(char *str, WStringC *string)
{
  int res = 0;
  int i = 0;
  List *tmp = string->string;

  while (tmp != NULL && str[i] != NULL)
    {
      if (tmp->character->c != str[i++])
	{
	  return FALSE;
	}
      tmp = tmp->next;
    }
  return TRUE;
}

int compare_string(WStringC *string_src, WStringC *string)
{
  int res = 0;
  int i = 0;
  List *tmp = string->string;
  List *tmp_src = string_src->string;

  while (tmp != NULL && tmp_src != NULL)
    {
      if (tmp->character->c != tmp_src->character->c)
	{
	  return FALSE;
	}
      tmp = tmp->next;
      tmp_src = tmp_src->next;
    }
  return TRUE;
}
