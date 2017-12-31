/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 17:48:38 by vtennero          #+#    #+#             */
/*   Updated: 2017/12/29 17:15:40 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

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

int		ft_set_spec(t_params *arg, char *str, int *index, va_list arguments, char **buf)
{
	if (g_formats[str[*index]].printfunc)
	{
		ft_general_overrides(arg);
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

static char		*ft_width_perc(t_params *arg)
{
	if (arg->flags[MINUS])
		return(ft_is_s_right(arg->width, arg->width - 1, "%", ' '));
	else
		return(ft_is_s_left(arg->width, arg->width - 1, "%", ' '));
}

static int		ft_read_string(char *str, va_list arguments)
{
	int			index;
	t_params	arg;
	char		*buf;
	//int			tmp;
	int			p;

	buf = NULL;
	index = 0;
	p = 0;
	//tmp = index;
	ft_bzero(&arg, sizeof(t_params));
	if (str)
	{
		while (str[index] != '\0')
		{
			if (str[index] == '%')
			{
				if (ft_strlen(str) == 1)
					return (0);
				p++;
				ft_bzero(&arg, sizeof(t_params));
				//tmp = (tmp != 0) ? tmp + 1 : tmp;
				//buf = ft_strjoin_clr(buf, ft_strsub(str, tmp, index - tmp), 1);
				index++;
				while (str[index] != '\0')
				{
					if (ft_set_flags(&arg, str, &index) == 1)						
						;
					else if (ft_set_length(&arg, str, &index) == 1)
						;
					else if (ft_set_width(&arg, str, &index) == 1)
					{
						if (str[index + 1] == '%')
						{
							buf = ft_width_perc(&arg);
							index++;
							break;
						}
					}
					else if (ft_set_prec(&arg, str, &index) == 1)
						;
					else if (ft_set_spec(&arg, str, &index, arguments, &buf) == 1)
					{
						//tmp = index;
						break;
					}
					else if (str[index] == '%')
					{
						while (str[index] == '%')
						{
							p++;
							index++;
						}
						index--;
						buf = ft_append(buf, p / 2, '%');
						//tmp = index;
						p = 0;
						break;
					}
					else
					{
						index--;
						break;
					}
					index++;		
				}
			}
			else
				buf = ft_append(buf, 1, str[index]);
			index++;
		}
	}
	return (ft_write(buf));
}

int	ft_printf(const char *format, ...)
{
	va_list	arguments;
	int	n;

	ft_set_g_formats();
	va_start(arguments, format);
	/*if (ft_strstr(format, "%") == NULL)
		return (ft_write((char *)format));*/
	n = ft_read_string((char *)format, arguments);
	va_end(arguments);
	return (n);
}
