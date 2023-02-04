/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:36:24 by rertzer           #+#    #+#             */
/*   Updated: 2023/01/09 16:31:44 by rertzer          ###   ########.fr       */
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
	ft_printf("ra\n");
}

void	ps_ops_rb(t_psdata *psdata)
{
	ps_ops_rotate(&(psdata->stack_b));
	ft_printf("rb\n");
}

void	ps_ops_rr(t_psdata *psdata)
{
	ps_ops_rotate(&(psdata->stack_a));
	ps_ops_rotate(&(psdata->stack_b));
	ft_printf("rr\n");
}
