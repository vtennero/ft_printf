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

char	*ft_is_x(t_params *arg, va_list lst)
{
	long long	number;
	char		*s1;

	number = ft_prop_cast_d(arg, lst);
	if (number >= 0)
		s1 = ft_itoa_base(number, "0123456789abcdef");
	else
	{
		s1 = ft_itoa_base(-number -1, "fedcba9876543210");
		s1 = ft_prepend(s1, 8 - ft_strlen(s1), 'f');
	}
	return (s1);
}