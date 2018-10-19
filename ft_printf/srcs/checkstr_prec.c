/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkstr_prec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 19:32:28 by gofernan          #+#    #+#             */
/*   Updated: 2018/06/02 22:15:38 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static void		prec_asarg_aux(t_fstr *pfs, int *tmpargorder)
{
	*tmpargorder = pfs->argov;
	pfs->argov = pfs->prec_asargv;
	if (pfs->precheck)
		store_arglist(pfs);
	else
	{
		pfs->precvalue = ft_atoi(sel_arglist(pfs)->str);
		if (pfs->precvalue < 0)
		{
			pfs->prec = 0;
			pfs->precvalue = 0;
		}
	}
	pfs->prec_asarg = 1;
	pfs->argov = *tmpargorder;
}

static int		checkstr_prec_asarg(const char *str, t_fstr *pfs, int *aux)
{
	char	*tmp;
	int		tmpargorder;
	int		i;

	i = 2;
	while (str[i] >= 48 && str[i] <= 57)
		i++;
	if (str[i] == '$')
	{
		*aux = i;
		if (!(tmp = malloc(sizeof(char) * (i - 1))))
			exit(EXIT_FAILURE);
		ft_strncpy(tmp, str + 2, i - 2);
		tmp[i - 2] = '\0';
		pfs->prec_asargv = ft_atoi(tmp);
		free(tmp);
		if (!pfs->prec_asargv)
		{
			pfs->prec = 0;
			return (-1);
		}
		prec_asarg_aux(pfs, &tmpargorder);
		return (1);
	}
	return (0);
}

int				checkstr_prec_as(const char *str, t_fstr *pfs, int *aux)
{
	if (*(str + 2) >= 48 && *(str + 2) <= 57)
	{
		if (checkstr_prec_asarg(str, pfs, aux))
			return (1);
	}
	*aux = 1;
	if (!pfs->argo && !pfs->fwidth_as && !pfs->prec_as)
		(pfs->argov)++;
	if (pfs->precheck)
	{
		store_arglist(pfs);
	}
	else
	{
		pfs->precvalue = ft_atoi(sel_arglist(pfs)->str);
		if (pfs->precvalue < 0)
		{
			pfs->prec = 0;
			pfs->precvalue = 0;
		}
	}
	pfs->prec_as = 1;
	(pfs->argov)++;
	return (1);
}

static int		checkstr_prec_aff(const char *str, t_fstr *pfs, int *aux)
{
	char	*tmp;
	int		i;

	i = 1;
	while (str[i] >= 48 && str[i] <= 57)
		i++;
	*aux = i - 1;
	if (pfs->precheck)
		return (1);
	if (!(tmp = (char *)malloc(sizeof(char) * i)))
		exit(EXIT_FAILURE);
	ft_strncpy(tmp, str + 1, i - 1);
	tmp[i - 1] = '\0';
	pfs->precvalue = ft_atoi(tmp);
	free(tmp);
	return (1);
}

int				checkstr_prec(const char *str, t_fstr *pfs, int *aux)
{
	if (*str == '.')
	{
		pfs->prec = 1;
		if (*(str + 1) == '*')
			return (checkstr_prec_as(str, pfs, aux));
	}
	else
		return (0);
	if (*(str + 1) >= 48 && *(str + 1) <= 57)
		return (checkstr_prec_aff(str, pfs, aux));
	else
	{
		if (!pfs->precheck)
			pfs->precvalue = 0;
	}
	return (1);
}
