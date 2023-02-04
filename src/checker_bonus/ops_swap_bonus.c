/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 11:35:19 by rertzer           #+#    #+#             */
/*   Updated: 2023/01/16 11:27:23 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static t_stack	*ck_ops_swap(t_stack *stack)
{
	t_stack	*a;
	t_stack	*b;

	a = stack;
	b = a->next;
	a->prev->next = b;
	b->prev = a->prev;
	a->prev = b;
	a->next = b->next;
	a->next->prev = a;
	b->next = a;
	return (b);
}

void	ck_ops_sa(t_ckdata *ckdata)
{
	if (NULL != ckdata->stack_a)
		ckdata->stack_a = ck_ops_swap(ckdata->stack_a);
}

void	ck_ops_sb(t_ckdata *ckdata)
{
	if (NULL != ckdata->stack_b)
		ckdata->stack_b = ck_ops_swap(ckdata->stack_b);
}

void	ck_ops_ss(t_ckdata *ckdata)
{
	if (NULL != ckdata->stack_a)
		ck_ops_sa(ckdata);
	if (NULL != ckdata->stack_b)
		ck_ops_sb(ckdata);
}
