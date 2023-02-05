/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:38:18 by rertzer           #+#    #+#             */
/*   Updated: 2023/02/05 14:48:24 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_push_to_b(t_psdata *psdata)
{
	psdata->size = ps_stack_size(psdata->stack_a);
	ps_to_array(psdata);
	ps_compute_to_push(psdata);
}

void	ps_compute_to_push(t_psdata *psdata)
{
	int	offset;
	int	max_offset;

	max_offset = 0;
	offset = -1;
	while (++offset < psdata->size)
	{
		psdata->to_push[offset] = ps_to_push_score(psdata->stack_a, offset);
		if (psdata->to_push[offset] > psdata->to_push[max_offset])
			max_offset = offset;
	}
	//fprintf(stderr, "kept : %d, offset %d\n", psdata->to_push[max_offset], max_offset);
	ps_set_to_push(psdata, max_offset);
}

void	ps_set_to_push(t_psdata *psdata, int offset)
{
	int	max;
	t_stack	*start;
	t_stack *current;

	psdata->size_a = ps_stack_size(psdata->stack_a);
	max = ps_to_push_score(psdata->stack_a, offset);
	offset = 0;
	current = psdata->stack_a;
	while (current->tp != max)
	{
		current = current->next;
		offset++;
	}
	start = current;
	while (current)
	{
		if (current->tp == max)
		{
			psdata->to_push[offset] = 0;
			max--;
		}
		else
			psdata->to_push[offset] = 1;
		//fprintf(stderr, "max %d, offset %d, tp %d, topush %d\n", max, offset, current->tp, psdata->to_push[offset]);
		current = ps_stack_next(current, start);
		offset = (offset + 1) % psdata->size_a;
	}
}

int	ps_to_push_score(t_stack *stack, int offset)
{
	int	i;
	int	max;
	t_stack	*current;
	t_stack *tmp;

	i = -1;
	while (++i < offset)
		stack = stack->next;
	
	stack->prev->tp = 1;
	current = stack->prev->prev;
	while (current)
	{
		tmp = current->next;
		max = 0;
		while (tmp)
		{
			if (tmp->nb > current->nb)
				max = ps_max(max, tmp->tp);
			tmp = ps_stack_next(tmp, stack);
		}
		current->tp = max + 1;
		//fprintf(stderr, "curent max : %d\n", current->tp);
		current = ps_stack_prev(current, stack->prev);
	}
	max = ps_get_tp_max(stack);
	return (max);
}

int	ps_get_tp_max(t_stack *stack)
{
	int		max;
	t_stack	*tmp;

	max = stack->tp;
	tmp = stack;
	while (tmp)
	{
		max = ps_max(max, tmp->tp);
		tmp = ps_stack_next(tmp, stack);
	}
	return (max);
}
