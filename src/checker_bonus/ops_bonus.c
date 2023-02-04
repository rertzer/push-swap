/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:06:40 by rertzer           #+#    #+#             */
/*   Updated: 2023/01/15 16:42:45 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ck_ops_add(t_ckdata *ckdata, enum e_ops ops)
{
	t_ops	*new;
	t_ops	*last;

	new = malloc(sizeof(t_ops));
	if (NULL == new)
		ck_quit(ckdata, 1);
	new->next = NULL;
	new->ops = ops;
	if (ckdata->ops == NULL)
		ckdata->ops = new;
	else
	{
		last = ckdata->ops;
		while (last->next != NULL)
			last = last->next;
		last->next = new;
	}
}
