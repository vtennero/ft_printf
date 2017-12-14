/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 19:16:55 by vtennero          #+#    #+#             */
/*   Updated: 2017/12/14 19:34:29 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	int	n;

	n = 6;

	printf("%.4i\n", n);
	printf("%10i\n", n);
	printf("%#i\n", n);
	printf("%+i\n", n);
	printf("%-i\n", n);
	printf("% i\n", n);
	printf("%0i\n", n);
	printf("%hi\n", n);
	printf("%hhi\n", n);
	printf("%ji\n", n);
	printf("%li\n", n);
	printf("%lli\n", n);
	printf("%zi\n", n);

		printf("%i\n", n);

	/*printf("basic : \n%d\n", n);
	printf("precision : \n%.4d\n", n);
	printf("width: \n%10d\n", n);
	printf("# : \n%#d\n", n);
	printf("+ : \n%+d\n", n);
	printf("- : \n%-d\n", n);
	printf("space : \n% d\n", n);
	printf("zero : \n%0d\n", n);
	printf("h : \n%hd\n", n);
	printf("hh : \n%hhd\n", n);
	printf("j : \n%jd\n", n);
	printf("l : \n%ld\n", n);
	printf("ll : \n%lld\n", n);
	printf("z : \n%zd\n", n);*/
	return (0);
}
