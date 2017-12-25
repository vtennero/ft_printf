
#include "ft_printf.h"

static void		ft_override_params(t_params *arg, int nb)
{
	if (arg->flags[SPACE] && arg->flags[PLUS])
		arg->flags[SPACE] = 0;
	if (arg->flags[SPACE] && nb < 0)
		arg->flags[SPACE] = 0;
}

static char	*ft_prep(char c)
{
	char	*preppie;

	preppie = malloc(sizeof(char) + 1);
	preppie[0] = c;
	preppie[1] = '\0';
	return (preppie);
}

static char	*ft_prepend(char *str, int number, t_params *arg)
{
	if (arg->flags[PLUS] && number >= 0)
		return (ft_strjoin_clr(ft_prep('+'), str, 0));
	else if (number < 0)
		return (ft_strjoin_clr(ft_prep('-'), str, 0));
	else if (arg->flags[SPACE])
		return (ft_strjoin_clr(ft_prep(' '), str, 0));
	else
		return (str);
}

static char	*ft_malloc_width(int n, int z)
{
	char	*str;
	int		i;
	char	c;

	c = (z) ? '0' : ' ';
	//c = ' ';
	i = 0;
	if (n < 0)
		n = 0;
	str = (char *)malloc(n + 1);
	if (str)
	{
		while (i < n)
		{
			str[i] = c;
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}

static char	*ft_malloc_prec(char *str, int prec)
{
	char	*s1;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = ft_strlen(str);
	s1 = (char *)malloc(sizeof(char) * ft_max(len, prec) + 1);
	if (s1)
	{
/*		ft_putnbr(prec - len);
		ft_putnbr(prec - len);
		ft_putnbr(prec);
		if (prec - len > 0)
		{
		ft_putstr("tata\n");
		ft_putnbr(prec - len);
*/
			while (i < prec - len)
				s1[i++] = '0';
//		}
		while (j < len)
		{
			s1[i] = str[j];
			j++;
			i++;
		}
}
	return (s1);
}

char	*ft_is_d(t_params *arg, va_list lst)
{
	long long	number;
	char		*s1;
	char		*s2;

	number = ft_prop_cast(arg, lst, 'd');
	//ft_print_params(arg);
	ft_override_params(arg, number);
	s1 = ft_malloc_prec(ft_itoa_base(ft_abs(number), "0123456789"), arg->prec);
	s1 = ft_prepend(s1, number, arg);
	s2 = ft_malloc_width(arg->width - ft_strlen(s1), arg->flags[ZERO]);	
	if (arg->flags[MINUS])
		return (ft_strjoin_clr(s1, s2, 2));
	else
		return (ft_strjoin_clr(s2 , s1, 2));
}
