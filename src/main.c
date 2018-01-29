/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 11:52:18 by vtennero          #+#    #+#             */
/*   Updated: 2017/12/14 19:04:29 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int		a;
	int		b;
	wchar_t	s[4];
	char	*c;

	s[0] = 0x53;
	s[1] = 0x3abc;
	s[2] = 0x81000;
	s[3] = '\0';
	setlocale(LC_ALL, "en_US.UTF-8");
	// ft_putnbr(MB_CUR_MAX);
	// ft_putendl("my printf :");
	a = ft_printf(TEXT);
	ft_putchar(10);
	// ft_putendl("standard printf :");
	// b = printf(TEXT);
	// ft_printf("my printf returns : %d\n", a);
	// ft_printf("standard printf returns : %d\n", b);

	// while (1)
	// ;
	return (0);
}