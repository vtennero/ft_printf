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
/*
void	ft_is_s(t_params *arg)
{
	printf("s\n");
}
*/
char	*ft_is_cap_s(t_params *arg, va_list arguments)
{
	printf("S\n");
	return (0);
}

char	*ft_is_p(t_params *arg, va_list arguments)
{
	printf("p\n");
	return (0);
}
/*
char	*ft_is_d(t_params *arg, va_list arguments)
{
	printf("d\n");
	return (0);
}
*/
char	*ft_is_cap_d(t_params *arg, va_list arguments)
{
	printf("D\n");
	return (0);
}

char	*ft_is_i(t_params *arg, va_list arguments)
{
	printf("i\n");
	return (0);
}

char	*ft_is_o(t_params *arg, va_list arguments)
{
	printf("o\n");
	return (0);
}

char	*ft_is_cap_o(t_params *arg, va_list arguments)
{
	printf("O\n");
	return (0);
}

char	*ft_is_u(t_params *arg, va_list arguments)
{
	printf("u\n");
	return (0);
}

char	*ft_is_cap_u(t_params *arg, va_list arguments)
{
	printf("U\n");
	return (0);
}

char	*ft_is_x(t_params *arg, va_list arguments)
{
	printf("x\n");
	return (0);
}

char	*ft_is_cap_x(t_params *arg, va_list arguments)
{
	printf("X\n");
	return (0);
}

char	*ft_is_c(t_params *arg, va_list arguments)
{
	printf("c\n");
	return (0);
}

char	*ft_is_cap_c(t_params *arg, va_list arguments)
{
	printf("C\n");
	return (0);
}
