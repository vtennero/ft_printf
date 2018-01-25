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

int		ft_set_spec(t_params *arg, char spec, va_list arguments, char **buf)
{
	char	*processed_string;

	processed_string = NULL;
	if (g_formats[spec].printfunc)
	{
		ft_general_overrides(arg);
		//printf("ft_set_spec buf pointer addr : %p\n", buf);
		processed_string = g_formats[spec].printfunc(arg, arguments);
		//printf("ft_set_spec processed_string pointer addr : %p\n", processed_string);
		*buf = ft_strjoin_clr(*buf, processed_string, 0);
		//free(processed_string);
		//*buf = ft_strjoin_clr(*buf, g_formats[spec].printfunc(arg, arguments), 2);
		return (1);
	}
	return (0);
}

static int		ft_flwp(t_params *arg, char *format, int *i)
{
	if (ft_set_flags(arg, format, i) == 1)						
		return (1);
	else if (ft_set_length(arg, format, i) == 1)
		return (1);
	else if (ft_set_width(arg, format, i) == 1)
		return (1);
	else if (ft_set_prec(arg, format, i) == 1)
		return (1);
	return (0);
}

static void		ft_is_not_perc(char **buf, char *format, int *index)
{
	int			i;
	char		*addition;

	i = 0;
	while (format[i] != '%' && format[i] != '\0')
		i += 1;
	addition = ft_strndup(format, i);
	//printf("ft_strndup malloc pointer addr : %p\n", addition);
	*index += i - 1;
	*buf = ft_strjoin_clr(*buf, addition, 2);
}

static void		ft_is_perc(char **buf, char *format, int *index, va_list arguments)
{
	int			i;
	char		*addition;
	t_params	arg;

	i = 1;
	ft_bzero(&arg, sizeof(t_params));
	*index += 1;
	while (format[i] != '\0')
	{
		if (ft_flwp(&arg, format, &i) == 1)
			;
		else if (ft_set_spec(&arg, format[i], arguments, buf) == 1)
			break;
		else
		{
			*buf = ft_strjoin_clr(*buf, ft_is_s_perc(&arg, format + i), 2);
			break;
		}
		i++;
	}
	*index += i - 1;
}

static int		ft_read_string(char *str, va_list arguments)
{
	int			index;
	char		*buf;

	buf = NULL;
	index = 0;
	if (str)
	{
		while (str[index] != '\0')
		{
			if (str[index] == '%')
			{
				if (ft_strlen(str) == 1)
					return (0);
				ft_is_perc(&buf, str + index, &index, arguments);
			}
			else
				ft_is_not_perc(&buf, str + index, &index);
			index++;
		}
	}
	return (ft_print_buffer(buf));
}

int	ft_printf(const char *format, ...)
{
	va_list	arguments;
	int	n;

	ft_set_g_formats();
	va_start(arguments, format);
	n = ft_read_string((char *)format, arguments);
	va_end(arguments);
	return (n);
}