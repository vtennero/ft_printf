/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 22:35:17 by vtennero          #+#    #+#             */
/*   Updated: 2018/01/02 22:35:19 by vtennero         ###   ########.fr       */
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
	return (s1);
}

char	*ft_is_x(t_params *arg, va_list lst)
{
	unsigned long long	number;
	char		*s1;
	char		*s2;
	int			hash;

	hash = 0;
	number = ft_prop_cast_unsigned(arg, lst);
	//if (number >= 0)
		s1 = ft_malloc_prec(ft_llutoa_base(number, "0123456789abcdef"), arg);
	/*else
	{
		s1 = ft_malloc_prec(ft_lltoa_base(-number -1, "fedcba9876543210"), arg);
		s1 = ft_prepend(s1, 8 - ft_strlen(s1), 'f');
		//if (number < -2147483647)
		//	s1 = ft_strjoin_clr("ffffffff", s1, 1);
	}*/
	if (arg->flags[HASH] && number != 0)
		hash = 2;
	s2 = ft_malloc_width(ft_strlen(s1) + hash, arg);
	if (arg->flags[HASH] && number != 0)
		{
			if (arg->flags[ZERO])
				s2 = ft_strjoin_clr("0x", s2, 1);				
			else
			{
				if (arg->flags[MINUS])
					s1 = ft_strjoin_clr("0x", s1, 1);
				else
					s2 = ft_strjoin_clr(s2, "0x", 0);
			}
		}
	if (arg->flags[MINUS])
		return (ft_strjoin_clr(s1, s2, 2));
	else
		return (ft_strjoin_clr(s2, s1, 2));
}

char	*ft_is_cap_x(t_params *arg, va_list lst)
{
	unsigned long long	number;
	char		*s1;
	char		*s2;
	int			hash;

	hash = 0;
	number = ft_prop_cast_unsigned(arg, lst);
	if (number >= 0)
		s1 = ft_malloc_prec(ft_llutoa_base(number, "0123456789ABCDEF"), arg);
	else
	{
		s1 = ft_malloc_prec(ft_lltoa_base(-number -1, "FEDCBA9876543210"), arg);
		s1 = ft_prepend(s1, 8 - ft_strlen(s1), 'F');
		//if (number < -2147483647)
		//	s1 = ft_strjoin_clr("FFFFFFF", s1, 1);
	}
	if (arg->flags[HASH] && number != 0)
		hash = 2;
	s2 = ft_malloc_width(ft_strlen(s1) + hash, arg);
	if (arg->flags[HASH] && number != 0)
		{
			if (arg->flags[ZERO])
				s2 = ft_strjoin_clr("0X", s2, 1);				
			else
			{
				if (arg->flags[MINUS])
					s1 = ft_strjoin_clr("0X", s1, 1);
				else
					s2 = ft_strjoin_clr(s2, "0X", 0);
			}
		}
	if (arg->flags[MINUS])
		return (ft_strjoin_clr(s1, s2, 2));
	else
		return (ft_strjoin_clr(s2, s1, 2));
}
/*
char	*ft_is_cap_x(t_params *arg, va_list lst)
{
	long long	number;
	char		*s1;
	char		*s2;
	int			hash;

	hash = 0;
	number = ft_prop_cast_d(arg, lst);
	if (number >= 0)
	{
		s1 = ft_llutoa_base(number, "0123456789ABCDEF");
		if (arg->prec == 0 && arg->flags[PREC] && s1[0] == '0')
			s1 = NULL;
	}
	else
	{
		s1 = ft_lltoa_base(-number -1, "FEDCBA9876543210");
		s1 = ft_prepend(s1, 8 - ft_strlen(s1), 'F');
		if (number < -2147483647)
			s1 = ft_strjoin_clr("FFFFFFFF", s1, 1);
	}
	if (arg->flags[HASH] && number != 0)
		hash = 2;
	s2 = ft_malloc_width(ft_strlen(s1) + hash, arg);
	if (arg->flags[HASH] && number != 0)
		{
			if (arg->flags[ZERO])
				s2 = ft_strjoin_clr("0X", s2, 1);				
			else
			{
				if (arg->flags[MINUS])
					s1 = ft_strjoin_clr("0X", s1, 1);
				else
					s2 = ft_strjoin_clr(s2, "0X", 0);
			}
		}
	if (arg->flags[MINUS])
		return (ft_strjoin_clr(s1, s2, 2));
	else
		return (ft_strjoin_clr(s2, s1, 2));
}*/