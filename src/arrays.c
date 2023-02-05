/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrays.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:21:39 by rertzer           #+#    #+#             */
/*   Updated: 2023/02/05 15:24:17 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_nb_to_push(t_psdata *psdata)
{
	int	size;
	int	i;

	size = 0;
	i = -1;
	while (++i < psdata->size)
	{
		if (psdata->to_push[i])
			size++;
	}
	return (size);
}

int	*ps_get_sorted_array(t_psdata *psdata, int *size)
{
	int	i;
	int	j;
	int	*tpv;
	t_stack	*tmp;

	*size = ps_nb_to_push(psdata);
	tmp = psdata->stack_a;
	tpv = ps_malloc_array(psdata, *size);
	i = -1;
	j = -1;
	while (++i < psdata->size)
	{
		if (psdata->to_push[i])
			tpv[++j] = tmp->nb;
		tmp = tmp->next;
	}
	ps_sort_array(tpv, *size);
	return (tpv);
}

int	*ps_malloc_array(t_psdata *psdata, int size)
{
	int	*array;

	array = malloc(sizeof(int) * size);
	if (NULL == array)
		ps_quit(psdata, 1);
	return (array);
}

void	ps_to_array(t_psdata *psdata)
{
	int		i;

	psdata->to_push = ps_malloc_array(psdata, psdata->size);
	i = -1;
	while (++i < psdata->size)
		psdata->to_push[i] = 0;
}

void	ps_sort_array(int *tab, int size)
{
	int	j;

	while (size > 0)
	{
		size--;
		j = 0;
		while (j < size)
		{
			if (tab[j + 1] < tab[j])
				swap(&tab[j], &tab[j + 1]);
			j++;
		}
	}
}
