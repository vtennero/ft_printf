/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 13:46:36 by vtennero          #+#    #+#             */
/*   Updated: 2017/12/14 12:55:43 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <stdarg.h>

typedef int t_bool;

enum
{
	HASH, PLUS, MINUS, SPACE, ZERO, H, L, J, Z, HH, LL
};

enum
{
	STR, L_STR, PTR_A, DEC, L_S_DEC, INTGR, U_OCT, L_U_OCT, U_DEC, L_U_DEC, 
	U_HEXA, L_U_HEXA, CHR, L_CHR
};

typedef struct	s_params
{
	int			width;
	int			prec;
	t_bool		spec[L_CHR + 1];
	t_bool		flags[LL + 1];
}				t_params;

int	ft_printf(const char *format, ...);

#endif
