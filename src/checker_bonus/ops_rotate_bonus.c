/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 11:33:32 by rertzer           #+#    #+#             */
/*   Updated: 2023/01/16 11:26:09 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	ck_ops_rotate(t_stack **stack)
{
	*stack = (*stack)->next;
}

void	ck_ops_ra(t_ckdata *ckdata)
{
	if (NULL != ckdata->stack_a)
		ck_ops_rotate(&(ckdata->stack_a));
}

void	ck_ops_rb(t_ckdata *ckdata)
{
	if (NULL != ckdata->stack_b)
		ck_ops_rotate(&(ckdata->stack_b));
}

void	ck_ops_rr(t_ckdata *ckdata)
{
	if (NULL != ckdata->stack_a)
		ck_ops_rotate(&(ckdata->stack_a));
	if (NULL != ckdata->stack_b)
		ck_ops_rotate(&(ckdata->stack_b));
}
