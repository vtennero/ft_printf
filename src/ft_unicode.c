/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 15:26:32 by vtennero          #+#    #+#             */
/*   Updated: 2018/01/30 15:26:45 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char 	*ft_get_wchar(wchar_t wc, char wca[MB_CUR_MAX], t_params *arg)
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
	return (NULL);
}

static char 	*ft_get_wchar_prec(wchar_t wc, char wca[MB_CUR_MAX], t_params *arg)
{
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
	return (NULL);
}

char			*ft_is_unicode_c(t_params *arg, int var)
{
	char		wca[MB_CUR_MAX];
	wchar_t		wc;
	char		*str;

	wc = (wchar_t)var;
	ft_bzero(wca, MB_CUR_MAX);
	if (var < 0 || (var >= 0xd800 && var < 0xe000) || var > 0x10ffff)
	{
		arg->flags[ERR]	= 1;
		return (NULL);
}
	if (arg->flags[PREC])
		str = ft_get_wchar_prec(wc, wca, arg);
	else
		str = ft_get_wchar(wc, wca, arg);
	if (arg->flags[ERR])
		str = NULL;
		return (str);
}