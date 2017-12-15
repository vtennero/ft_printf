

#include "ft_printf.h"

#include <stdio.h>

char		*ft_is_s(t_params *arg, char *str)
{
	int		i;
	int		j;
	int		k;
	int		n;
	char	*s;

	i = 0;
	j = 0;
	k = 0;
	n = 0;
	s = (char *)malloc(ft_strlen(str) + 1);
	if (arg->prec)
		i = arg->width - arg->prec;
	else
		i = arg->width - ft_strlen(str);
	if (i > 0)
	{
	while (j < i)
	{
		if (arg->flags[MINUS])
			{
				s[j] = str[i];
				i++;
			}
		else
			s[j] = ' ';
		j++;
	}
	while (j < ft_strlen(str))
	{
		if (arg->flags[MINUS])
			s[j] = ' ';
		else
			{
				s[j] = str[k];
				k++;
			}
		j++;
	}
}
else
{

}
	s[j] = '\0';
	//ft_write(s);
	return (s);
}