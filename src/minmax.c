/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minmax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:49:10 by rertzer           #+#    #+#             */
/*   Updated: 2023/01/14 11:11:23 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
	int	buffer;

	buffer = *a;
	*a = *b;
	*b = buffer;
}

int	ps_max(int a, int b)
{
	if (a < b)
		return (b);
	else
		return (a);
}

int	ps_min_strat(int *tab, int size)
{
	int	i;
	int	min;

	min = 0;
	i = -1;
	while (++i < size)
	{
		if (tab[i] < tab[min])
			min = i;
	}
	return (min);
}

t_stack	*ps_get_insert_floor(t_psdata *psdata, int nb)
{
	t_stack	*floor;
	t_stack	*tmp;

	floor = NULL;
	tmp = psdata->stack_a;
	if (NULL == tmp)
		return (NULL);
	while (tmp)
	{
		if (tmp->nb > nb && (floor == NULL || tmp->nb < floor->nb))
			floor = tmp;
		tmp = ps_stack_next(tmp, psdata->stack_a);
	}
	if (floor == NULL)
	{
		ps_set_smallest_a(psdata);
		floor = psdata->smallest_a;
	}
	return (floor);
}

void	ps_set_smallest_a(t_psdata *psdata)
{
	t_stack	*tmp;

	tmp = psdata->stack_a;
	psdata->smallest_a = tmp;
	while (tmp)
	{
		if (tmp->nb < psdata->smallest_a->nb)
			psdata->smallest_a = tmp;
		tmp = ps_stack_next(tmp, psdata->stack_a);
	}
}
