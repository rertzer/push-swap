/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:22:06 by rertzer           #+#    #+#             */
/*   Updated: 2023/01/12 15:24:25 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_print(t_psdata *psdata)
{
	ft_printf("pile A:\n");
	ps_stack_print(psdata->stack_a);
	ft_printf("\npile B:\n");
	ps_stack_print(psdata->stack_b);
	ft_printf("\n");
}

void	ps_stack_print(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		ft_printf("%d\n", tmp->nb);
		if (tmp->next != stack)
			tmp = tmp->next;
		else
			tmp = NULL;
	}
}
