# ft_printf (Work in Progress)

The goal of the project is to recode the printf function (man 3 printf).

## Installing

Clone the repository and: 

```
make
```

### For Linux users only

In the makefile, replace :

```
-Wall -Werror -Wextra
```
with:
```
-Wall -Wno-empty-body -Wno-unused -Wextra
```

Note: this prinft is made for Mac use and won't run the same way on Linux.

## Running the tests

The easiest way is to add a .c with a main function that calls ft_printf with the parameters of your choice, compile it with libftprintf.a, then run the newly created executable.

Examples of tests:

```
ft_printf("//buffer[1]//%50.5 -0s//buffer[2]//%s%.4s %5.4d", "Oh Captain My ", "Cap", "tain", 350);
ft_printf("%d %U", 6, 5);
ft_printf("%#+0- 10.5s", NULL);
ft_printf("%5.5 0 d", 450);
ft_printf("%.-60d", 44);
ft_printf("Bonjour %10.4d, ca va ? %054-d", -44, 52);
ft_printf("%50.5 0s", "Oh Captain My Captain");
ft_printf("%010.5s", "Oh Captain My Captain");
```

## Features

Conversions with : sSpdDioOuUxXcC 

Strings containing : %%

All flags: #0-+ and space

Minimum ﬁeld-width

Precision

The following length specifiers: hh h l ll j z

### Undefined behavior

Overlap and/or override of flags/specifiers/converters.

For example:

```
ft_printf("%#+0- 10.5s", NULL);
```

## Additional Resources

Instructions : [Subject](http://bit.ly/2le7CAs)

Test programs (not made by me) : [1. 42FC](https://github.com/jgigault/42FileChecker) [2. curqui_test](https://github.com/curquiza/curqui_test)

## Author

* **Victor Tenneroni** - [Website](http://victor-tenneroni.com/)
