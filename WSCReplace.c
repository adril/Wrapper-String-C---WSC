#include "WStringC.h"

int replace(char c_old, char c_new, WStringC *string)
{
  int res = 0;
  List *tmp = string->string;

  while (tmp != NULL)
    {
      if (tmp->character->c == c_old)
	{
	  tmp->character->c = c_new;
	  res++;
	}
      tmp = tmp->next;
    }
  return res;
}

int replace_str_index(char *str_old, WStringC *string)
{
  int i = 0;
  int indx_comp = 0;
  List *tmp = string->string;
  List *tmp_comp;

  while (tmp != NULL)
    {
      printf("%c - %c\n", str_old[i], tmp->character->c);
      indx_comp = 0;
      tmp_comp = tmp;
      for (int res = 0; tmp_comp != NULL && tmp_comp->character->c == str_old[indx_comp]; res++)
	{
	  printf("%c\n", str_old[indx_comp]);
	  if (res == strlen(str_old) - 1)
	    {
	      return i;
	    }
	  indx_comp++;
	  tmp_comp = tmp_comp->next;
	}
      i++;
      tmp = tmp->next;
    }
  return -1;
}

WStringC *replace_str(char *str_old, char *str_new, WStringC *string)
{
  int indx_replace = replace_str_index(str_old, string);
  if (strlen(str_old) == strlen(str_new) && indx_replace >= 0)
    {
      int indx_copy = 0;
      int i = 0;
      List *tmp = string->string;
      while (tmp != NULL)
	{
	  if (++i >= indx_replace)
	    {
	      tmp->character->c = str_new[indx_copy++];
	    }
	  tmp = tmp->next;
	}
      return string;
    }
  return string;
}
