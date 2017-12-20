#include "ft_printf.h"

static long long	ft_prop_cast_d(t_params *arg, va_list lst)
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

static void	*ft_prop_cast_s(t_params *arg, va_list lst)
{
	if (arg->flags[L])
		return (va_arg(lst, wchar_t*));
	else
		return (va_arg(lst, char *));
}

long long	ft_prop_cast(t_params *arg, va_list lst, char c)
{
	if (c == 'd')
		return (ft_prop_cast_d(arg, lst));
	else
		return (0);
}