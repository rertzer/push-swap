/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:16:55 by rertzer           #+#    #+#             */
/*   Updated: 2023/02/05 17:27:31 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_ops_push(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a;
	t_stack	*b;

	a = *stack_a;
	b = *stack_b;
	*stack_b = a;
	if (a != a->next)
		*stack_a = a->next;
	else
		*stack_a = NULL;
	a->prev->next = a->next;
	a->next->prev = a->prev;
	if (NULL == b)
	{
		a->prev = a;
		a->next = a;
	}
	else
	{
		a->prev = b->prev;
		a->prev->next = a;
		a->next = b;
		b->prev = a;
	}
}

void	ps_ops_pa(t_psdata *psdata)
{
	ps_ops_push(&(psdata->stack_b), &(psdata->stack_a));
	ps_ops_print(psdata, "pa");
}

void	ps_ops_pb(t_psdata *psdata)
{
	ps_ops_push(&(psdata->stack_a), &(psdata->stack_b));
	ps_ops_print(psdata, "pb");
}
