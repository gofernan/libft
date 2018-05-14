/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imaxtoa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 16:05:46 by gofernan          #+#    #+#             */
/*   Updated: 2018/05/07 16:50:47 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_lenght(intmax_t a, int base)
{
	int	i;

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
		while (a > (base - 1))
		{
			a /= base;
			i++;
		}
	}
	return (i);
}

static char			*ft_octal(intmax_t nb, int sizeintmaxb)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	j = sizeintmaxb - 3;
	k = j;
	if (nb >= 0)
		i = ft_lenght(nb, 8);
	else
		i = sizeintmaxb / 3 + 1;
	if (!(str = ft_strnew(i)))
		return (NULL);
	while (i)
	{
		str[i-- - 1] = (((uintmax_t)nb << j) >> k) + '0';
		if (j < 3 && i > 0)
			str[i-- - 1] = ((uintmax_t)nb >> (k + 3 - j)) + '0';
		else
			j -= 3;
	}
	return (str);
}

static char			*ft_hexadecimal(intmax_t nb, int sizeintmaxb, char lworup)
{
	int			i;
	int			j;
	int			k;
	intmax_t	tmp;
	char		*str;

	j = sizeintmaxb - 4;
	k = j;
	if (nb >= 0)
		i = ft_lenght(nb, 16);
	else
		i = sizeintmaxb / 4;
	if (!(str = ft_strnew(i)))
		return (NULL);
	while (i)
	{
		tmp = ((uintmax_t)nb << j) >> k;
		if (tmp > 9)
			str[i-- - 1] = tmp + lworup;
		else
			str[i-- - 1] = tmp + 48;
		j -= 4;
	}
	return (str);
}

static char			*ft_decimal(intmax_t nb)
{
	int			i;
	int			j;
	intmax_t	rest;
	char		*str;

	j = 0;
	i = ft_lenght(nb, 10);
	if (!(str = ft_strnew(i)))
		return (NULL);
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

static char			*ft_binary(intmax_t nb, int sizeintmaxb)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	j = sizeintmaxb - 1;
	k = j;
	if (nb >= 0)
		i = ft_lenght(nb, 2);
	else
		i = sizeintmaxb;
	if (!(str = ft_strnew(i)))
		return (NULL);
	while (i)
		str[i-- - 1] = (((uintmax_t)nb << j--) >> k) + '0';
	return (str);
}

char				*ft_imaxtoa_base(intmax_t nb, int base, int alternative)
{
	int		sizeintmaxb;
	char	lwcase;
	char	upcase;

	lwcase = 87;
	upcase = 55;
	sizeintmaxb = sizeof(intmax_t) * 8;
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
