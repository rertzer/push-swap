/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:11:54 by rertzer           #+#    #+#             */
/*   Updated: 2023/01/15 18:21:25 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ck_quit(t_ckdata *ckdata, int error)
{
	if (error)
		ft_putendl_fd("Error", 2);
	ps_stack_clear(&(ckdata->stack_a));
	ps_stack_clear(&(ckdata->stack_b));
	ck_clean_ops(ckdata);
	ck_clean_arg_lst(ckdata);
	exit(error);
}

void	ck_clean_ops(t_ckdata *ckdata)
{
	t_ops	*tmp;
	t_ops	*ops;

	ops = ckdata->ops;
	while (ops)
	{
		tmp = ops->next;
		free(ops);
		ops = tmp;
	}
}

void	ck_clean_arg_lst(t_ckdata *ckdata)
{
	int	i;

	if (NULL == ckdata->arg_lst)
		return ;
	i = -1;
	while (NULL != ckdata->arg_lst[++i])
		free(ckdata->arg_lst[i]);
	free(ckdata->arg_lst);
	ckdata->arg_lst = NULL;
}
