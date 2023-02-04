/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:30:54 by rertzer           #+#    #+#             */
/*   Updated: 2023/01/15 18:29:30 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ck_check(t_ckdata *ckdata)
{
	int	ok;

	ok = 0;
	ok += ck_check_stack_a(ckdata);
	ok += ck_check_stack_b(ckdata);
	if (ok == 2)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	ck_check_stack_a(t_ckdata *ckdata)
{
	int		prev;
	t_stack	*stack;

	prev = INT_MIN;
	stack = ckdata->stack_a;
	while (stack)
	{
		if (stack->nb < prev)
			return (0);
		prev = stack->nb;
		stack = ps_stack_next(stack, ckdata->stack_a);
	}
	return (1);
}

int	ck_check_stack_b(t_ckdata *ckdata)
{
	if (ckdata->stack_b == NULL)
		return (1);
	else
		return (0);
}
