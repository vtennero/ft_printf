/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 15:28:09 by vtennero          #+#    #+#             */
/*   Updated: 2017/12/14 15:35:10 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

char	*ft_is_cap_s(t_params *arg, va_list lst)
{
	arg->flags[L] = 1;
	return (ft_is_s(arg, lst));
}

char	*ft_is_p(t_params *arg, va_list lst)
{
	printf("p\n");
	return (0);
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

char	*ft_is_o(t_params *arg, va_list lst)
{
	printf("o\n");
	return (0);
}

char	*ft_is_cap_o(t_params *arg, va_list lst)
{
	printf("O\n");
	return (0);
}

char	*ft_is_cap_u(t_params *arg, va_list lst)
{
	arg->flags[L] = 1;
	return (ft_is_u(arg, lst));
}

char	*ft_is_x(t_params *arg, va_list lst)
{
	printf("x\n");
	return (0);
}

char	*ft_is_cap_x(t_params *arg, va_list lst)
{
	printf("X\n");
	return (0);
}

char	*ft_is_cap_c(t_params *arg, va_list lst)
{
	arg->flags[L] = 1;
	return (ft_is_c(arg, lst));
}
