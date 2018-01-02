#include "ft_printf.h"

long long	ft_prop_cast_d(t_params *arg, va_list lst)
{
	if (arg->flags[HH])
		return ((char)va_arg(lst, int));
	else if (arg->flags[H])
		return ((short)va_arg(lst, int));
	else if (arg->flags[L])
		return (va_arg(lst, long));
	else if (arg->flags[LL])
		return (va_arg(lst, long long));
	else if (arg->flags[J])
		return (va_arg(lst, intmax_t));
	else if (arg->flags[Z])
		return (va_arg(lst, size_t));
	else
		return (va_arg(lst, int));
}

char		*ft_prop_cast_u(t_params *arg, va_list lst)
{
	if (arg->flags[Z])
		return (ft_llutoa(va_arg(lst, size_t)));
	else if (arg->flags[J])
		return (ft_llutoa(va_arg(lst, uintmax_t)));
	else if (arg->flags[LL])
		return (ft_llutoa(va_arg(lst, unsigned long long)));
	else if (arg->flags[L])
		return (ft_lutoa(va_arg(lst, unsigned long)));
	else if (arg->flags[H])
		return (ft_llutoa((short)va_arg(lst, unsigned int)));
	else if (arg->flags[HH])
		return (ft_itoa((char)va_arg(lst, unsigned int)));
	else
		return (ft_llutoa(va_arg(lst, unsigned int)));
}

void	*ft_prop_cast_s(t_params *arg, va_list lst)
{
	if (arg->flags[L])
		return (va_arg(lst, wchar_t*));
	else
		return (va_arg(lst, char *));
}

int		ft_prop_cast_c(t_params *arg, va_list lst)
{
	if (arg->flags[L])
		return (va_arg(lst, wint_t));
	else
		return (va_arg(lst, int));
}

void	*ft_prop_cast_p(t_params *arg, va_list lst)
{
	return (ft_itoa((int)va_arg(lst, void *)));
}

/*
long long	ft_prop_cast(t_params *arg, va_list lst, char c)
{
	if (c == 'd')
		return (ft_prop_cast_d(arg, lst));
	if (c == 's')
		return (ft_prop_cast_s(arg, lst));
	if (c == 'u')
		return (ft_prop_cast_u(arg, lst));
	else
		return (0);
}*/