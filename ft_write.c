
#include "ft_printf.h"

void	ft_write(char *str)
{
	int	n;

	n = ft_strlen(str);
	write(1, str, n);
}