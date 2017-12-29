

#include "ft_printf.h"


static char		ft_set_zero(t_params *arg)
{
	if (arg->flags[ZERO])
		return ('0');
	return (' ');
}

char		*ft_is_s_right(int malloc_size, int n, char *str, char c)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	n = malloc_size - n;
	s = malloc(malloc_size + 1);
	if (s)
	{
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
}
	return (s);
}

char		*ft_is_s_left(int malloc_size, int n, char *str, char c)
{
	int		i;
	int		j;
	char	*s;


	i = 0;
	j = 0;
	s = malloc(malloc_size + 1);
	if (s)
	{
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
}
	return (s);
}

char		*ft_is_s(t_params *arg, va_list lst)
{
	int		malloc_size;
	int		prec;
	int		width;
	int		str_length;
	int		n;
	char	*str;

	str = va_arg(lst, char *);
	//str = ft_llutoa_base((char *)va_arg(arguments, unsigned long long), "0123456789");
	if (str == NULL)
		str = ft_strdup("(null)"); //leak
	str_length = ft_strlen(str);
	width = arg->width;
	prec = arg->prec;
	malloc_size = 0;
	n = 0;

	//traitement de la precision

	if (prec > str_length)
		malloc_size = str_length;
	else if (arg->flags[PREC] == 0)
		malloc_size = str_length;
	else
		malloc_size = prec;

	//traitement de la width

	if (width > malloc_size)
		{
			n = width - malloc_size;
			malloc_size = width;
		}
	else
		;

	//malloc et remplissage de la string

	if (arg->flags[MINUS])
		return(ft_is_s_right(malloc_size, n, str, ft_set_zero(arg)));
	else
		return(ft_is_s_left(malloc_size, n, str, ft_set_zero(arg)));
}