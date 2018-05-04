#include "libft.h"

static int		ft_lenght(uintmax_t a)
{
	int		i;

	i = 1;
	while (a > 9)
	{
		a /= 10;
		i++;
	}
	return (i);
}

char		*ft_uimaxtoa(uintmax_t nb)
{
	int			i;
	int			j;
	uintmax_t	rest;
	char		*str;

	j = 0;
	i = ft_lenght(nb);
	if (!(str = ft_strnew(i)))
		return (NULL);
	while (i)
	{
		rest = nb % 10;
		str[i-- - 1] = (char)rest + '0';
		nb = nb / 10;
	}
	return (str);
}
