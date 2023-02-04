/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_reverse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:41:56 by rertzer           #+#    #+#             */
/*   Updated: 2023/01/09 16:31:05 by rertzer          ###   ########.fr       */
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
	ft_printf("rra\n");
}

void	ps_ops_rrb(t_psdata *psdata)
{
	ps_ops_reverse(&(psdata->stack_b));
	ft_printf("rrb\n");
}

void	ps_ops_rrr(t_psdata *psdata)
{
	ps_ops_reverse(&(psdata->stack_a));
	ps_ops_reverse(&(psdata->stack_b));
	ft_printf("rrr\n");
}
