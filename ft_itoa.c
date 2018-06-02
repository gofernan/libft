/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 20:24:17 by gofernan          #+#    #+#             */
/*   Updated: 2018/06/02 18:38:41 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_lenght(intmax_t a)
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

char			*ft_itoa(intmax_t n)
{
	int			i;
	int			j;
	intmax_t	rest;
	char		*str;

	j = 0;
	i = ft_lenght(n);
	if (!(str = ft_strnew(i)))
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		j++;
	}
	while (i > j)
	{
		if (n < 0)
			rest = -(n % 10);
		else
			rest = n % 10;
		str[i-- - 1] = (char)rest + '0';
		n = n / 10;
	}
	return (str);
}
