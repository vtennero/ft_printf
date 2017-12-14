

#include "ft_printf.h"

#include <stdio.h>

void	ft_is_s(t_params *arg, char *str)
{
	int	n;

	n = arg->prec;
	if (arg->flags[PREC])
	{
		str = ft_strndup(str, n);
	}

	ft_write(str)
}