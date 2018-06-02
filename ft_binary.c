/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 22:28:20 by gofernan          #+#    #+#             */
/*   Updated: 2018/06/02 22:28:57 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_length(intmax_t a, int base)
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

char			*ft_binary(intmax_t nb)
{
	int		i;
	int		j;
	int		k;
	int		sizeintmaxb;
	char	*str;

	sizeintmaxb = sizeof(intmax_t) * 8;
	j = sizeintmaxb - 1;
	k = j;
	if (nb >= 0)
		i = ft_length(nb, 2);
	else
		i = sizeintmaxb;
	if (!(str = ft_strnew(i)))
		return (NULL);
	while (i)
		str[i-- - 1] = (((uintmax_t)nb << j--) >> k) + '0';
	return (str);
}
