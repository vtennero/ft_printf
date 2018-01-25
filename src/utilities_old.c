/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 19:03:11 by vtennero          #+#    #+#             */
/*   Updated: 2017/12/14 19:03:13 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

void			ft_print_params(t_params *arg)
{
	printf("%c : %d\n", '#', arg->flags[0]);
	printf("%c : %d\n", '+', arg->flags[1]);
	printf("%c : %d\n", '-', arg->flags[2]);
	printf("%c : %d\n", ' ', arg->flags[3]);
	printf("%c : %d\n", '0', arg->flags[4]);
	printf("%c : %d\n", 'h', arg->flags[5]);
	printf("%c : %d\n", 'l', arg->flags[6]);
	printf("%c : %d\n", 'j', arg->flags[7]);
	printf("%c : %d\n", 'z', arg->flags[8]);
	printf("%s : %d\n", "hh", arg->flags[9]);
	printf("%s : %d\n", "ll", arg->flags[10]);
	printf("%s : %d\n", "precision (flag)", arg->flags[11]);
	printf("width = %d\n", arg->width);
	printf("precision = %d\n", arg->prec);
}

char			*ft_append(char *buf, int n, char c)
{
	char		*append;
	int			i;

	i = 0;
	append = malloc(sizeof(char) * n + 1);
	//printf("ft_append malloc pointer addr : %p\n", append);
	if (append)
	{
		while (i < n)
			append[i++] = c;
	}
	append[i] = '\0';
	return (ft_strjoin_clr(buf, append, 2));
}

char			*ft_prepend(char *buf, int n, char c)
{
	char		*prepend;
	int			i;

	i = 0;
	prepend = malloc(sizeof(char) * n + 1);
	//printf("ft_prepend malloc pointer addr : %p\n", prepend);
	if (prepend)
	{
		while (i < n)
			prepend[i++] = c;
	}
	prepend[i] = '\0';
	return (ft_strjoin_clr(prepend, buf, 2));
}

t_bool			ft_is_char(char c1, char c2)
{
	if (c1 == c2)
		return (1);
	else
		return (0);
}

char			*ft_is_s_right(int malloc_size, int n, char *str, char c)
{
	int			i;
	int			j;
	char		*s;

	i = 0;
	j = 0;
	n = malloc_size - n;
	s = malloc(malloc_size + 1);
	//printf("ft_is_right malloc pointer addr : %p\n", s);
	if (s)
	{
		while (i < malloc_size)
		{
			if (n)
			{
				s[i] = str[j];
				n--;
				j++;
			}
			else
				s[i] = c;
			i++;
		}
		s[i] = '\0';
	}
	return (s);
}

char			*ft_is_s_left(int malloc_size, int n, char *str, char c)
{
	int			i;
	int			j;
	char		*s;

	i = 0;
	j = 0;
	s = malloc(malloc_size + 1);
	//printf("ft_is_left malloc pointer addr : %p\n", s);
	if (s)
	{
		while (i < malloc_size)
		{
			if (n)
			{
				s[i] = c;
				n--;
			}
			else
				s[i] = str[j++];
			i++;
		}
		s[i] = '\0';
	}
	return (s);
}
