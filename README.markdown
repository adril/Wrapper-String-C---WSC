# Wrapper-String-C---WSC #

Wrapper-String-C (WSC) is a simple library C wrapper to manipulate strings.
The main functions are describe below:

* creating a WStringC wich is a kind of object, it have to be passed to each functions every times.
* playing with it :)
* append - split - replace - compare character (char), string(char *), WStringC.


## Demos ##

### Get started ###

    WStringC *string = String("Hello World");
    string->show(string);
    string->destroy(string);

### Append Character ###

      string->append('x', string);

### Append String ###

      string->append_str_string("Wrap", string);


### Append WStringC ###

    //INFO: split String
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


## Installation ##

### Comming soon ###

...

* * * *
****
--------------------------


## Markdown plus tables ##

| Header | Header | Right  |
| ------ | ------ | -----: |
|  Cell  |  Cell  |   $10  |
|  Cell  |  Cell  |   $20  |
