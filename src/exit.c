/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:46:05 by rertzer           #+#    #+#             */
/*   Updated: 2023/02/05 13:51:37 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_quit(t_psdata *psdata, int error)
{
	if (error)
		ft_putendl_fd("Error", 2);
	ps_stack_clear(&(psdata->stack_a));
	ps_stack_clear(&(psdata->stack_b));
	ps_flush_arrays(psdata);
	ps_clean_arg_lst(psdata);
	exit(error);
}

void	ps_flush_arrays(t_psdata *psdata)
{
	if (NULL != psdata->to_push)
		free(psdata->to_push);
	if (NULL != psdata->values)
		free(psdata->values);
}

void	ps_clean_arg_lst(t_psdata *psdata)
{
	int	i;

	if (NULL == psdata->arg_lst)
		return ;
	i = -1;
	while (NULL != psdata->arg_lst[++i])
		free(psdata->arg_lst[i]);
	free(psdata->arg_lst);
	psdata->arg_lst = NULL;
}

void	ps_stack_clear(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*next;

	tmp = *stack;
	while (tmp)
	{
		if (tmp->next != *stack)
			next = tmp->next;
		else
			next = NULL;
		free(tmp);
		tmp = next;
	}
	*stack = NULL;
}
