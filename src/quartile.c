/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quartile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:29:06 by rertzer           #+#    #+#             */
/*   Updated: 2023/01/12 16:29:32 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_quartile(t_psdata *psdata)
{
	int	size;
	int	*tpv;

	tpv = ps_get_sorted_array(psdata, &size);
	psdata->quartile1 = tpv[size / 4];
	psdata->quartile2 = tpv[size / 2];
	psdata->quartile3 = tpv[3 * size / 4];
	free(tpv);
}

void	ps_mediane(t_psdata *psdata)
{
	int	size;
	int	*tpv;

	tpv = ps_get_sorted_array(psdata, &size);
	psdata->quartile1 = tpv[size / 2];
	psdata->quartile2 = tpv[size / 2];
	psdata->quartile3 = tpv[size / 2];
	free(tpv);
}
