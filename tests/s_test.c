/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 19:16:55 by vtennero          #+#    #+#             */
/*   Updated: 2017/12/14 19:33:55 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	printf("precision : \n%.4s\n", "hello");
	printf("width: \n%10s\n", "hello");
	printf("# : \n%#s\n", "hello");
	printf("+ : \n%+s\n", "hello");
	printf("- : \n%-s\n", "hello");
	printf("space : \n% s\n", "hello");
	printf("zero : \n%0s\n", "hello");
	printf("h : \n%hs\n", "hello");
	printf("hh : \n%hhs\n", "hello");
	printf("j : \n%js\n", "hello");
	printf("l : \n%ls\n", "hello");
	printf("ll : \n%lls\n", "hello");
	printf("z : \n%zs\n", "hello");

		printf("basic : \n%s\n", "hello");
	return (0);
}
