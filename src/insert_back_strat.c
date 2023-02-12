/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_back_strat.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 09:26:09 by rertzer           #+#    #+#             */
/*   Updated: 2023/02/12 11:22:12 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_insert_back_strat_zero(t_psdata *psdata)
{
	t_stack	*floor;

	floor = ps_get_insert_floor(psdata, psdata->next2move->nb);
	if (floor != NULL)
	{
		while (psdata->stack_a != floor && psdata->stack_b != psdata->next2move)
			ps_ops_rr(psdata);
		while (psdata->stack_a != floor)
			ps_ops_ra(psdata);
	}
	while (psdata->stack_b != psdata->next2move)
		ps_ops_rb(psdata);
	ps_ops_pa(psdata);
}

void	ps_insert_back_strat_one(t_psdata *psdata)
{
	t_stack	*floor;

	floor = ps_get_insert_floor(psdata, psdata->next2move->nb);
	if (floor != NULL)
	{
		while (psdata->stack_a != floor && psdata->stack_b != psdata->next2move)
			ps_ops_rrr(psdata);
		while (psdata->stack_a != floor)
			ps_ops_rra(psdata);
	}
	while (psdata->stack_b != psdata->next2move)
		ps_ops_rrb(psdata);
	ps_ops_pa(psdata);
}

void	ps_insert_back_strat_two(t_psdata *psdata)
{
	t_stack	*floor;

	floor = ps_get_insert_floor(psdata, psdata->next2move->nb);
	if (floor != NULL)
	{
		while (psdata->stack_a != floor)
			ps_ops_ra(psdata);
	}
	while (psdata->stack_b != psdata->next2move)
		ps_ops_rrb(psdata);
	ps_ops_pa(psdata);
}

void	ps_insert_back_strat_three(t_psdata *psdata)
{
	t_stack	*floor;

	floor = ps_get_insert_floor(psdata, psdata->next2move->nb);
	if (floor != NULL)
	{	
		while (psdata->stack_a != floor)
			ps_ops_rra(psdata);
	}
	while (psdata->stack_b != psdata->next2move)
		ps_ops_rb(psdata);
	ps_ops_pa(psdata);
}

void	ps_insert_back_strat_four(t_psdata *psdata)
{
	ps_ops_pa(psdata);
	ps_ops_sa(psdata);
}
