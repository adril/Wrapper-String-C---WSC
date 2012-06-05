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


___________________________________________

### Append Character ###

    WStringC *string = String("Hello World");

    string->append('x', string);
    string->show(string);
    string->destroy(string);

##### Output #####

> Hello Worldx

___________________________________________

### Append String ###

    WStringC *string = String("Hello World");

    string->append_str_string("Wrap", string);
    string->show(string);
    string->destroy(string);

##### Output #####

> Hello WorldWrap

___________________________________________

### Append WStringC ###

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

##### Output #####

> before split:
>  
> hello;World;42;42|24  
>  
> after split:
>  
> hello  
> World  
> 42  
> 42  
> 24  

___________________________________________

### Compare Character ###
    
    WStringC *string = String("x");

    if (string->compare('x', string))
       printf("string == x");
    else
       printf("string != x");

    string->destroy(string);

##### Output #####

> string == x

___________________________________________

### Compare String ###

    WStringC *string = String("Hello World");

    if (string->compare_str("Hello World", string))
       printf("string == Hello World\n");
    else
       printf("string != Hello World\n");

    string->destroy(string);


##### Output #####

> string == Hello World

___________________________________________

### Compare WStringC ###

    WStringC *string = String("Hello World");
    WStringC *stringToCompare = String("Hello World");

    if (string->compare_string(stringToCompare, string))
       printf("string == Hello World\n");
    else
       printf("string != Hello World\n");

    string->destroy(string);

##### Output #####

> string == Hello World

___________________________________________

## Installation ##

### Comming soon ###

...


## Markdown plus tables ##

| Header | Header | Right  |
| ------ | ------ | -----: |
|  Cell  |  Cell  |   $10  |
|  Cell  |  Cell  |   $20  |
