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
	if (g_formats[spec].printfunc)
	{
		ft_general_overrides(arg);
		*buf = ft_strjoin_clr(*buf, g_formats[spec].printfunc(arg, arguments), 2);
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

/*
static int		ft_read_string(char *str, va_list arguments)
{
	int			index;
	t_params	arg;
	char		*buf;
	int			p;

	buf = NULL;
	index = 0;
	p = 0;
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
*/


/*
static int		ft_read_string(char *str, va_list arguments)
{
	int			index;
	t_params	arg;
	char		*buf;
	int			p;

	buf = NULL;
	index = 0;
	p = 0;
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
				index++;
				while (str[index] != '\0')
				{
					if (!(ft_set_flags(&arg, str, &index) == 1))
						if (!(ft_set_length(&arg, str, &index) == 1))
							if (!(ft_set_width(&arg, str, &index) == 1))
								if (!(ft_set_prec(&arg, str, &index) == 1))
									if (!(ft_set_spec(&arg, str, &index, arguments, &buf) == 1))
										if (!(ft_is_perc(str[index]) == 1))
											buf = ft_append(buf, 1, str[index]);
										else
											break;
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
*/

/*
static int		ft_is_perc(t_params *arg, char *str, int *index, va_list arguments, char **buf)
{
	int			t;

	ft_putendl("//FT_IS_PERC//");
	t = 0;
	if (str[*index])
	{	
	if (ft_set_flags(arg, str, index) == 1)						
		t = 1;
	else if (ft_set_length(arg, str, index) == 1)
			t = 1;
	else if (ft_set_width(arg, str, index) == 1)
		t = 1;
	else if (ft_set_prec(arg, str, index) == 1)
		t = 1;
	else if (ft_set_spec(arg, str, index, arguments, buf) == 1)
		t = 2;
	}
	return (t);
}

static int		ft_read_string(char *str, va_list arguments)
{
	int			index;
	t_params	arg;
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
				ft_bzero(&arg, sizeof(t_params));
				index++;
				while (str[index] != '\0')
				{
					if (ft_is_perc(&arg, str, &index, arguments, &buf) == 1)
						;
					else if (ft_is_perc(&arg, str, &index, arguments, &buf) == 2)
						break;
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
*/