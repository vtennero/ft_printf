
#include "ft_printf.h"

static int	ft_check_if_null(char *str)
{
	int		n;
	char	*s2;

	n = 0;
	if (!str)
		return (0);
	if ((s2 = ft_strstr(str, "^@")) != 0)
	{
		n++;
		//while ((s2 = ft_strstr(s2, "^@")) != 0)
		//	n++;
	}
	return (n);
}

int	ft_write(char *str)
{
	int	n;
	int	p;

	n = ft_strlen(str);
	p = ft_check_if_null(str);
	write(1, str, n);
	return (n - p);
}