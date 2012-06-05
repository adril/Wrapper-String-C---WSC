#include "WStringC.h"
#include "test.h"

void		test()
{
  WStringC *string = String("Hello World");

  string->show(string);
  string->destroy(string);
}

void		test_a()
{
  WStringC *string = String("Hello World");

  string->append('x', string);
  string->show(string);
  string->destroy(string);
}

void		test_b()
{
  WStringC *string = String("Hello World");

  string->append_str_string("Wrap", string);
  string->show(string);
  string->destroy(string);
}

void		test_c()
{
  //INFO: split String
  WStringC *splitMe = String("hello;World;42;42|24");

  printf("before split:\n\n");
  splitMe->show(splitMe);
  printf("\nafter split:\n\n");

  WStringC **splitList = splitMe->split(";|", splitMe);
  int i = 0;
  while (splitList[i] != NULL)
    {
      splitList[i]->show(splitList[i]);
      splitList[i]->destroy(splitList[i]);
      i++;
    }
  free(splitList);
  free(splitMe);
}

void		test_d()
{
  WStringC *string = String("x");

  if (string->compare('x', string))
    printf("string == x\n");
  else
    printf("string != x\n");

  string->destroy(string);
}

void		test_e()
{
  WStringC *string = String("Hello World\n");

  if (string->compare_str("Hello World\n", string))
    printf("string == Hello World\n");
  else
    printf("string != Hello World\n");

  string->destroy(string);
}

void		test_f()
{
  WStringC *string = String("Hello World");
  WStringC *stringToCompare = String("Hello World");

  if (string->compare_string(stringToCompare, string))
    printf("string == Hello World\n");
  else
    printf("string != Hello World\n");

  string->destroy(string);
}

