/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplify.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 09:19:07 by rertzer           #+#    #+#             */
/*   Updated: 2023/02/12 10:14:00 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	ps_simplify_del_two(t_psdata *psdata, char *first, char *second)
{
	char	**sm;
	int		len;
	int		i;

	sm = psdata->small_moves;
	len = 0;
	while (sm[len] != NULL)
		len++;
	i = -1;
	while (++i < 11)
	{
		if (sm[i] && sm[i + 1] && !ft_strcmp(sm[i], first) \
								&& !ft_strcmp(sm[i + 1], second))
			ps_simplify_shift(sm, i, 2);
	}
}

void ps_simplify_shift(char **sm, int start, int offset)
{
	int	j;
	int	len;

	len = 0;
	while (sm[len] != NULL)
		len++;

	j = -1;
	while (++j < len - (start + offset))
			sm[start + j] = sm [start + j + offset];
	while (start + j < len)
	{
		sm[start + j] = NULL;
		j++;
	}
}

void	ps_simplify(t_psdata *psdata)
{
	int		i;
	int		len;
	char	**sm;

	ps_simplify_del_two(psdata, "rra", "ra");
	ps_simplify_del_two(psdata, "ra", "rra");
	ps_simplify_del_two(psdata, "pb", "pa");
	ps_simplify_del_two(psdata, "pb", "pa");
	sm = psdata->small_moves;
	len = 0;
	while (sm[len] != NULL)
		len++;
	i = -1;
	while (++i < 10)
	{
		if (sm[i] && sm[i + 1] && sm[i + 2] && !ft_strncmp(sm[i], "ra", 4) \
				&& !ft_strncmp(sm[i + 1], "pa", 4) \
				&& !ft_strncmp(sm[i + 2], "rra", 4))
		{
			sm[i] = "pa";
			sm[i + 1] = "sa";
			ps_simplify_shift(sm, i + 2, 1);
		}
	}
}
