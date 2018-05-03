#include "libft.h"

static int		ft_lenght(long a)
{
	int		i;

	i = 1;
	if (a < 0)
	{
		while (a < -9)
		{
			a /= 10;
			i++;
		}
		i++;
	}
	else
	{
		while (a > 9)
		{
			a /= 10;
			i++;
		}
	}
	return (i);
}

char			*ft_ltoa(long nb)
{
	int		i;
	int		j;
	long	rest;
	char	*str;

	j = 0;
	i = ft_lenght(nb);
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		j++;
	}
	while (i > j)
	{
		if (nb < 0)
			rest = -(nb % 10);
		else
			rest = nb % 10;
		str[i-- - 1] = (char)rest + '0';
		nb = nb / 10;
	}
	return (str);
}
