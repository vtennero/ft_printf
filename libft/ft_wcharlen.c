/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 16:41:27 by vtennero          #+#    #+#             */
/*   Updated: 2018/01/25 17:07:26 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wcharlen(wchar_t c)
{
	if (c >= 0 && c < 0x7f)
		return(1);
	else if (c < 0x7ff)
		return (2);
	else if (c < 0xffff)
		return (3);
	else if (c < 0x10ffff)
		return (4);
	return (0);
}
