/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other_specs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 10:35:44 by vtennero          #+#    #+#             */
/*   Updated: 2018/01/25 10:35:45 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_is_cap_s(t_params *arg, va_list lst)
{
	arg->flags[L] = 1;
	return (ft_is_s(arg, lst));
}

char	*ft_is_cap_d(t_params *arg, va_list lst)
{
	arg->flags[L] = 1;
	return (ft_is_d(arg, lst));
}

char	*ft_is_i(t_params *arg, va_list lst)
{
	return (ft_is_d(arg, lst));
}

char	*ft_is_cap_o(t_params *arg, va_list lst)
{
	arg->flags[L] = 1;
	return (ft_is_o(arg, lst));
}

char	*ft_is_cap_u(t_params *arg, va_list lst)
{
	arg->flags[L] = 1;
	return (ft_is_u(arg, lst));
}

char	*ft_is_cap_c(t_params *arg, va_list lst)
{
	arg->flags[L] = 1;
	return (ft_is_c(arg, lst));
}
