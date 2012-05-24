#ifndef __MY_STRING_H__
#define __MY_STRING_H__

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct s_list List;
typedef struct s_String WStringC;

struct s_String
{
  size_t	size;
  List		*string;
  void		(*add)(char c, List *string);
  List*		(*last)(WStringC *string);
  //
  void		(*append)(char c, WStringC *string);
  void		(*append_str_string)(char const* str_string, WStringC *string);
  void		(*append_string)(WStringC *src_string, WStringC *string);
  //
  WStringC**    (*split)(char *separator, WStringC *string);
  //
  int		(*compare)(char c, WStringC *string);
  int		(*compare_str)(char *str, WStringC *string);
  int		(*compare_string)(WStringC *string_src, WStringC *string);
  //
  void		(*show)(WStringC *string);
  char*		(*get)(WStringC *string);
  //
  void		(*destroy)(WStringC *string);
};

typedef struct s_Character
{
  char		c;
}		Character;

struct		s_list
{
  Character	*character;
  List		*next;
};

WStringC* String(char const* string);
void str_to_list(char const* str_string, WStringC *string);
void add(char c, List *string);
void destroy(WStringC *string);

void append(char c, WStringC *string);
void append_str_string(char const* str_string, WStringC *string);
void append_string(WStringC *src_string, WStringC *string);

WStringC **split(char *separator, WStringC *string);

int compare(char c, WStringC *string);
int compare_str(char *str, WStringC *string);
int compare_string(WStringC *string_src, WStringC *string);

List* last(WStringC *string);
void show(WStringC *string);
char *get(WStringC *string);

#endif /* !__MY_STRING_H__ */
