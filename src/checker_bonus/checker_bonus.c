/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 11:38:08 by rertzer           #+#    #+#             */
/*   Updated: 2023/01/15 18:26:50 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ck_init_data(t_ckdata *ckdata)
{
	ckdata->stack_a = NULL;
	ckdata->stack_b = NULL;
	ckdata->arg_lst = NULL;
	ckdata->ops = NULL;
}

int	main(int argc, char **argv)
{
	t_ckdata	ckdata;

	ck_init_data(&ckdata);
	ck_load_stack(&ckdata, argc, argv);
	ck_get_stdin(&ckdata);
	ck_run(&ckdata);
	ck_check(&ckdata);
	ck_quit(&ckdata, 0);
	return (0);
}
