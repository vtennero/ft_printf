/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_s_perc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 13:47:25 by vtennero          #+#    #+#             */
/*   Updated: 2018/01/25 14:13:13 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		ft_set_zero(t_params *arg)
{
	if (arg->flags[ZERO])
		return ('0');
	return (' ');
}

static int		ft_prec_s(int malloc_size, int str_length, t_params *arg)
{
	if (arg->prec > str_length)
		malloc_size = str_length;
	else if (arg->flags[PREC] == 0)
		malloc_size = str_length;
	else
		malloc_size = arg->prec;
	return (malloc_size);
}

static int		ft_width_s(int malloc_size, int *n, t_params *arg)
{
	if (arg->width > malloc_size)
	{
		*n = arg->width - malloc_size;
		malloc_size = arg->width;
	}
	return (malloc_size);
}

char			*ft_is_s_perc(t_params *arg, char *format)
{
	int			malloc_size;
	int			width;
	int			n;
	char		*str;

	arg->flags[PREC] = 0;
	str = ft_strndup(format, 1);
	if (str == NULL)
		str = ft_strdup("(null)");
	width = arg->width;
	n = 0;
	malloc_size = ft_prec_s(0, ft_strlen(str), arg);
	malloc_size = ft_width_s(malloc_size, &n, arg);
	if (arg->flags[MINUS])
		return (ft_is_s_perc_right(malloc_size, malloc_size - n, str, ft_set_zero(arg)));
	else
		return (ft_is_s_perc_left(malloc_size, n, str, ft_set_zero(arg)));
}
