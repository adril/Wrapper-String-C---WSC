#include "WStringC.h"

int		main(int ac, char **av)
{
  (void)ac;
  (void)av;

  WStringC *_string = String("hello world - ");

  _string->show(_string);



  printf("[string]: %s\n", _string->get(_string));

  //INFO: append char test
  _string->append('x', _string);
  _string->append('y', _string);
  _string->append('z', _string);

  _string->show(_string);
  printf("[string] [after append]: %s\n", _string->get(_string));

  //INFO: append char* test

  _string->append_str_string("Wrap", _string);
  _string->append_str_string("BASIC", _string);
  _string->append_str_string("test", _string);


  _string->show(_string);
  printf("[string] [after append]: %s\n", _string->get(_string));


  //INFO: append String test
  WStringC *wscString = String("");
  wscString->show(wscString);
  //  printf("[string]: %s\n", wscString->get(wscString));

  wscString->append_str_string("Wrapper-String-C---WSC", wscString);
  wscString->show(wscString);

  //INFO: append String String

  _string->append_string(wscString, _string);

  _string->show(_string);
  wscString->show(wscString);

  wscString->destroy(wscString);
  _string->destroy(_string);

  //INFO: split String
  WStringC *splitMe = String("hello;World;42;42|24");
  splitMe->show(splitMe);

  WStringC **splitList = splitMe->split(";|", splitMe);
  int i = 0;
  while (splitList[i] != NULL)
    {
      splitList[i]->show(splitList[i]);
      //splitList[i]->destroy(splitList[i]);
      i++;
    }
  //  free(splitList);

  //INFO: compare
  i = 0;
  while (splitList[i] != NULL)
    {
      splitList[i]->show(splitList[i]);
      if (splitList[i + 1] != NULL)
	{
	  if (splitList[i]->compare_string(splitList[i], splitList[i + 1]))
	    {
	      printf("[compare] [equal]: %s %s\n", splitList[i]->get(splitList[i]), splitList[i + 1]->get(splitList[i + 1]));
	    }
	  else
	    {
	      printf("[compare] [diferent]: %s %s\n", splitList[i]->get(splitList[i]), splitList[i + 1]->get(splitList[i + 1]));
	    }
	}

      splitList[i]->destroy(splitList[i]);
      i++;
    }

  free(splitList);
  splitMe->destroy(splitMe);

}
