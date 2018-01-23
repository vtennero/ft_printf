#include "ft_printf.h"

void	*ft_prop_cast_s(t_params *arg, va_list lst)
{
	if (arg->flags[L])
		return (va_arg(lst, wchar_t*));
	else
		return (va_arg(lst, char *));
}

//signed

long long	ft_prop_cast_signed(t_params *arg, va_list lst)
{
	if (arg->flags[J])
		return (va_arg(lst, intmax_t));
	else if (arg->flags[Z])
		return (va_arg(lst, size_t));
	else if (arg->flags[LL])
		return (va_arg(lst, long long));
	else if (arg->flags[L])
		return (va_arg(lst, long));
	else if (arg->flags[H])
		return ((short)va_arg(lst,int));
	else if (arg->flags[HH])
		return ((char)va_arg(lst, int));
	return (va_arg(lst, int));
}

int		ft_prop_cast_c(t_params *arg, va_list lst)
{
	if (arg->flags[L])
		return (va_arg(lst, wint_t));
	else
		return (va_arg(lst, int));
}

//unsigned

unsigned long long	ft_prop_cast_unsigned(t_params *arg, va_list lst)
{
	if (arg->flags[J])
		return (va_arg(lst, uintmax_t));
	else if (arg->flags[Z])
		return (va_arg(lst, size_t));
	else if (arg->flags[LL])
		return (va_arg(lst, unsigned long long));
	else if (arg->flags[L])
		return (va_arg(lst, unsigned long));
	else if (arg->flags[H])
		{
			//ft_putendl("H");
		return ((unsigned short)va_arg(lst, unsigned int));
		}
	else if (arg->flags[HH])
		{
			//ft_putendl("HH");
		return ((unsigned char)va_arg(lst, unsigned int));
		}
		//ft_putendl("va arg unsigned int");
	return (va_arg(lst, unsigned int));
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

unsigned long long	ft_prop_cast_o(t_params *arg, va_list lst)
{
	if (arg->flags[HH])
		return ((char)va_arg(lst, unsigned int));
	else if (arg->flags[H])
		return ((short)va_arg(lst, unsigned int));
	else if (arg->flags[L])
		return (va_arg(lst, unsigned long));
	else if (arg->flags[LL])
		return (va_arg(lst, unsigned long long));
	else if (arg->flags[J])
		return (va_arg(lst, uintmax_t));
	else if (arg->flags[Z])
		return (va_arg(lst, size_t));
	else
		return (va_arg(lst, unsigned int));
}

unsigned long long ft_prop_cast_p(t_params *arg, va_list lst)
{
	return (va_arg(lst, unsigned long long));
	//return (ft_itoa((int)va_arg(lst, void *)));
}

unsigned long long	ft_prop_cast_x(t_params *arg, va_list lst)
{
		if (arg->flags[HH])
		return ((char)va_arg(lst, unsigned int));
	else if (arg->flags[H])
		return ((short)va_arg(lst, unsigned int));
	else if (arg->flags[L])
		return (va_arg(lst, unsigned long));
	else if (arg->flags[LL])
		return (va_arg(lst, unsigned long long));
	else if (arg->flags[J])
		return (va_arg(lst, uintmax_t));
	else if (arg->flags[Z])
		return (va_arg(lst, size_t));
	else
		return (va_arg(lst, unsigned int));
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