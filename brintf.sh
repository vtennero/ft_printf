#!/bin/bash

	#printf "\"$1\""
	#X="\"$1\""
	X=$1
	toto="'s/TEXT .*/TEXT $X/g'"
	echo $X
	echo $toto
	#sed -i -e '/TEXT .*/TEXT '$X'/g' ft_printf.h
	sed -i -e $toto ft_printf.h
	make re
	./dummy_test | cat -e
