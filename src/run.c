/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:19:29 by rertzer           #+#    #+#             */
/*   Updated: 2023/02/05 15:11:53 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_run(t_psdata *psdata)
{
	psdata->size = ps_stack_size(psdata->stack_a);
	if (psdata->size <= 1)
		return ;
	else if (psdata->size == 2)
		ps_run_two(psdata);
	else if (psdata->size <= 5)
		ps_run_small(psdata);
	else if (psdata->size < 200)
		ps_run_medium(psdata);
	else
		ps_run_large(psdata);
}

void	ps_run_medium(t_psdata *psdata)
{
	ps_push_to_b(psdata);
	ps_mediane(psdata);
	ps_split_values(psdata);
	ps_insert_back(psdata);
	ps_first_top(psdata);
}

void	ps_run_large(t_psdata *psdata)
{
	ps_push_to_b(psdata);
	ps_quartile(psdata);
	ps_split_values(psdata);
	psdata->quartile1 = psdata->quartile2;
	psdata->quartile3 = psdata->quartile2;
	ps_split_values(psdata);
	ps_insert_back(psdata);
	ps_first_top(psdata);
}
