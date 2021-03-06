/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcslen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 15:45:01 by gofernan          #+#    #+#             */
/*   Updated: 2018/05/07 18:27:41 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t			ft_wcslen(const wchar_t *s)
{
	size_t counter;

	counter = 0;
	while (*s++ != 0)
		counter++;
	return (counter);
}
