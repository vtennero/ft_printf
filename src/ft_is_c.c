/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 11:42:33 by vtennero          #+#    #+#             */
/*   Updated: 2017/12/31 11:42:34 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_malloc_width(t_params *arg)
{
	char		*str;
	int			i;
	char		c;

	i = 0;
	if (!arg->width)
		return (NULL);
	c = (arg->flags[ZERO]) ? '0' : ' ';
	str = (char *)malloc(arg->width - 1 + 1);
	if (str)
		while (i < arg->width - 1)
			str[i++] = c;
	return (str);
}

static char		*ft_is_normal_c(t_params *arg, int var)
{
	char	c;

	c = (char)var;
	if (arg->flags[MINUS])
	{
		if (c == 0)
			c = -8;
		return (ft_prepend(ft_malloc_width(arg), 1, c));
	}
	else
	{
		if (c == 0)
			c = -8;
		return (ft_append(ft_malloc_width(arg), 1, c));
	}
}

char		*ft_is_c(t_params *arg, va_list lst)
{
	int		var;

	var = ft_prop_cast_c(arg, lst);
	if (var <= 255)
		return (ft_is_normal_c (arg, var));
	return (ft_is_unicode_c(arg, var));
}