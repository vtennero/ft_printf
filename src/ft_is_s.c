/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 14:59:35 by vtennero          #+#    #+#             */
/*   Updated: 2018/01/25 14:11:36 by vtennero         ###   ########.fr       */
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
	// ft_printf("arg->prec = %d str_length = %d\n", arg->prec, str_length);

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

static char		*ft_is_normal_s(t_params *arg, va_list lst)
{
	int			malloc_size;
	int			width;
	int			n;
	char		*str;

	str = ft_prop_cast_s(arg, lst);
	if (str == NULL && arg->width == 0)
		return(str = ft_strdup("(null)"));
	width = arg->width;
	n = 0;
	malloc_size = ft_prec_s(0, ft_strlen(str), arg);
	malloc_size = ft_width_s(malloc_size, &n, arg);
	if (arg->flags[MINUS])
		return (ft_is_s_right(malloc_size, n, str, ft_set_zero(arg)));
	else
		return (ft_is_s_left(malloc_size, n, str, ft_set_zero(arg)));
}

char			*ft_unicode_converter(t_params *arg, wchar_t *wstr, int len)
{
	char		*new;
	int			i;
	int			j;
	int			malloc_size;
	int			n;
	int			width;
	int			tmp;
	int			tmp2;

	i = 0;
	j = 0;
	n = 0;
	new = NULL;
	if (arg->flags[PREC])
		tmp2 = arg->prec;
	// tmp = (arg->prec) ? arg->prec : len;
	// ft_printf("len = %d\n", len);
	// ft_printf("tmp = %d\n", tmp);
	// printf("new addr : %p\n", &new);
	while (i < len + 1 && tmp >= 1)
	{
		// ft_printf("i = %d\n",i);
		if (arg->flags[ERR] == 1)
			{
				free (new);
		 		printf("new addr : %p\n", &new);
				return (NULL);
			}
		else
		{
		new = ft_strjoin_clr(new, ft_is_unicode_c(arg, (int)wstr[j]), 2);
		// ft_putchar(ft_is_unicode_c(arg, (int)wstr[j]));
		// ft_putendl("");
		// if (arg->prec)
			// tmp -= ft_wcharlen(wstr[j]);
		i += ft_wcharlen(wstr[j]);
		j++;
	}
	}
	// ft_putendl(new);
	// ft_printf("tmp = %d\n", tmp);
	// if (arg->prec)
		// arg->prec = arg->prec - tmp;
	arg->prec = tmp2;
	malloc_size = ft_prec_s(0, ft_strlen(new), arg);
	// ft_printf("malloc_size = %d\n", malloc_size);
	malloc_size = ft_width_s(malloc_size, &n, arg);
	if (arg->flags[MINUS])
		return (ft_is_s_perc_right(malloc_size, n, new, ft_set_zero(arg)));
	else
		return (ft_is_s_perc_left(malloc_size, n, new, ft_set_zero(arg)));
}

static char		*ft_is_unicode_s(t_params *arg, va_list lst)
{
	wchar_t		*wstr;
	char		*str;
	// int			malloc_size;
	// int			width;
	// int			n;


	str = NULL;
	// printf("str addr : %p\n", &str);
	if ((wstr = ft_prop_cast_s(arg, lst)) == NULL)
		return (str = ft_strdup("(null)"));

	// printf("wcharlen = %d\n", ft_wcharlen(wstr[3]));
	// printf("wstrlen = %d\n", ft_wstrlen(wstr));
	// width = arg->width;
	// n = 0;
	// malloc_size = ft_prec_s(0, ft_wstrlen(wstr), arg);
	// malloc_size = ft_width_s(malloc_size, &n, arg);
	// printf("malloc_size = %d\n", malloc_size);
	//if (arg->flags[MINUS])
	return (ft_unicode_converter(arg, wstr, ft_wstrlen(wstr)));
}

char			*ft_is_s(t_params *arg, va_list lst)
{
	if (arg->flags[L])
		return (ft_is_unicode_s(arg, lst));
	else
		return (ft_is_normal_s(arg, lst));
}
