/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_reverse_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 11:31:02 by rertzer           #+#    #+#             */
/*   Updated: 2023/01/16 11:25:05 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	ck_ops_reverse(t_stack **stack)
{
	*stack = (*stack)->prev;
}

void	ck_ops_rra(t_ckdata *ckdata)
{
	if (NULL != ckdata->stack_a)
		ck_ops_reverse(&(ckdata->stack_a));
}

void	ck_ops_rrb(t_ckdata *ckdata)
{
	if (NULL != ckdata->stack_b)
		ck_ops_reverse(&(ckdata->stack_b));
}

void	ck_ops_rrr(t_ckdata *ckdata)
{
	if (NULL != ckdata->stack_a)
		ck_ops_reverse(&(ckdata->stack_a));
	if (NULL != ckdata->stack_b)
		ck_ops_reverse(&(ckdata->stack_b));
}
