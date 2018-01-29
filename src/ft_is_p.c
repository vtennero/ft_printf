/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 22:19:43 by vtennero          #+#    #+#             */
/*   Updated: 2018/01/25 14:10:25 by vtennero         ###   ########.fr       */
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
	if (str[0] == '0' && arg->prec == 0 && arg->flags[PREC])
		str = NULL;
	len = ft_strlen(str);
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

static	char			*ft_is_p_one(t_params *arg, unsigned long long number)
{
	char				*s1;
	char				*s2;
	int					lstr;

	s1 = ft_malloc_prec(ft_llutoa_base(number, "0123456789abcdef"), arg);
	s1 = ft_strjoin_clr("0x", s1, 1);
	lstr = ft_strlen(s1);
	s2 = ft_malloc_width(lstr, arg);
	if (arg->flags[MINUS])
		return (ft_strjoin_clr(s1, s2, 2));
	else
		return (ft_strjoin_clr(s2, s1, 2));
}
static	char			*ft_is_p_two(t_params *arg, unsigned long long number)
{
	char				*s1;
	char				*s2;
	int					lstr;

	s1 = ft_malloc_prec(ft_llutoa_base(number, "0123456789abcdef"), arg);
	lstr = ft_strlen(s1);
	s2 = ft_malloc_width(lstr + 2, arg);
	s2 = ft_strjoin_clr("0x", s2, 1);
	return (ft_strjoin_clr(s2, s1, 2));
}
char					*ft_is_p(t_params *arg, va_list lst)
{
	unsigned long long	number;

	arg->flags[LL] = 1;
	number = ft_prop_cast_unsigned(arg, lst);
	if (arg->flags[ZERO] && arg->width > 0 && arg->flags[MINUS] == 0)
		return(ft_is_p_two(arg, number));
	else
		return (ft_is_p_one(arg, number));
}
