/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_override_spec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 17:45:37 by vtennero          #+#    #+#             */
/*   Updated: 2017/12/30 17:52:19 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_is_z(t_params *arg)
{
	arg->flags[J] = 0;
	arg->flags[LL] = 0;
	arg->flags[L] = 0;
	arg->flags[H] = 0;
	arg->flags[HH] = 0;
}

static void	ft_is_j(t_params *arg)
{
	arg->flags[LL] = 0;
	arg->flags[L] = 0;
	arg->flags[H] = 0;
	arg->flags[HH] = 0;
}

static void	ft_is_ll(t_params *arg)
{
	arg->flags[L] = 0;
	arg->flags[H] = 0;
	arg->flags[HH] = 0;
}

static void	ft_is_l(t_params *arg)
{
	arg->flags[H] = 0;
	arg->flags[HH] = 0;
}

static void	ft_is_h(t_params *arg)
{
	arg->flags[HH] = 0;
}

void		ft_override_spec(t_params *arg)
{
	if (arg->flags[Z])
		ft_is_z(arg);
	else if (arg->flags[J])
		ft_is_j(arg);
	else if (arg->flags[LL])
		ft_is_ll(arg);
	else if (arg->flags[L])
		ft_is_l(arg);
	else if (arg->flags[H])
		ft_is_h(arg);
	else
		;
}
