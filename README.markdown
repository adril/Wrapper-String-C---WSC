# Wrapper-String-C---WSC #

Wrapper-String-C (WSC) is a simple library C wrapper to manipulate strings.
The main functions are describe below:

* creating a WStringC wich is a kind of object, it have to be passed to each functions every times.
* playing with it :)
* append - split - replace (soon) - compare character (char), string(char *), WStringC.


## Demos ##

### Get started ###

First include the header file

`#include "WStringC.h"`

Then we declare WString object and set it with String function which takes the string parameter. 

    WStringC *string = String("Hello World");

    string->show(string);
    string->destroy(string);

##### Output #####

> Hello World

### Append Character ###

    WStringC *string = String("Hello World");

    string->append('x', string);
    string->destroy(string);

### Append String ###

    WStringC *string = String("Hello World");

    string->append_str_string("Wrap", string);
    string->destroy(string);

### Append WStringC ###

    WStringC *splitMe = String("hello;World;42;42|24");

    splitMe->show(splitMe);

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

##### Output #####

> hello;World;42;42|24  
> hello  
> World  
> 42  
> 42  
> 24  

### Compare Character ###
    
    WStringC *string = String("x");

    if (string->compare('x', string))
       printf("string == x");
    else
       printf("string != x");

    string->destroy(string);

##### Output #####

> string == x

### Compare String ###

    WStringC *string = String("Hello World");

    if (string->compare_str("Hello World", string))
       printf("string == Hello World");
    else
       printf("string != Hello World");

    string->destroy(string);


##### Output #####

> string == Hello World

### Compare WStringC ###

    WStringC *string = String("Hello World");
    WStringC *stringToCompare = String("Hello World");

    if (string->compare_string(stringToCompare, string))
       printf("string == Hello World");
    else
       printf("string != Hello World");

    string->destroy(string);

##### Output #####

> string == Hello World


## Installation ##

### Comming soon ###

...


## Markdown plus tables ##

| Header | Header | Right  |
| ------ | ------ | -----: |
|  Cell  |  Cell  |   $10  |
|  Cell  |  Cell  |   $20  |
