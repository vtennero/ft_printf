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

// NSFW

#define TEXT "%x\n", -30


//#define TEXT "%5p\n", &i

//#define TEXT "@moulitest: %#.o %#.0o", 0, 0

//#define TEXT "%S", L"米"
//#define TEXT "%.4S", L"我是一只猫。" //undefined behavior

//#define TEXT "%lu", 4294967296
//#define TEXT "%lu", -42
//#define TEXT "%llu", 4999999999
//#define TEXT "%ju", 4999999999
//#define TEXT "%ju", 4294967296
//#define TEXT "%hU", 4294967296

//o

//#define TEXT "%#6o", 2500
//#define TEXT "%-#6o", 2500
//#define TEXT "@moulitest: %.o %.0o", 0, 0
//#define TEXT "%o\n", 8
//#define TEXT "%-5.10o", 2500
//#define TEXT "%-10.5o", 2500
//define TEXT "%.#o", 0
//#define TEXT "@moulitest: %5.o %5.0o", 0, 0
//#define TEXT "@moulitest: %.10o", 42

//c

//#define TEXT "%+c", 0
//#define TEXT "%c", 0
//#define TEXT "% c", 0
//#define TEXT "%5c", 42
//#define TEXT "%-5c", 42
//#define TEXT "%2c", 0

//#define TEXT "% c", 'a'
//#define TEXT "% c", 0
//#define TEXT "@moulitest: %c", 0
//#define TEXT "@moulitest: %c", 45

//u

//#define TEXT "%u", -4294967296
//#define TEXT "%u", -4294967297
//#define TEXT "%u", 9223372036854775807
//#define TEXT "%u", 4294967296
//#define TEXT "%u", -4294967299

//d

//#define TEXT "{% 03d}", 0
//#define TEXT "%lllhd", 92233
//#define TEXT "%.d %.0d", 0, 0
//#define TEXT "%.d", 0, 0
//#define TEXT "%.d", 0
//#define TEXT "@moulitest: %5.d %5.0d", 0, 0
//#define TEXT "@moulitest: %.d %.0d", 0, 0
//#define TEXT "@moulitest: %.d", 0
//#define TEXT "@moulitest: %.d %.0d", 42, 43

//# define TEXT "%d %U", 6, 5
//# define TEXT "%5.5 0 d", 450
//# define TEXT "%.-60d", 44
//# define TEXT "Bonjour %10.4d, ca va ? %054-d", -44, 52
//# define TEXT "Bonjour %10.4d, ca va ? %054d", -44, 52
//#define TEXT "%d", -2147483648
//#define TEXT "%d", -2147483648
//#define TEXT "%0+5d", 42
//#define TEXT "%05d", 42
//#define TEXT "%0+5d", -42
//#define TEXT "%05d", -42
//#define TEXT "% 5d", -42
//#define TEXT "%4.15d", 42 
//#define TEXT "%03.2d", 0
//#define TEXT "%03d", 1
//#define TEXT "%03.2d", 1
//#define TEXT "% d", 42
//#define TEXT "% 10.5d", 4242


//#define TEXT "%lld", 9223372036854775807
//#define TEXT "%lld", -9223372036854775808
//#define TEXT "%jd", 9223372036854775807
//#define TEXT "%jd", -9223372036854775808

//ld lld ...

//#define TEXT "%ld", -2147483648
//#define TEXT "%ld", 2147483648
//#define TEXT "%ld", -2147483649
//#define TEXT "%zd", 4294967295
//#define TEXT "%zd", 4294967296

//s

//# define TEXT "%#+0- 10.5s", NULL
//# define TEXT "//buffer[1]//%50.5 -0s//buffer[2]//%s%.4s %5.4d", "anticonstitutionnel", "toto", "titi", 350
//# define TEXT "%50.5 0s", "anticonstitutionnel"
//# define TEXT "%010.5s", "anticonstitutionnel"
//# define TEXT "//buffer[1]//%50.5 -0s//buffer[2]//", "anticonstitutionnel"

//other

//#define TEXT ""
//#define TEXT "%5%"
//#define TEXT "%%%%%%%%%trtftft%%%%"
//#define TEXT "toto%%basdsadas"
//#define TEXT "totos", "titi"
//#define TEXT "toto%%b%s", "titi"
//#define TEXT "toto%%b/%10-.4s"
//#define TEXT "%"
//#define TEXT "% Zoooo"

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

int			ft_printf(const char *format, ...);

//PARAMETERS CREATION

void		ft_set_g_formats(void);
t_params	*ft_create_params(void);
t_params	*ft_set_zero_params(t_params *arg);

//PARAMETERS SETTINGS

int		ft_set_flags(t_params *arg, char *str, int *index);
int		ft_set_length(t_params *arg, char *str, int *index);
int		ft_set_width(t_params *arg, char *str, int *index);
int		ft_set_prec(t_params *arg, char *str, int *index);
int		ft_set_spec(t_params *arg, char *str, int *index, va_list arguments, char **buf);

//PARAMETERS OVERRIDE

t_params	*ft_general_overrides(t_params *arg);
void		ft_override_params_d(t_params *arg, long long nb);
void		ft_override_length(t_params *arg);

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

//CAST / VA_ARGS

//long long	ft_prop_cast(t_params *arg, va_list lst, char c);

long long	ft_prop_cast_d(t_params *arg, va_list lst);
char		*ft_prop_cast_u(t_params *arg, va_list lst);
void		*ft_prop_cast_s(t_params *arg, va_list lst);
int			ft_prop_cast_c(t_params *arg, va_list lst);
void	*ft_prop_cast_p(t_params *arg, va_list lst);

//PRINT

int			ft_write(char *str);

//UTILITIES

void		ft_print_params(t_params *arg);
char		*ft_append(char *buf, int n, char c);
char		*ft_prepend(char *buf, int n, char c);
t_bool		ft_is_char(char c1, char c2);

//OTHER

char		*ft_is_s_left(int malloc_size, int n, char *str, char c);
char		*ft_is_s_right(int malloc_size, int n, char *str, char c);

#endif
