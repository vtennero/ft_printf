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

	s[0] = 0x53;
	s[1] = 0x3abc;
	s[2] = 0x81000;
	s[3] = '\0';
		// setlocale(LC_ALL, "");
		// ft_putnbr(MB_CUR_MAX);
		ft_putendl("my printf :");
		a = ft_printf(TEXT);
		ft_putchar(10);
		ft_putendl("standard printf :");
		b = printf(TEXT);
		ft_printf("my printf returns : %d\n", a);
		ft_printf("standard printf returns : %d\n", b);


		/*ft_putstr("my number of printed characters\n");
		ft_putnbr(ft_printf(TEXT));
		ft_putchar(10);
		ft_putstr("standard printf :\n");
		ft_putnbr(printf(TEXT));
		ft_putchar(10);*/
	//while (1)
	//	;
	return (0);
}

/*
int		main(int ac, char **av)
{
	
	if (ac == 2)
		;
	ft_set_g_formats();
	ft_read_string(av[1]);
	printf("#-ll");
	//ft_putnbr(printf(""));
	//ft_putchar(10);
	//printf("%Z546", 6);
	//printf("string = \n");
	//ft_putnbr(printf("string = \n"));
	//printf("string = 漢字\n");
	//ft_putnbr(printf("string = 漢字\n"));
	//ft_putchar(10);
	//ft_putendl("string = 漢字");
	//ft_putchar('漢');
	return (0);
}
*/