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
#include <wchar.h>
#include <limits.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//#define TEXT "%o\\n", 40

#define TEXT "{%05.s}", 0

//#define TEXT "%s\\n", NULL

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
	t_bool		flags[PREC + 1];
}				t_params;

typedef struct s_struct
{
	char		*(*printfunc)(t_params *arg, va_list lst);
}				t_struct;

int			ft_printf(const char *format, ...);

//PARAMETERS CREATION

void		ft_set_g_formats(void);
int			ft_read_format(char *format, va_list lst);
t_params	*ft_create_params(void);
t_params	*ft_set_zero_params(t_params *arg);

//PARAMETERS SETTINGS

int		ft_set_flags(t_params *arg, char *str, int *index);
int		ft_set_length(t_params *arg, char *str, int *index);
int		ft_set_width(t_params *arg, char *str, int *index);
int		ft_set_prec(t_params *arg, char *str, int *index);

//PARAMETERS OVERRIDE

t_params	*ft_general_overrides(t_params *arg);
void		ft_override_params_d(t_params *arg, long long nb);
void		ft_override_length(t_params *arg);
void		ft_is_z(t_params *arg);
void		ft_is_j(t_params *arg);
void		ft_is_ll(t_params *arg);
void		ft_is_l(t_params *arg);
void		ft_is_h(t_params *arg);

//SPECIFIERS

char		*ft_is_s(t_params *arg, va_list lst);
char		*ft_is_cap_s(t_params *arg, va_list lst);
char		*ft_is_p(t_params *arg, va_list lst);
char		*ft_is_d(t_params *arg, va_list lst);
char		*ft_is_cap_d(t_params *arg, va_list lst);
char		*ft_is_i(t_params *arg, va_list lst);
char		*ft_is_o(t_params *arg, va_list lst);
char		*ft_is_cap_o(t_params *arg, va_list lst);
char		*ft_is_u(t_params *arg, va_list lst);
char		*ft_is_cap_u(t_params *arg, va_list lst);
char		*ft_is_x(t_params *arg, va_list lst);
char		*ft_is_cap_x(t_params *arg, va_list lst);
char		*ft_is_c(t_params *arg, va_list lst);
char		*ft_is_cap_c(t_params *arg, va_list lst);
char		*ft_is_s_perc(t_params *arg, char *format);

//CAST

long long	ft_prop_cast_signed(t_params *arg, va_list lst);
unsigned long long ft_prop_cast_unsigned(t_params *arg, va_list lst);
void		*ft_prop_cast_s(t_params *arg, va_list lst);
int			ft_prop_cast_c(t_params *arg, va_list lst);

//PRINT

int			ft_print_buffer(char *str);
void		ft_print_params(t_params *arg);

//STRING MANIPULATION

char		*ft_is_s_left(int malloc_size, int n, char *str, char c);
char		*ft_is_s_right(int malloc_size, int n, char *str, char c);
char		*ft_is_s_perc_left(int malloc_size, int n, char *str, char c);
char		*ft_is_s_perc_right(int malloc_size, int n, char *str, char c);
char		*ft_append(char *buf, int n, char c);
char		*ft_prepend(char *buf, int n, char c);

#endif
