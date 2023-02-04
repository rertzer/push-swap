/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 10:44:21 by rertzer           #+#    #+#             */
/*   Updated: 2023/01/14 09:37:51 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_insert_back(t_psdata *psdata)
{
	void	*strat[4];
	t_fun	ib_strat;

	strat[0] = ps_insert_back_strat_zero;
	strat[1] = ps_insert_back_strat_one;
	strat[2] = ps_insert_back_strat_two;
	strat[3] = ps_insert_back_strat_three;
	while (NULL != psdata->stack_b)
	{
		ps_insert_back_next(psdata);
		if (psdata->smallest_a == NULL || \
				psdata->next2move->nb < psdata->smallest_a->nb)
			psdata->smallest_a = psdata->next2move;
		ib_strat = strat[psdata->index];
		ib_strat(psdata);
	}
}

static void	ps_insert_back_next_init(t_psdata *psdata, \
		int *index, int *min_strat, int *min_steps)
{
	psdata->size_a = ps_stack_size(psdata->stack_a);
	psdata->size_b = ps_stack_size(psdata->stack_b);
	psdata->next2move = psdata->stack_b;
	*index = 0;
	*min_strat = 0;
	*min_steps = INT_MAX;
}

void	ps_insert_back_next(t_psdata *psdata)
{
	int		mini;
	int		min_steps;
	int		min_strat;
	int		index;
	t_stack	*tmp;

	ps_insert_back_next_init(psdata, &index, &min_strat, &min_steps);
	tmp = psdata->stack_b;
	while (tmp)
	{
		mini = ps_calculate_min_steps(psdata, tmp, index);
		if (mini < min_steps)
		{
			min_steps = mini;
			min_strat = psdata->index;
			psdata->next2move = tmp;
		}
		index++;
		tmp = ps_stack_next(tmp, psdata->stack_b);
	}
	psdata->index = min_strat;
}

int	ps_calculate_min_steps(t_psdata *psdata, t_stack *tmp, int index)
{
	int	step_ar;
	int	step_arr;
	int	step_brr;
	int	min[4];
	int	strat;

	step_brr = psdata->size_b - index;
	step_ar = ps_get_insert_index(psdata, tmp->nb);
	step_arr = psdata->size_a - step_ar;
	min[0] = ps_max(step_ar, index);
	min[1] = ps_max(step_arr, step_brr);
	min[2] = step_ar + step_brr;
	min[3] = step_arr + index;
	strat = ps_min_strat(min, 4);
	psdata->index = strat;
	return (min[strat]);
}

int	ps_get_insert_index(t_psdata *psdata, int nb)
{
	int		index;
	t_stack	*tmp;
	t_stack	*target;

	target = ps_get_insert_floor(psdata, nb);
	if (target == NULL)
		return (0);
	index = 0;
	tmp = psdata->stack_a;
	while (tmp)
	{
		if (tmp == target)
			break ;
		index++;
		tmp = ps_stack_next(tmp, psdata->stack_a);
	}
	return (index);
}
