/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_override_params.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 14:31:04 by vtennero          #+#    #+#             */
/*   Updated: 2017/12/30 14:31:17 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_params	*ft_general_overrides(t_params *arg)
{
	if (arg->flags[PLUS] && arg->flags[SPACE])
		arg->flags[SPACE] = 0;
	if (arg->flags[MINUS] && arg->flags[ZERO])
		arg->flags[ZERO] = 0;
	ft_override_length(arg);
	//cas des signed char
	
	//if (arg->flags[PREC] && arg->flags[ZERO])
	//	arg->flags[ZERO] = 0;
	//ft_print_params(arg);
	return (arg);
}

void		ft_override_params_d(t_params *arg, long long nb)
{
	if (arg->flags[SPACE] && arg->flags[PLUS])
		arg->flags[SPACE] = 0;
	if (arg->flags[SPACE] && nb < 0)
		arg->flags[SPACE] = 0;
	if (arg->flags[PLUS] && nb < 0)
		arg->flags[PLUS] = 0;
	if (arg->flags[ZERO] && arg->flags[PREC] && arg->width)
		arg->flags[ZERO] = 0;
}