/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 22:19:43 by vtennero          #+#    #+#             */
/*   Updated: 2018/01/02 22:19:44 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_is_p(t_params *arg, va_list lst)
{
	char	*str;

	str = (char *)ft_prop_cast_p(arg, lst);
	ft_putendl(str);
	return (str);
}