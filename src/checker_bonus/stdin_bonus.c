/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 13:30:25 by rertzer           #+#    #+#             */
/*   Updated: 2023/01/15 18:15:39 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ck_get_stdin(t_ckdata *ckdata)
{
	char		*line;
	enum e_ops	ops;

	line = get_next_line(0);
	while (line)
	{
		ops = ck_get_ops(ckdata, line);
		free(line);
		ck_ops_add(ckdata, ops);
		line = get_next_line(0);
	}
}

char	**ck_valid_lines(t_ckdata *ckdata)
{
	char	**valid;

	valid = \
		ft_split("pa\n pb\n sa\n sb\n ss\n ra\n rb\n rr\n rra\n rrb\n rrr\n"\
		, ' ');
	if (NULL == valid)
		ck_quit(ckdata, 1);
	return (valid);
}

enum e_ops	ck_get_ops(t_ckdata *ckdata, char *line)
{
	int		i;
	char	**valid;

	i = -1;
	valid = ck_valid_lines(ckdata);
	while (++i < OPS_MAX)
	{
		if (0 == ft_strncmp(line, valid[i], 5))
			break ;
	}
	ft_flush_split(valid);
	if (i == OPS_MAX)
		ck_quit(ckdata, 1);
	return ((enum e_ops)i);
}
