/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 18:17:18 by gofernan          #+#    #+#             */
/*   Updated: 2018/05/07 18:17:19 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_lenght(long long a)
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

char			*ft_lltoa(long long nb)
{
	int			i;
	int			j;
	long long	rest;
	char		*str;

	j = 0;
	i = ft_lenght(nb);
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
