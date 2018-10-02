/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:06:58 by gofernan          #+#    #+#             */
/*   Updated: 2018/10/02 23:29:41 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int		*ft_range(int min, int max)
{
	int *arr;
	int i;

	i = 0;
	if (min >= max)
	{
		arr = NULL;
		return (arr);
	}
	if (!(arr = (int*)malloc((max - min) * sizeof(int))))
		return (NULL);
	while (min < max)
	{
		arr[i] = min;
		i++;
		min++;
	}
	return (arr);
}
