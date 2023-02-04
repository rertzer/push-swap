/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrays.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:21:39 by rertzer           #+#    #+#             */
/*   Updated: 2023/01/14 11:12:42 by rertzer          ###   ########.fr       */
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

	*size = ps_nb_to_push(psdata);
	tpv = ps_malloc_array(psdata, *size);
	i = -1;
	j = -1;
	while (++i < psdata->size)
	{
		if (psdata->to_push[i])
			tpv[++j] = psdata->values[i];
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
	t_stack	*tmp;

	psdata->values = ps_malloc_array(psdata, psdata->size);
	psdata->sorted = ps_malloc_array(psdata, psdata->size);
	psdata->to_push = ps_malloc_array(psdata, psdata->size);
	tmp = psdata->stack_a;
	i = -1;
	while (++i < psdata->size)
	{
		psdata->values[i] = tmp->nb;
		psdata->sorted[i] = tmp->nb;
		psdata->to_push[i] = 1;
		tmp = tmp->next;
	}
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
