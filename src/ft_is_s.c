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

	i = 0;
	new = NULL;
	while (i < len - 1)
	{
		new = ft_strjoin_clr(new, ft_is_unicode_c(arg, (int)wstr[i]), 2);
		i++;
	}
	// ft_putendl(new);
	return (new);
}

static char		*ft_is_unicode_s(t_params *arg, va_list lst)
{
	wchar_t		*wstr;
	char		*str;
	int			malloc_size;
	int			width;
	int			n;

	str = NULL;
	if ((wstr = ft_prop_cast_s(arg, lst)) == NULL)
		return (str = ft_strdup("(null"));

	// printf("wcharlen = %d\n", ft_wcharlen(wstr[3]));
	// printf("wstrlen = %d\n", ft_wstrlen(wstr));
	width = arg->width;
	n = 0;
	malloc_size = ft_prec_s(0, ft_wstrlen(wstr), arg);
	malloc_size = ft_width_s(malloc_size, &n, arg);
	// printf("malloc_size = %d\n", malloc_size);
	//if (arg->flags[MINUS])
		return (ft_unicode_converter(arg, wstr, ft_wstrlen(wstr)));
	//else
	//	return (ft_is_s_left(malloc_size, n, wstr, ft_set_zero(arg)));

	printf("%S\n", wstr);
	printf("wstr[0] = %c\n", wstr[0]);
	printf("wstr[1] = %c\n", wstr[1]);
	printf("wstr[2] = %c\n", wstr[2]);
	printf("wstr[3] = %c\n", wstr[3]);
	printf("wstr[4] = %c\n", wstr[4]);
	printf("wstr[5] = %c\n", wstr[5]);
	printf("wstr[6] = %c\n", wstr[6]);
	printf("wstr[7] = %c\n", wstr[7]);
	printf("wstr[8] = %c\n", wstr[8]);
	printf("wstr[9] = %c\n", wstr[9]);
	printf("wstr[10] = %c\n", wstr[10]);
	printf("wstr[11] = %c\n", wstr[11]);
	printf("wstr[12] = %c\n", wstr[12]);
	printf("wstr[13] = %c\n", wstr[13]);

	return (0);
}

char			*ft_is_s(t_params *arg, va_list lst)
{
	if (arg->flags[L])
		return (ft_is_unicode_s(arg, lst));
	else
		return (ft_is_normal_s(arg, lst));
}
