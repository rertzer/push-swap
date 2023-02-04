/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 11:25:37 by rertzer           #+#    #+#             */
/*   Updated: 2023/01/16 11:22:36 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	ck_ops_push(t_stack **stack_a, t_stack **stack_b)
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

void	ck_ops_pa(t_ckdata *ckdata)
{
	if (NULL != ckdata->stack_b)
		ck_ops_push(&(ckdata->stack_b), &(ckdata->stack_a));
}

void	ck_ops_pb(t_ckdata *ckdata)
{
	if (NULL != ckdata->stack_a)
		ck_ops_push(&(ckdata->stack_a), &(ckdata->stack_b));
}
