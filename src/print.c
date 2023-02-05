/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:22:06 by rertzer           #+#    #+#             */
/*   Updated: 2023/02/05 17:19:53 by rertzer          ###   ########.fr       */
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

void	ps_ops_print(t_psdata *psdata, char *str)
{
	if (psdata->size == 5)
	{
		psdata->small_moves[psdata->sm_index] = str;
		psdata->sm_index++;
	}
	else
		ft_putendl_fd(str, 1);
}
