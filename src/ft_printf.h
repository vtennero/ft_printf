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

#include "../libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <limits.h>

#include <stdint.h>

// NSFW

#define TEXT "%5%"




//# define TEXT "%#+0- 10.5s", NULL
//#define TEXT "%%%%%%%%%trtftft%%%%"
//#define TEXT "toto%%basdsadas"
//#define TEXT "totos", "titi"
//#define TEXT "toto%%b%s", "titi"
//#define TEXT "toto%%b/%10-.4s"
//# define TEXT "//buffer[1]//%50.5 -0s//buffer[2]//%s%.4s %5.4d", "anticonstitutionnel", "toto", "titi", 350
//# define TEXT "%d %U", 6, 5
//# define TEXT "%5.5 0 d", 450
//# define TEXT "%.-60d", 44
//# define TEXT "Bonjour %10.4d, ca va ? %054-d", -44, 52
//# define TEXT "Bonjour %10.4d, ca va ? %054d", -44, 52
//# define TEXT "%50.5 0s", "anticonstitutionnel"
//# define TEXT "%010.5s", "anticonstitutionnel"
//# define TEXT "//buffer[1]//%50.5 -0s//buffer[2]//", "anticonstitutionnel"

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
	char		*(*printfunc)(t_params *arg, va_list lst);
}				t_struct;

int		ft_printf(const char *format, ...);

//SPECIFIERS

char	*ft_is_s(t_params *arg, va_list lst);

char	*ft_is_cap_s(t_params *arg, va_list lst);
char	*ft_is_p(t_params *arg, va_list lst);
char	*ft_is_d(t_params *arg, va_list lst);
char	*ft_is_cap_d(t_params *arg, va_list lst);
char	*ft_is_i(t_params *arg, va_list lst);
char	*ft_is_o(t_params *arg, va_list lst);
char	*ft_is_cap_o(t_params *arg, va_list lst);
char	*ft_is_u(t_params *arg, va_list lst);
char	*ft_is_cap_u(t_params *arg, va_list lst);
char	*ft_is_x(t_params *arg, va_list lst);
char	*ft_is_cap_x(t_params *arg, va_list lst);
char	*ft_is_c(t_params *arg, va_list lst);
char	*ft_is_cap_c(t_params *arg, va_list lst);

//CAST

long long	ft_prop_cast(t_params *arg, va_list lst, char c);

//PRINT

int		ft_write(char *str);

//UTILITIES

void	ft_print_params(t_params *arg);
char	*ft_append(char *buf, int n, char c);
t_bool		ft_is_char(char c1, char c2);

//OTHER

char		*ft_is_s_left(int malloc_size, int n, char *str, char c);
char		*ft_is_s_right(int malloc_size, int n, char *str, char c);

#endif
