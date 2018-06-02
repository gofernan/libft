/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 18:27:59 by gofernan          #+#    #+#             */
/*   Updated: 2018/06/02 21:53:14 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_length(uintmax_t a)
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

char			*ft_uitoa(uintmax_t nb)
{
	int			i;
	int			j;
	uintmax_t	rest;
	char		*str;

	j = 0;
	i = ft_length(nb);
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
