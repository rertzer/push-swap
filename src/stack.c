/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:25:36 by rertzer           #+#    #+#             */
/*   Updated: 2023/01/14 11:03:44 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_stack_add_back(t_psdata *psdata, t_stack **stack, int nb)
{
	t_stack	*last;
	t_stack	*new;

	new = ps_stack_new(psdata, nb);
	if (*stack)
	{
		last = ps_stack_last(*stack);
		new->next = last->next;
		last->next = new;
		new->next->prev = new;
		new->prev = last;
	}
	else
		*stack = new;
}

t_stack	*ps_stack_new(t_psdata *psdata, int nb)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (NULL == new)
		ps_quit(psdata, 1);
	new->nb = nb;
	new->prev = new;
	new->next = new;
	return (new);
}

t_stack	*ps_stack_last(t_stack *stack)
{
	t_stack	*last;

	if (NULL == stack)
		return (NULL);
	last = stack;
	while (last->next && last->next != stack)
		last = last->next;
	return (last);
}

int	ps_stack_size(t_stack *stack)
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

t_stack	*ps_stack_next(t_stack *tmp, t_stack *stack)
{
	if (tmp != NULL && tmp->next != stack)
		return (tmp->next);
	else
		return (NULL);
}
