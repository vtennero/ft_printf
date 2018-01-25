/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_buffer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 10:37:46 by vtennero          #+#    #+#             */
/*   Updated: 2018/01/25 10:37:49 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_check_if_null(char *str, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		if (str[i] == -8)
			str[i] = 0;
		i++;
	}
}

int	ft_print_buffer(char *str)
{
	int	n;

	n = ft_strlen(str);
	ft_check_if_null(str, n);
	write(1, str, n);
	free(str);
	return (n);
}
