/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 11:52:18 by vtennero          #+#    #+#             */
/*   Updated: 2017/12/14 12:55:40 by vtennero         ###   ########.fr       */
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

void		ft_set_bool_flags(t_params *arg, int n)
{
	arg->flags[n] = 1;	
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
		arg->prec = 0;
		while (ft_isdigit((int)str[*index]) == 1)
		{
			arg->prec = 10 * arg->prec + (int)str[*index] - 48;
			*index += 1;
		}
		*index -= 1;
		return (1);
	}
	return (0);
}

int		ft_set_spec(t_params *arg, char *str, int *index)
{
	if (ft_is_char(str[*index], 's') == 1)
		return (arg->spec[STR] = 1);
	else if (ft_is_char(str[*index], 'S') == 1)
		return (arg->spec[L_STR] = 1);
	else if (ft_is_char(str[*index], 'p') == 1)
		return (arg->spec[PTR_A] = 1);
	else if (ft_is_char(str[*index], 'd') == 1)
		return (arg->spec[DEC] = 1);
	else if (ft_is_char(str[*index], 'D') == 1)
		return (arg->spec[L_S_DEC] = 1);
	else if (ft_is_char(str[*index], 'i') == 1)
		return 	(arg->spec[INTGR] = 1);
	else if (ft_is_char(str[*index], 'o') == 1)
		return (arg->spec[U_OCT] = 1);
	else if (ft_is_char(str[*index], 'O') == 1)
		return (arg->spec[L_U_OCT] = 1);
	else if (ft_is_char(str[*index], 'u') == 1)
		return (arg->spec[U_DEC] = 1);
	else if (ft_is_char(str[*index], 'U') == 1)
		return (arg->spec[L_U_DEC] = 1);
	else if (ft_is_char(str[*index], 'x') == 1)
		return (arg->spec[U_HEXA] = 1);
	else if (ft_is_char(str[*index], 'X') == 1)
		return (arg->spec[L_U_HEXA] = 1);
	else if (ft_is_char(str[*index], 'x') == 1)
		return (arg->spec[CHR] = 1);
	else if (ft_is_char(str[*index], 'C') == 1)
		return (arg->spec[L_CHR] = 1);
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
	printf("%c : %d\n", '#', arg->flags[0]);
	printf("%c : %d\n", '+', arg->flags[1]);
	printf("%c : %d\n", '-', arg->flags[2]);
	printf("%c : %d\n", ' ', arg->flags[3]);
	printf("%c : %d\n", '0', arg->flags[4]);
	printf("%c : %d\n", 'h', arg->flags[5]);
	printf("%c : %d\n", 'l', arg->flags[6]);
	printf("%c : %d\n", 'j', arg->flags[7]);
	printf("%c : %d\n", 'z', arg->flags[8]);
	printf("%s : %d\n", "hh", arg->flags[9]);
	printf("%s : %d\n", "ll", arg->flags[10]);
	printf("width = %d\n", arg->width);
	printf("precision = %d\n", arg->prec);
	printf("%c : %d\n", 's', arg->spec[0]);
	printf("%c : %d\n", 'S', arg->spec[1]);
	printf("%c : %d\n", 'p', arg->spec[2]);
	printf("%c : %d\n", 'd', arg->spec[3]);
	printf("%c : %d\n", 'D', arg->spec[4]);
	printf("%c : %d\n", 'i', arg->spec[5]);
	printf("%c : %d\n", 'o', arg->spec[6]);
	printf("%c : %d\n", 'O', arg->spec[7]);
	printf("%c : %d\n", 'u', arg->spec[8]);
	printf("%c : %d\n", 'U', arg->spec[9]);
	printf("%c : %d\n", 'x', arg->spec[10]);
	printf("%c : %d\n", 'X', arg->spec[11]);
	printf("%c : %d\n", 'x', arg->spec[12]);
	printf("%c : %d\n", 'C', arg->spec[13]);
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
					else if (ft_set_width(&arg, str, &index) == 1)
						;
					else if (ft_set_prec(&arg, str, &index) == 1)
						;
					else if (ft_set_spec(&arg, str, &index) == 1)
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
	printf("%+c\n", 'a');
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
