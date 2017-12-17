/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 11:52:18 by vtennero          #+#    #+#             */
/*   Updated: 2017/12/14 19:04:29 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

static t_struct	g_formats[127];

void		ft_set_g_formats(void)
{
	g_formats['s'].printfunc = ft_is_s;
	g_formats['S'].printfunc = ft_is_cap_s;
	g_formats['p'].printfunc = ft_is_p;
	g_formats['d'].printfunc = ft_is_d;
	g_formats['D'].printfunc = ft_is_cap_d;
	g_formats['i'].printfunc = ft_is_i;
	g_formats['o'].printfunc = ft_is_o;
	g_formats['O'].printfunc = ft_is_cap_o;
	g_formats['u'].printfunc = ft_is_u;
	g_formats['U'].printfunc = ft_is_cap_u;
	g_formats['x'].printfunc = ft_is_x;
	g_formats['X'].printfunc = ft_is_cap_x;
	g_formats['c'].printfunc = ft_is_c;
	g_formats['C'].printfunc = ft_is_cap_c;
}

t_bool		ft_is_char(char c1, char c2)
{
	if (c1 == c2)
		return (1);
	else
		return (0);
}

int		ft_set_flags(t_params *arg, char *str, int *index)
{
	if (ft_is_char(str[*index], '#') == 1)
		return(arg->flags[HASH] = 1);	
	else if (ft_is_char(str[*index], '+') == 1)
		return(arg->flags[PLUS] = 1);	
	else if (ft_is_char(str[*index], '-') == 1)
		return(arg->flags[MINUS] = 1);	
	else if (ft_is_char(str[*index], ' ') == 1)
		return(arg->flags[SPACE] = 1);	
	else if (ft_is_char(str[*index], '0') == 1)
		return(arg->flags[ZERO] = 1);
	return (0);
}

int		ft_set_length(t_params *arg, char *str, int *index)
{
	if (ft_strnequ(str + *index, "hh", 2) == 1)
	{
		*index += 1;
		return (arg->flags[HH] = 1);
	}
	if (ft_strnequ(str + *index, "ll", 2) == 1)
	{
		*index += 1;
		return (arg->flags[LL] = 1);
	}	
	else if (ft_is_char(str[*index], 'h') == 1)
		return(arg->flags[H] = 1);	
	else if (ft_is_char(str[*index], 'l') == 1)
		return(arg->flags[L] = 1);	
	else if (ft_is_char(str[*index], 'j') == 1)
		return(arg->flags[J] = 1);	
	else if (ft_is_char(str[*index], 'z') == 1)
		return(arg->flags[Z] = 1);	
	return (0);
}

int		ft_set_width(t_params *arg, char *str, int *index)
{
	if (ft_isdigit((int)str[*index]) == 1)
	{
		arg->width = 0;
		while (ft_isdigit((int)str[*index]) == 1)
		{
			arg->width = 10 * arg->width + (int)str[*index] - 48;
			*index += 1;
		}
		*index -= 1;
		return (1);
	}
	return (0);
}

int		ft_set_prec(t_params *arg, char *str, int *index)
{
	if (ft_is_char(str[*index], '.') == 1)
	{
		*index += 1;
		arg->flags[PREC] = 1;
		arg->prec = 0;
		if (ft_isdigit((int)str[*index]) == 1)
		{
			arg->prec = 0;
			while (ft_isdigit((int)str[*index]) == 1)
			{
				arg->prec = 10 * arg->prec + (int)str[*index] - 48;
				*index += 1;
			}

		}
		*index -= 1;
		return (1);
	}
	return (0);
} 

t_params	*ft_set_overrides(t_params *arg)
{
	if (arg->flags[PLUS] && arg->flags[SPACE])
		arg->flags[SPACE] = 0;
	if (arg->flags[MINUS] && arg->flags[ZERO])
		arg->flags[ZERO] = 0;
	
	//cas des signed char
	
	//if (arg->flags[PREC] && arg->flags[ZERO])
	//	arg->flags[ZERO] = 0;
	//ft_print_params(arg);
	return (arg);
}

char	*ft_set_type(void)
{
	return ("char *");
}

int		ft_set_spec(t_params *arg, char *str, int *index, va_list arguments, char **buf)
{
	if (g_formats[str[*index]].printfunc)
	{
		ft_set_overrides(arg);
		//ft_write("toto");
		//ft_print_params(arg);		
		//ft_write(g_formats[str['s']].printfunc(arg, va_arg(arguments, char*)));
		//ft_write(va_arg(arguments, char *));

		*buf = ft_strjoin_clr(*buf, g_formats[str[(*index)]].printfunc(arg, arguments), 0);
		//ft_write(*buf);

		//ft_write(g_formats[str[*index]].printfunc(arg, var));
		return (1);
	}
	return (0);
}

t_params	*ft_create_params(void)
{
	t_params	*arg;

	arg = (t_params *)malloc(sizeof(t_params));
	if (arg)
		return (arg);
	else
		return (NULL);
}

t_params	*ft_set_zero_params(t_params *arg)
{
	int	i;

	ft_bzero(arg, sizeof(t_params));
	return (arg);
}

int		ft_read_string(char *str, va_list arguments)
{
	int			index;
	t_params	arg;
	char		*buf;
	int			tmp;

	buf = NULL;
	index = 0;
	tmp = index;
	ft_bzero(&arg, sizeof(t_params));
	if (str)
	{
		while (str[index] != '\0')
		{
			if (str[index] == '%')
			{
				ft_bzero(&arg, sizeof(t_params));
				tmp = (tmp != 0) ? tmp + 1 : tmp;
				buf = ft_strjoin_clr(buf, ft_strsub(str, tmp, index - tmp), 1);
				index++;
				while (str[index] != '\0')
				{
					if (ft_set_flags(&arg, str, &index) == 1)						
						;
					else if (ft_set_length(&arg, str, &index) == 1)
						;
					else if (ft_set_width(&arg, str, &index) == 1)
						;
					else if (ft_set_prec(&arg, str, &index) == 1)
						;
					else if (ft_set_spec(&arg, str, &index, arguments, &buf) == 1)
					{
						tmp = index;
						break;
					}
					else
						break;
					index++;		
				}
			}
			index++;
		}
	}
	ft_write(buf);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	arguments;

	va_start(arguments, format);
	ft_read_string((char *)format, arguments);
	va_end(arguments);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac)
	{
		ft_set_g_formats();
		ft_write("my printf :\n");
		//ft_printf(TEXT);
		ft_putchar(10);
		ft_write("standard printf :\n");
		printf(TEXT);
		}
	return (0);
}

/*
int		main(int ac, char **av)
{
	
	if (ac == 2)
		;
	ft_set_g_formats();
	ft_read_string(av[1]);
	printf("#-ll");
	//ft_putnbr(printf(""));
	//ft_putchar(10);
	//printf("%Z546", 6);
	//printf("string = \n");
	//ft_putnbr(printf("string = \n"));
	//printf("string = 漢字\n");
	//ft_putnbr(printf("string = 漢字\n"));
	//ft_putchar(10);
	//ft_putendl("string = 漢字");
	//ft_putchar('漢');
	return (0);
}
*/