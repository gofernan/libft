/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 16:19:36 by gofernan          #+#    #+#             */
/*   Updated: 2018/05/07 18:13:13 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_lenght(int a, int base)
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
		while (a > (base - 1))
		{
			a /= base;
			i++;
		}
	}
	return (i);
}

char			*ft_octal(int nb)
{
	int		i;
	int		j;
	char	*str;

	j = 29;
	if (nb >= 0)
		i = ft_lenght(nb, 8);
	else
		i = 11;
	if (!(str = ft_strnew(i)))
		return (NULL);
	while (i)
	{
		str[i-- - 1] = (((unsigned int)nb << j) >> 29) + '0';
		j -= 3;
	}
	return (str);
}

char			*ft_hexadecimal(int nb)
{
	int		i;
	int		j;
	int		tmp;
	char	*str;

	j = 28;
	if (nb >= 0)
		i = ft_lenght(nb, 16);
	else
		i = 8;
	if (!(str = ft_strnew(i)))
		return (NULL);
	while (i)
	{
		tmp = ((unsigned int)nb << j) >> 28;
		if (tmp > 9)
			str[i-- - 1] = tmp + 87;
		else
			str[i-- - 1] = tmp + 48;
		j -= 4;
	}
	return (str);
}

char			*ft_decimal(int nb)
{
	int		i;
	int		j;
	int		rest;
	char	*str;

	j = 0;
	i = ft_lenght(nb, 10);
	if (!(str = ft_strnew(i)))
		return (NULL);
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
		j++;
	}
	while (i > j)
	{
		rest = nb % 10;
		str[i-- - 1] = (char)rest + '0';
		nb = nb / 10;
	}
	return (str);
}

char			*ft_binary(int nb)
{
	int		i;
	int		j;
	char	*str;

	j = 31;
	if (nb >= 0)
		i = ft_lenght(nb, 2);
	else
		i = 32;
	if (!(str = ft_strnew(i)))
		return (NULL);
	while (i)
		str[i-- - 1] = (((unsigned int)nb << j--) >> 31) + '0';
	return (str);
}

char			*ft_itoa_base(int nb, int base)
{
	if (base == 10)
		return (ft_decimal(nb));
	else if (base == 2)
		return (ft_binary(nb));
	else if (base == 16)
		return (ft_hexadecimal(nb));
	else if (base == 8)
		return (ft_octal(nb));
	else
		return (NULL);
}
