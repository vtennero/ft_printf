
#include "ft_printf.h"

static void	ft_check_if_null(char *str, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		if (str[i] == -8)
			str[i] = 0;
		i++;
	}
}

int	ft_write(char *str)
{
	int	n;

	n = ft_strlen(str);
	ft_check_if_null(str, n);
	write(1, str, n);
	//free(str);
	return (n);
}