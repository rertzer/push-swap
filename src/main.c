/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:45:32 by rertzer           #+#    #+#             */
/*   Updated: 2023/01/16 15:29:40 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_init_psdata(t_psdata *psdata)
{
	psdata->stack_a = NULL;
	psdata->stack_b = NULL;
	psdata->size_a = 0;
	psdata->size_b = 0;
	psdata->quartile1 = 0;
	psdata->quartile2 = 0;
	psdata->quartile3 = 0;
	psdata->next2move = NULL;
	psdata->smallest_a = NULL;
	psdata->index = 0;
	psdata->size = 0;
	psdata->values = NULL;
	psdata->sorted = NULL;
	psdata->to_push = NULL;
	psdata->table = NULL;
	psdata->arg_lst = NULL;
}

void	ps_stack_already_sorted(t_psdata *psdata)
{
	t_stack	*tmp;
	t_stack	*last;
	int		sorted;

	sorted = 1;
	tmp = psdata->stack_a;
	last = psdata->stack_a->prev;
	while (tmp != last)
	{
		if (tmp->nb > tmp->next->nb)
		{
			sorted = 0;
			break ;
		}
		tmp = tmp->next;
	}
	if (sorted)
		ps_quit(psdata, 0);
}

int	main(int argc, char **argv)
{
	t_psdata	psdata;

	if (argc > 1)
	{
		ps_init_psdata(&psdata);
		ps_load_stack(&psdata, argc, argv);
		ps_stack_already_sorted(&psdata);
		ps_run(&psdata);
		ps_quit(&psdata, 0);
	}
	return (0);
}
