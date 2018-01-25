/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 14:59:35 by vtennero          #+#    #+#             */
/*   Updated: 2017/12/30 15:15:11 by vtennero         ###   ########.fr       */
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
		str = ft_strdup("(null)"); //leak
	//printf("ft_is_s_perc malloc pointer addr : %p\n", str);
	width = arg->width;
	n = 0;
	malloc_size = ft_prec_s(0, ft_strlen(str), arg);
	malloc_size = ft_width_s(malloc_size, &n, arg);
	if (arg->flags[MINUS])
		return (ft_is_s_right(malloc_size, n, str, ft_set_zero(arg)));
	else
		return (ft_is_s_left(malloc_size, n, str, ft_set_zero(arg)));
}

char			*ft_is_s(t_params *arg, va_list lst)
{
	int			malloc_size;
	int			width;
	int			n;
	char		*str;

	str = ft_prop_cast_s(arg, lst);
	if (str == NULL)
		str = ft_strdup("(null)"); //leak
	//printf("ft_is_s malloc pointer addr : %p\n", str);
	width = arg->width;
	n = 0;
	malloc_size = ft_prec_s(0, ft_strlen(str), arg);
	malloc_size = ft_width_s(malloc_size, &n, arg);
	if (arg->flags[MINUS])
		return (ft_is_s_right(malloc_size, n, str, ft_set_zero(arg)));
	else
		return (ft_is_s_left(malloc_size, n, str, ft_set_zero(arg)));
}
