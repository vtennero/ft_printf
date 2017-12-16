/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 13:46:36 by vtennero          #+#    #+#             */
/*   Updated: 2017/12/14 19:01:51 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <stdarg.h>

# define TEXT "//buffer[1]//%50.5 -0s//buffer[2]//", "anticonstitutionnel"
//# define TEXT "//buffer[1]//%50.5 -0s//buffer[2]//%s", "anticonstitutionnel", "toto"

//# define TEXT "%50.5 0s", "anticonstitutionnel"
//# define TEXT "%010.5s", "anticonstitutionnel"

typedef int t_bool;

enum
{
	HASH, PLUS, MINUS, SPACE, ZERO, H, L, J, Z, HH, LL, PREC
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
	//t_bool		spec[L_CHR + 1];
	t_bool		flags[PREC + 1];
}				t_params;

typedef struct s_struct
{
	char		*(*printfunc)(t_params *arg, char *str);
}				t_struct;

int	ft_printf(const char *format, ...);

//SPECIFIERS

char	*ft_is_s(t_params *arg, char *str);

char	*ft_is_cap_s(t_params *arg, char *str);
char	*ft_is_p(t_params *arg, char *str);
char	*ft_is_d(t_params *arg, char *str);
char	*ft_is_cap_d(t_params *arg, char *str);
char	*ft_is_i(t_params *arg, char *str);
char	*ft_is_o(t_params *arg, char *str);
char	*ft_is_cap_o(t_params *arg, char *str);
char	*ft_is_u(t_params *arg, char *str);
char	*ft_is_cap_u(t_params *arg, char *str);
char	*ft_is_x(t_params *arg, char *str);
char	*ft_is_cap_x(t_params *arg, char *str);
char	*ft_is_c(t_params *arg, char *str);
char	*ft_is_cap_c(t_params *arg, char *str);

//PRINT

void	ft_write(char *str);

//UTILITIES

void	ft_print_params(t_params *arg);

#endif
