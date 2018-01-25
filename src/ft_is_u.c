/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 15:52:33 by vtennero          #+#    #+#             */
/*   Updated: 2018/01/25 14:14:26 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char				*ft_malloc_width(int n, t_params *arg)
{
	char				*str;
	int					i;
	char				c;

	n = arg->width - arg->flags[SPACE] - arg->flags[PLUS] - n;
	c = (arg->flags[ZERO]) ? '0' : ' ';
	i = 0;
	if (n < 0)
		n = 0;
	str = (char *)malloc(n + 1);
	if (str)
	{
		while (i < n)
		{
			str[i] = c;
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}

static char				*ft_malloc_prec(char *str, t_params *arg)
{
	char				*s1;
	int					i;
	int					j;
	int					len;

	i = 0;
	j = 0;
	len = ft_strlen(str);
	if (str)
	{
		if (arg->prec == 0 && arg->flags[PREC] && str[0] == '0')
			return (NULL);
	}
	s1 = (char *)malloc(sizeof(char) * ft_max(len, arg->prec) + 1);
	if (s1)
	{
		while (i < arg->prec - len)
			s1[i++] = '0';
		while (j < len)
		{
			s1[i] = str[j];
			j++;
			i++;
		}
		s1[i] = '\0';
	}
	free(str);
	return (s1);
}

char					*ft_is_u(t_params *arg, va_list lst)
{
	unsigned long long	number;
	char				*s1;
	char				*s2;

	number = ft_prop_cast_unsigned(arg, lst);
	s1 = ft_malloc_prec(ft_llutoa(number), arg);
	s2 = ft_malloc_width(ft_strlen(s1), arg);
	if (arg->flags[MINUS])
		return (ft_strjoin_clr(s1, s2, 2));
	else
		return (ft_strjoin_clr(s2, s1, 2));
}
