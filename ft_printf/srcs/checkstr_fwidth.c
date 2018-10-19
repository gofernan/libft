/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkstr_fwidth.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 17:39:27 by gofernan          #+#    #+#             */
/*   Updated: 2018/06/04 11:15:17 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static int		asarg_aux(t_fstr *pfs, int *tmpargorder)
{
	if (pfs->precheck)
		store_arglist(pfs);
	else
	{
		pfs->fwidthvalue = ft_atoi(sel_arglist(pfs)->str);
		if (pfs->fwidthvalue < 0)
		{
			pfs->flags[2] = 1;
			pfs->fwidthvalue = -pfs->fwidthvalue;
		}
	}
	pfs->fwidth_asarg = 1;
	pfs->argov = *tmpargorder;
	return (1);
}

static int		checkstr_fwidth_asarg(const char *str, t_fstr *pfs,
		int *aux, int *i)
{
	char	*tmp;
	int		tmpargorder;

	*i = 1;
	while (str[*i] >= 48 && str[*i] <= 57)
		(*i)++;
	if (str[*i] == '$')
	{
		*aux = *i;
		if (!(tmp = malloc(sizeof(char) * (*i))))
			exit(EXIT_FAILURE);
		ft_strncpy(tmp, str + 1, *i - 1);
		tmp[*i - 1] = '\0';
		pfs->fwidth_asargv = ft_atoi(tmp);
		free(tmp);
		if (!pfs->fwidth_asargv)
		{
			pfs->fwidth = 0;
			return (-1);
		}
		tmpargorder = pfs->argov;
		pfs->argov = pfs->fwidth_asargv;
		return (asarg_aux(pfs, &tmpargorder));
	}
	return (0);
}

static int		checkstr_fwidth_as(const char *str, t_fstr *pfs,
		int *aux, int *i)
{
	if (str[*i] == '*')
	{
		pfs->fwidth = 1;
		if (str[*i + 1] >= 48 && str[*i + 1] <= 57)
			if (checkstr_fwidth_asarg(str, pfs, aux, i))
				return (1);
		if (!pfs->argo && !pfs->prec_as && !pfs->fwidth_as)
			(pfs->argov)++;
		if (pfs->precheck)
			store_arglist(pfs);
		else
		{
			pfs->fwidthvalue = ft_atoi(sel_arglist(pfs)->str);
			if (pfs->fwidthvalue < 0)
			{
				pfs->flags[2] = 1;
				pfs->fwidthvalue = -pfs->fwidthvalue;
			}
		}
		(pfs->argov)++;
		pfs->fwidth_as = 1;
		return (1);
	}
	return (0);
}

int				checkstr_fwidth(const char *str, t_fstr *pfs, int *aux)
{
	int		i;
	char	*tmp;

	i = 0;
	if (checkstr_fwidth_as(str, pfs, aux, &i))
		return (1);
	while (str[i] >= 48 && str[i] <= 57)
		i++;
	if (str[i] != '$' && i > 0)
	{
		*aux = i - 1;
		if (pfs->precheck)
			return (1);
		if (!(tmp = (char *)malloc(sizeof(char) * (i + 1))))
			exit(EXIT_FAILURE);
		ft_strncpy(tmp, str, i);
		tmp[i] = '\0';
		pfs->fwidthvalue = ft_atoi(tmp);
		free(tmp);
		pfs->fwidth = 1;
		return (1);
	}
	return (0);
}
