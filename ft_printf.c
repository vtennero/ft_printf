/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 17:48:38 by vtennero          #+#    #+#             */
/*   Updated: 2017/12/14 18:39:28 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	va_list	arguments;

	va_start(arguments, format);
	//printf("%s", va_arg(arguments, char *));
	//va_arg(arguments, char *);
	//printf("%s", va_arg(arguments, char *));
	ft_read_string(format, va_arg(arguments, char *));
	va_end(arguments);
	return (0);
}
/*
int	main(int ac, char **av)
{
	if (ac)
	{
		ft_set_g_formats();
		ft_read_string(av[1], av[2]);
		//ft_printf("%s\n", "toto", "tata");
		}
	return (0);
}
*/