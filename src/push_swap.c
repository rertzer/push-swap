/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:50:51 by rertzer           #+#    #+#             */
/*   Updated: 2023/01/16 15:23:54 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_first_top(t_psdata *psdata)
{
	int		i;
	t_stack	*tmp;

	psdata->size_a = ps_stack_size(psdata->stack_a);
	ps_set_smallest_a(psdata);
	i = 0;
	tmp = psdata->stack_a;
	while (tmp)
	{
		if (tmp == psdata->smallest_a)
			break ;
		i++;
		tmp = ps_stack_next(tmp, psdata->stack_a);
	}
	if (i <= psdata->size_a / 2)
	{
		while (psdata->stack_a != psdata->smallest_a)
			ps_ops_ra(psdata);
	}
	else
	{
		while (psdata->stack_a != psdata->smallest_a)
			ps_ops_rra(psdata);
	}
}

static void	ps_insert_quartile3(t_psdata *psdata, int i)
{
	psdata->to_push[i] = 2;
	ps_ops_pb(psdata);
	ps_ops_rb(psdata);
}

static void	ps_insert_quartile1(t_psdata *psdata, int i)
{
	psdata->to_push[i] = 2;
	ps_ops_pb(psdata);
}

void	ps_split_values(t_psdata *psdata)
{
	t_stack	*tmp;
	int		i;

	i = -1;
	tmp = psdata->stack_a;
	while (++i < psdata->size)
	{
		if (psdata->to_push[i] == 2)
			continue ;
		if (psdata->to_push[i] == 1)
		{
			if (tmp->nb >= psdata->quartile3)
				ps_insert_quartile3(psdata, i);
			else if (tmp->nb <= psdata->quartile1)
				ps_insert_quartile1(psdata, i);
			else
				ps_ops_ra(psdata);
		}
		else
			ps_ops_ra(psdata);
		tmp = psdata->stack_a;
	}
}
