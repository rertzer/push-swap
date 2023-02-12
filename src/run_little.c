/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_little.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:16:07 by rertzer           #+#    #+#             */
/*   Updated: 2023/02/12 10:15:38 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_run_small(t_psdata *psdata)
{
	int	i;

	i = psdata->size - 2;
	while (--i)
		ps_ops_pb(psdata);

	ps_run_three(psdata);
	ps_insert_back(psdata);
	ps_first_top(psdata);
	ps_simplify(psdata);
	i = -1;
	while (++i < 12)
	{
		if (psdata->small_moves[i])
			ft_putendl_fd(psdata->small_moves[i], 1);
	}
}

void	ps_run_two(t_psdata *psdata)
{
	if (psdata->stack_a->nb > psdata->stack_a->next->nb)
		ps_ops_sa(psdata);
}

void	ps_run_three(t_psdata *psdata)
{
	int	which_case;

	which_case = 0;
	if (psdata->stack_a->nb < psdata->stack_a->next->nb)
		which_case += 1;
	if (psdata->stack_a->next->nb < psdata->stack_a->prev->nb)
		which_case += 2;
	if (psdata->stack_a->nb < psdata->stack_a->prev->nb)
		which_case += 4;
	if (which_case == 0 || which_case == 5 || which_case == 6)
		ps_ops_sa(psdata);
	if (which_case == 2 || which_case == 4)
		ps_ops_ra(psdata);
	if (which_case <= 1)
		ps_ops_rra(psdata);
}
