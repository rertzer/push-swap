/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:38:18 by rertzer           #+#    #+#             */
/*   Updated: 2023/01/12 16:43:02 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_push_to_b(t_psdata *psdata)
{
	psdata->size = ps_stack_size(psdata->stack_a);
	ps_to_array(psdata);
	ps_sort_array(psdata->sorted, psdata->size);
	ps_compute_to_push(psdata);
}

void	ps_compute_to_push(t_psdata *psdata)
{
	psdata->size = ps_stack_size(psdata->stack_a);
	ps_init_table(psdata);
	ps_build_table(psdata);
	if (0 != psdata->table[psdata->size - 1][psdata->size -1])
		ps_assemble_to_push(psdata, psdata->size - 1, psdata->size - 1);
}

static void	ps_keep_pos(int *a, int *b)
{
	if (*a < 0)
		*a = 0;
	if (*b < 0)
		*b = 0;
}

void	ps_assemble_to_push(t_psdata *psdata, int i, int j)
{
	ps_keep_pos(&i, &j);
	if (psdata->values[i] == psdata->sorted[j])
	{
		psdata->to_push[i] = 0;
		if (i != 0 || j != 0)
			ps_assemble_to_push(psdata, i - 1, j - 1);
	}
	else
	{
		if (i != 0 && j != 0)
		{
			if (psdata->table[i][j - 1] > psdata->table[i - 1][j])
				ps_assemble_to_push(psdata, i, j - 1);
			else
				ps_assemble_to_push(psdata, i - 1, j);
		}
		else
		{
			if (i != 0)
				ps_assemble_to_push(psdata, i - 1, j);
			else if (j != 0)
				ps_assemble_to_push(psdata, i, j -1);
		}
	}
}
