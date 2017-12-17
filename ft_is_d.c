
#include "ft_printf.h"

static void		ft_override_params(t_params *arg, int nb)
{
	if (arg->flags[SPACE] && arg->flags[PLUS])
		arg->flags[SPACE] = 0;
	if (arg->flags[SPACE] && nb < 0)
		arg->flags[SPACE] = 0;
}
/*
char		*ft_is_d_right(int malloc_size, int n, char *str, char c)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	n = malloc_size - n;
	s = malloc(malloc_size + 1);
	while (i < malloc_size)
	{
		if (n)
		{
			s[i] = str[j];
			n--;
			j++;
		}
		else
			s[i] = c;
		i++;
	}
	s[i] = '\0';
	return (s);
}

char		*ft_is_d_left(int malloc_size, int n, char *str, char c)
{
	int		i;
	int		j;
	char	*s;


	i = 0;
	j = 0;
	s = malloc(malloc_size + 1);
	while (i < malloc_size)
	{
		if (n)
		{
			s[i] = c;
			n--;
		}
		else
		{
			s[i] = str[j];
			j++;
		}
		i++;
	}
	s[i] = '\0';
	return (s);
}
*/
char	*ft_malloc_width(int n, int z)
{
	char	*str;
	int		i;
	char	c;

	c = (z) ? '0' : ' ';
	i = 0;
	str = (char *)malloc (n + 1);
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_malloc_prec(t_params *arg, int n)
{
	char	*str;
	int		i;
	int		neg;
	int		malloc_size;

	neg = 0;
	i = 0;
	if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	malloc_size = arg->flags[SPACE] + arg->flags[PLUS] + neg + ft_max(ft_strlen(ft_itoa_base(n, "0123456789")), arg->prec);
	str = (char *) malloc(malloc_size);
	while (malloc_size)
		str[malloc_size--] = '0';
	if (arg->flags[SPACE])
		str[0] = ' ';
	else if (arg->flags[PLUS])
		str[0] = '+';
	else
		str[0] = '-';
	return (ft_strjoin_clr(str, ft_itoa_base(n, "0123456789"), 2));
}

char	*ft_is_d(t_params *arg, va_list arguments)
{
	int		nb;
	char	*s1;
	char	*s2;

	nb = va_arg(arguments, int);

	ft_override_params(arg, nb);

	length = 

	s1 = ft_malloc_prec(arg, nb);

	s2 = ft_malloc_width(ft_max(arg->width, 1), arg->flags[ZERO]);

	if (arg->flags[MINUS])
		return (ft_strjoin_clr(s1, s2, 2));
	else
		return (ft_strjoin_clr(s2 , s1, 2));
}
