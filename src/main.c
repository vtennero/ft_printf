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

int	main(int ac, char **av)
{
	if (ac)
	{
		ft_set_g_formats();
		ft_write("my printf :\n");
		ft_printf(TEXT);
		ft_putchar(10);
		ft_write("standard printf :\n");
		printf(TEXT);
		}
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