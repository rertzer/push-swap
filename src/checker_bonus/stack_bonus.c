/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:05:38 by rertzer           #+#    #+#             */
/*   Updated: 2023/01/15 12:11:14 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ck_stack_add_back(t_ckdata *ckdata, t_stack **stack, int nb)
{
	t_stack	*last;
	t_stack	*new;

	new = ck_stack_new(ckdata, nb);
	if (*stack)
	{
		last = ck_stack_last(*stack);
		new->next = last->next;
		last->next = new;
		new->next->prev = new;
		new->prev = last;
	}
	else
		*stack = new;
}

t_stack	*ck_stack_new(t_ckdata *ckdata, int nb)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (NULL == new)
		ck_quit(ckdata, 1);
	new->nb = nb;
	new->prev = new;
	new->next = new;
	return (new);
}

t_stack	*ck_stack_last(t_stack *stack)
{
	t_stack	*last;

	if (NULL == stack)
		return (NULL);
	last = stack;
	while (last->next && last->next != stack)
		last = last->next;
	return (last);
}

int	ck_stack_size(t_stack *stack)
{
	int		size;
	t_stack	*tmp;

	size = 0;
	tmp = stack;
	while (tmp)
	{
		size++;
		if (tmp->next != stack)
			tmp = tmp->next;
		else
			tmp = NULL;
	}
	return (size);
}

t_stack	*ck_stack_next(t_stack *tmp, t_stack *stack)
{
	if (tmp != NULL && tmp->next != stack)
		return (tmp->next);
	else
		return (NULL);
}
