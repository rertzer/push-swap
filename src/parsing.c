/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:44:54 by rertzer           #+#    #+#             */
/*   Updated: 2023/01/18 09:48:39 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_inside(t_psdata *psdata, int nb)
{
	t_stack	*tmp;

	tmp = psdata->stack_a;
	while (tmp)
	{
		if (tmp->nb == nb)
			return (1);
		if (tmp->next != psdata->stack_a)
			tmp = tmp->next;
		else
			tmp = NULL;
	}
	return (0);
}

void	ps_load_stack(t_psdata *psdata, int argc, char **argv)
{
	int		nb;
	int		i;
	int		j;

	i = 0;
	while (++i < argc)
	{
		psdata->arg_lst = ft_split(argv[i], ' ');
		if (psdata->arg_lst == NULL)
			ps_quit(psdata, 1);
		j = -1;
		while (NULL != psdata->arg_lst[++j])
		{
			nb = ps_atoi(psdata, psdata->arg_lst[j]);
			if (ps_inside(psdata, nb))
				ps_quit(psdata, 1);
			ps_stack_add_back(psdata, &(psdata->stack_a), nb);
		}
		ps_clean_arg_lst(psdata);
	}
}

static int	ps_safe_add(t_psdata *psdata, int sign, \
		unsigned int nba, unsigned int nbb)
{
	unsigned int	max;

	max = INT_MAX;
	if (sign < 0)
		max++;
	max -= nbb;
	max /= 10;
	if (nba > max)
		ps_quit(psdata, 1);
	return (nba * 10 + nbb);
}

int	ps_atoi(t_psdata *psdata, char *str)
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
			nb = ps_safe_add(psdata, sign, (unsigned int)nb, \
					(unsigned int)*str - '0');
		else
			ps_quit(psdata, 1);
		str++;
	}
	return (sign * nb);
}
