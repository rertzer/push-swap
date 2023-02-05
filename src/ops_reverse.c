/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_reverse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:41:56 by rertzer           #+#    #+#             */
/*   Updated: 2023/02/05 17:26:33 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_ops_reverse(t_stack **stack)
{
	*stack = (*stack)->prev;
}

void	ps_ops_rra(t_psdata *psdata)
{
	ps_ops_reverse(&(psdata->stack_a));
	ps_ops_print(psdata, "rra");
}

void	ps_ops_rrb(t_psdata *psdata)
{
	ps_ops_reverse(&(psdata->stack_b));
	ps_ops_print(psdata, "rrb");
}

void	ps_ops_rrr(t_psdata *psdata)
{
	ps_ops_reverse(&(psdata->stack_a));
	ps_ops_reverse(&(psdata->stack_b));
	ps_ops_print(psdata, "rrr");
}
