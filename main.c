/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 11:52:18 by vtennero          #+#    #+#             */
/*   Updated: 2017/12/13 23:22:12 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

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
	if (ft_is_char(str[*index], 'h') == 1)
		return(arg->flags[H] = 1);	
	else if (ft_is_char(str[*index], 'l') == 1)
		return(arg->flags[L] = 1);	
	else if (ft_is_char(str[*index], 'j') == 1)
		return(arg->flags[J] = 1);	
	else if (ft_is_char(str[*index], 'z') == 1)
		return(arg->flags[Z] = 1);	
	return (0);
}

void		ft_set_bool_flags(t_params *arg, int n)
{
	arg->flags[n] = 1;	
}

void		ft_set_width(t_params *arg, int n)
{
	arg->width = n;
}

void		ft_set_prec(t_params *arg, int n)
{
	arg->prec = n;
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
	/*i = 0;
	  arg->width = 0;
	  arg->prec = 0;
	  arg->spec = 0;
	  while (i < 12)
	  {
	  arg->flags[i] = 0;
	  i++;
	  }*/
	return (arg);
}

void	ft_print_params(t_params *arg)
{
	int	i;

	i = 0;
	printf("width = %d\n", arg->width);
	printf("precision = %d\n", arg->prec);
	while (i < 11)
	{
		printf("flag %d : %d\n", i, arg->flags[i]);
		i++;
	}
	printf("spec = %d\n", arg->spec);
}

int		ft_read_string(char *str)
{
	int	index;
	t_params	arg;

	index = 0;
	if (str)
	{
		while (str[index] != '\0')
		{
			if (str[index] == '%')
			{
				index++;
				ft_bzero(&arg, sizeof(t_params));
				while (str[index] != '\0')
				{
					if (ft_set_flags(&arg, str, &index) == 1)
						;
					else if (ft_set_length(&arg, str, &index) == 1)
						;
					else
						break;
					index++;
				}
			}
			index++;
		}
	}
	ft_print_params(&arg);
	return (0);
}

int		main(int ac, char **av)
{
	t_params	*arg;

	if (ac == 2)
		;
	ft_read_string(av[1]);
	//printf("");
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
