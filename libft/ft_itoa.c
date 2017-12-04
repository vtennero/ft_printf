/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 15:03:54 by vtennero          #+#    #+#             */
/*   Updated: 2017/07/22 12:13:31 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_itoazero(void)
{
	char	*str;

	str = malloc(2);
	if (!str)
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

static char		*ft_itoapos(int nv, int l)
{
	char	*res;
	int		j;

	res = malloc(sizeof(char) * l + 1);
	if (!res)
		return (NULL);
	j = l - 1;
	while (nv > 0)
	{
		res[j] = nv % 10 + 48;
		nv /= 10;
		j--;
	}
	res[l] = '\0';
	return (res);
}

static char		*ft_itoaneg(int nv, int l)
{
	char	*res;
	int		j;
	long	p;

	p = -(long)nv;
	res = malloc(sizeof(char) * l + 1);
	if (!res)
		return (NULL);
	j = l - 1;
	res[0] = '-';
	while (p > 0)
	{
		res[j] = p % 10 + 48;
		p /= 10;
		j--;
	}
	res[l] = '\0';
	return (res);
}

static int		ft_itoalength(int n)
{
	int	p;
	int	i;

	p = n;
	i = 0;
	if (p < 0)
	{
		i++;
		p = -p;
	}
	while (p != 0)
	{
		p /= 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	int	nv;
	int	l;
	int	i;

	l = ft_itoalength(n);
	nv = 0;
	i = 0;
	i = l;
	if (n == 0)
		return (ft_itoazero());
	else if (n > 0)
		return (ft_itoapos(n, l));
	else if (n < 0)
		return (ft_itoaneg(n, l));
	return (NULL);
}
