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

static char	*ft_malloc_width(t_params *arg)
{
	char	*str;
	int		i;
	char	c;

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

static char *ft_get_wchar(wchar_t wc, char wca[4], t_params *arg)
{
	if (ft_wcharlen(wc) == 1)
	{
		wca[0] = (char)wc;
		return (ft_strdup(wca));
	}
	else if (ft_wcharlen(wc) == 2)
	{
		wca[0] = (char)((wc >> 6) | 0xc0);
		wca[1] = (char)((wc & 0x3f) | 0x80);
		return (ft_strdup(wca));
	}
	else if (ft_wcharlen(wc) == 3)
	{
		wca[0] = (char)((wc >> 12) | 0xe0);
		wca[1] = (char)(((wc >> 6) & 0x3f) | 0x80);
		wca[2] = (char)((wc & 0x3f) | 0x80);
		return (ft_strdup(wca));
	}
	else if (ft_wcharlen(wc) == 4)
	{
		wca[0] = (char)((wc >> 18) | 0xf0);
		wca[1] = (char)(((wc >> 12) & 0x3f) | 0x80);
		wca[2] = (char)(((wc >> 6) & 0x3f) | 0x80);
		wca[3] = (char)((wc & 0x3f) | 0x80);
		return (ft_strdup(wca));
	}
	arg->flags[ERR] = 1;
	// ft_printf("ft_get_wchar: arg->flags[ERR] = %d\n", arg->flags[ERR]);
	return (NULL);
}

static char *ft_get_wchar_prec(wchar_t wc, char wca[4], t_params *arg)
{
	// ft_printf("charlen = %d\n", ft_wcharlen(wc));
	// ft_printf("ft_get_wchar prec%x\n", wc);
	if (ft_wcharlen(wc) == 1)
	{
		arg->prec -= 1;
		wca[0] = (char)wc;
		return ((arg->prec >= 0) ? ft_strdup(wca) : NULL);
	}
	else if (ft_wcharlen(wc) == 2)
	{
		arg->prec -= 2;
		wca[0] = (char)((wc >> 6) | 0xc0);
		wca[1] = (char)((wc & 0x3f) | 0x80);
		return ((arg->prec >= 0) ? ft_strdup(wca) : NULL);
	}
	else if (ft_wcharlen(wc) == 3)
	{
		arg->prec -= 3;
		wca[0] = (char)((wc >> 12) | 0xe0);
		wca[1] = (char)(((wc >> 6) & 0x3f) | 0x80);
		wca[2] = (char)((wc & 0x3f) | 0x80);
		return ((arg->prec >= 0) ? ft_strdup(wca) : NULL);
	}
	else if (ft_wcharlen(wc) == 4)
	{
		arg->prec -= 4;
		wca[0] = (char)((wc >> 18) | 0xf0);
		wca[1] = (char)(((wc >> 12) & 0x3f) | 0x80);
		wca[2] = (char)(((wc >> 6) & 0x3f) | 0x80);
		wca[3] = (char)((wc & 0x3f) | 0x80);
		return ((arg->prec >= 0) ? ft_strdup(wca) : NULL);
	}
	arg->flags[ERR] = 1;
	// ft_printf("ft_get_wchar: arg->flags[ERR] = %d\n", arg->flags[ERR]);
	return (NULL);
}

char		*ft_is_unicode_c(t_params *arg, int var)
{
	char		wca[4];
	wchar_t		wc;

	wc = (wchar_t)var;
	wca[0] = 0;
	wca[1] = 0;
	wca[2] = 0;
	wca[3] = 0;
	if (arg->flags[PREC])
		return(ft_get_wchar_prec(wc, wca, arg));
	else
		return(ft_get_wchar(wc, wca, arg));
}

char		*ft_is_c(t_params *arg, va_list lst)
{
	int		var;

	var = ft_prop_cast_c(arg, lst);
	if (var <= 255)
		return (ft_is_normal_c (arg, var));
	return (ft_is_unicode_c(arg, var));
}