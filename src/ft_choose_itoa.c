/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 17:13:39 by vtennero          #+#    #+#             */
/*   Updated: 2018/01/16 17:24:36 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_choose_itoa_o(t_params *arg, va_list lst, long long number)
{
	if (number < 0 && arg->flags[H])
		return (ft_llutoa_base(65536 + number, "01234567"));
	else if (number < 0 && arg->flags[HH])
		return (ft_llutoa_base(256 + number, "01234567"));
	//else if (number < 0)
	//	return (ft_llutoa_base(44294967295 + number, "01234567"));
	else
		return (ft_llutoa_base(number, "01234567"));
}
