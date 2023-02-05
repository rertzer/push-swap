/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:36:24 by rertzer           #+#    #+#             */
/*   Updated: 2023/02/05 17:27:10 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_ops_rotate(t_stack **stack)
{
	*stack = (*stack)->next;
}

void	ps_ops_ra(t_psdata *psdata)
{
	ps_ops_rotate(&(psdata->stack_a));
	ps_ops_print(psdata, "ra");
}

void	ps_ops_rb(t_psdata *psdata)
{
	ps_ops_rotate(&(psdata->stack_b));
	ps_ops_print(psdata, "rb");
}

void	ps_ops_rr(t_psdata *psdata)
{
	ps_ops_rotate(&(psdata->stack_a));
	ps_ops_rotate(&(psdata->stack_b));
	ps_ops_print(psdata, "rr");
}
