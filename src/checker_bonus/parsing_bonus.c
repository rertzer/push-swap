/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 11:59:26 by rertzer           #+#    #+#             */
/*   Updated: 2023/01/18 09:49:48 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	ck_inside(t_ckdata *ckdata, int nb)
{
	t_stack	*tmp;

	tmp = ckdata->stack_a;
	while (tmp)
	{
		if (tmp->nb == nb)
			return (1);
		if (tmp->next != ckdata->stack_a)
			tmp = tmp->next;
		else
			tmp = NULL;
	}
	return (0);
}

static int	ck_safe_add(t_ckdata *ckdata, int sign, \
		unsigned int nba, unsigned int nbb)
{
	unsigned int	max;

	max = INT_MAX;
	if (sign < 0)
		max++;
	max -= nbb;
	max /= 10;
	if (nba > max)
		ck_quit(ckdata, 1);
	return (nba * 10 + nbb);
}

static int	ck_atoi(t_ckdata *ckdata, char *str)
{
	int	sign;
	int	nb;

	nb = 0;
	if (str[0] == '-')
			sign = -1;
	else
		sign = 1;
	if (str[0] == '-' || str[0] == '+')
		str++;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			nb = ck_safe_add(ckdata, sign, (unsigned int)nb, \
					(unsigned int)*str - '0');
		else
			ck_quit(ckdata, 1);
		str++;
	}
	return (sign * nb);
}

void	ck_load_stack(t_ckdata *ckdata, int argc, char **argv)
{
	int		nb;
	int		i;
	int		j;

	i = 0;
	while (++i < argc)
	{
		ckdata->arg_lst = ft_split(argv[i], ' ');
		if (ckdata->arg_lst == NULL)
			ck_quit(ckdata, 1);
		j = -1;
		while (NULL != ckdata->arg_lst[++j])
		{
			nb = ck_atoi(ckdata, ckdata->arg_lst[j]);
			if (ck_inside(ckdata, nb))
				ck_quit(ckdata, 1);
			ck_stack_add_back(ckdata, &(ckdata->stack_a), nb);
		}
		ck_clean_arg_lst(ckdata);
	}
}
