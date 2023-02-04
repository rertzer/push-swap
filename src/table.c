/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:32:51 by rertzer           #+#    #+#             */
/*   Updated: 2023/01/14 09:36:00 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_init_table(t_psdata *psdata)
{
	int	i;
	int	j;

	psdata->table = malloc(sizeof(int *) * psdata->size);
	if (psdata->table == NULL)
		ps_quit(psdata, 1);
	i = -1;
	while (++i < psdata->size)
	{
		psdata->table[i] = malloc(sizeof(int) * psdata->size);
		if (psdata->table[i] == NULL)
			ps_quit(psdata, 1);
		j = -1;
		while (++j < psdata->size)
			psdata->table[i][j] = 0;
	}
}

void	ps_build_table(t_psdata *psdata)
{
	int	i;
	int	j;

	i = -1;
	while (++i < psdata->size)
	{
		j = -1;
		while (++j < psdata->size)
		{
			if (psdata->values[i] == psdata->sorted[j])
			{
				if (i == 0 || j == 0)
					psdata->table[i][j] = 1;
				else
					psdata->table[i][j] = psdata->table[i - 1][j - 1] + 1;
			}
			else
				psdata->table[i][j] = ps_table_max(psdata->table, i, j);
		}
	}
}

int	ps_table_max(int **table, int i, int j)
{
	if (i == 0 && j == 0)
		return (0);
	else if (i == 0)
		return (table[i][j - 1]);
	else if (j == 0)
		return (table[i - 1][j]);
	else
		return (ps_max(table[i - 1][j], table[i][j - 1]));
}
