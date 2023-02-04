/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:13:53 by rertzer           #+#    #+#             */
/*   Updated: 2023/01/05 16:36:45 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*ps_ops_swap(t_stack *stack)
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

void	ps_ops_sa(t_psdata *psdata)
{
	psdata->stack_a = ps_ops_swap(psdata->stack_a);
	ft_printf("sa\n");
}

void	ps_ops_sb(t_psdata *psdata)
{
	psdata->stack_b = ps_ops_swap(psdata->stack_b);
	ft_printf("sb\n");
}

void	ps_ops_ss(t_psdata *psdata)
{
	ps_ops_sa(psdata);
	ps_ops_sb(psdata);
	ft_printf("ss\n");
}
