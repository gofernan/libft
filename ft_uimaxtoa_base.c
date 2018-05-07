#include "libft.h"

static int		ft_lenght(uintmax_t a, int base)
{
	int		i;

	i = 1;
	{
		while (a > (base - 1))
		{
			a /= base;
			i++;
		}
	}
	return (i);
}
static char		*ft_octal(uintmax_t nb, int sizeintmaxb)
{
	int i;
	int j;
	int k;
	char *str;

	j = sizeintmaxb - 3;
	k = j;
	i = ft_lenght(nb, 8);
	if (!(str = ft_strnew(i)))
		return (NULL);
	while (i)
	{
		str[i-- -1] = ((nb << j) >> k) + '0';
		if (j < 3 && i > 0)
			str[i-- -1] = (nb >> (k + 3 - j)) + '0';
		else
			j -= 3;
	}
	return (str);
}
static char		*ft_hexadecimal(uintmax_t nb, int sizeintmaxb, char lworup)
{
	int			i;
	int			j;
	int			k;
	uintmax_t	tmp;
	char		*str;

	j = sizeintmaxb - 4;
	k = j;
	i = ft_lenght(nb, 16);
	if (!(str = ft_strnew(i)))
		return (NULL);
	while (i)
	{
		tmp = (nb << j) >> k;
		if (tmp > 9)
			str[i-- -1] = tmp + lworup;
		else
			str[i-- -1] = tmp + 48;
		j -= 4;
	}
	return (str);
}

static char		*ft_decimal(uintmax_t nb)
{
	int			i;
	int			j;
	uintmax_t	rest;
	char		*str;

	j = 0;
	i = ft_lenght(nb, 10);
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

static char		*ft_binary(uintmax_t nb, int sizeintmaxb)
{
	int i;
	int j;
	int k;
	char *str;

	j = sizeintmaxb - 1;
	k = j;
	i = ft_lenght(nb, 2);
	if (!(str = ft_strnew(i)))
		return (NULL);
	while (i)
		str[i-- - 1] = ((nb << j--) >> k) + '0';
	return (str);
}
char			*ft_uimaxtoa_base(uintmax_t nb, int base, int alternative)
{
	int sizeintmaxb;
	char lwcase = 87;
	char upcase = 55;

	sizeintmaxb = sizeof(uintmax_t) * 8;
	if (base == 10)
		return (ft_decimal(nb));
	else if (base == 2)
		return (ft_binary(nb, sizeintmaxb));
	else if (base == 16 && !alternative)
		return (ft_hexadecimal(nb, sizeintmaxb, lwcase));
	else if (base == 16)
		return (ft_hexadecimal(nb, sizeintmaxb, upcase));
	else if (base == 8)
		return (ft_octal(nb, sizeintmaxb));
	else
		return (NULL);
}
