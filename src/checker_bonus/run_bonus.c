/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:14:49 by rertzer           #+#    #+#             */
/*   Updated: 2023/01/15 18:34:36 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static t_ckfun	get_ckfun(enum e_ops ops)
{
	t_ckfun	funtab[OPS_MAX];

	funtab[0] = ck_ops_pa;
	funtab[1] = ck_ops_pb;
	funtab[2] = ck_ops_sa;
	funtab[3] = ck_ops_sb;
	funtab[4] = ck_ops_ss;
	funtab[5] = ck_ops_ra;
	funtab[6] = ck_ops_rb;
	funtab[7] = ck_ops_rr;
	funtab[8] = ck_ops_rra;
	funtab[9] = ck_ops_rrb;
	funtab[10] = ck_ops_rrr;
	return (funtab[ops]);
}

void	ck_run(t_ckdata *ckdata)
{
	t_ops	*ops;
	t_ckfun	ops_fun;

	ops = ckdata->ops;
	while (ops)
	{
		ops_fun = get_ckfun(ops->ops);
		ops_fun(ckdata);
		ops = ops->next;
	}
}
