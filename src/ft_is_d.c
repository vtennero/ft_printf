/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 14:26:59 by vtennero          #+#    #+#             */
/*   Updated: 2017/12/30 14:28:11 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_malloc_width(int n, t_params *arg)
{
	char	*str;
	int		i;
	char	c;

	n = arg->width - arg->flags[SPACE] - arg->flags[PLUS] - n;
	c = (arg->flags[ZERO]) ? '0' : ' ';
	i = 0;
	if (n < 0)
		n = 0;
	str = (char *)malloc(n + 1);
	//printf("ft_is_d malloc width s2 pointer addr : %p\n", str);
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

static char	*ft_malloc_prec(char *str, t_params *arg)
{
	char	*s1;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = ft_strlen(str);
	if (str)
	{
		if (arg->prec == 0 && arg->flags[PREC] && str[0] == '0')
			return (NULL);
	}
	s1 = (char *)malloc(sizeof(char) * ft_max(len, arg->prec) + 1);
	//printf("ft_is_d lltoabase pointer addr : %p\n", str);
	//printf("ft_is_d malloc prec pointer addr : %p\n", s1);
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

char	*ft_is_d(t_params *arg, va_list lst)
{
	long long	number;
	char		*s1;
	char		*s2;
	int			lstr;

	number = ft_prop_cast_signed(arg, lst);
	ft_override_params_d(arg, number);
	if (number >= 0)
	{
		s1 = ft_malloc_prec(ft_lltoa_base((long long)number, "0123456789"), arg);
		lstr = ft_strlen(s1);
	}
	else
	{
		s1 = ft_malloc_prec(ft_lltoa_base((long long)(-number), "0123456789"), arg);
		lstr = ft_strlen(s1) + 1;
	}
	s2 = ft_malloc_width(lstr, arg);
	if (number < 0)
	{
		if (arg->flags[ZERO])
			s2 = ft_prepend(s2, 1, '-');
		else if (number < -9223372036854775807)
			;
		else
			s1 = ft_prepend(s1, 1, '-');
	}
	else if (number >= 0)
	{
		if (arg->flags[PLUS] && arg->flags[ZERO])
			s2 = ft_prepend(s2, 1, '+');
		else if (arg->flags[PLUS] && !arg->flags[ZERO])
			s1 = ft_prepend(s1, 1, '+');
		else if (arg->flags[SPACE] && arg->flags[ZERO])
			s2 = ft_prepend(s2, 1, ' ');
		else if (arg->flags[SPACE] && !arg->flags[ZERO])
			s1 = ft_prepend(s1, 1, ' ');
	}
	if (arg->flags[MINUS])
		return (ft_strjoin_clr(s1, s2, 2));
	else
		return (ft_strjoin_clr(s2, s1, 2));
}