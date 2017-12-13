#!/bin/bash

	#printf "\"$1\""
	X="\"$1\""
	#echo $X
	sed -i -e 's/printf(.*)/printf('$X')/g' standard_printf.c
	gcc standard_printf.c
	./a.out