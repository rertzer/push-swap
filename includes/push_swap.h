/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:35:07 by rertzer           #+#    #+#             */
/*   Updated: 2023/01/15 18:35:34 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <string.h>
# include <errno.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				nb;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

typedef struct s_psdata
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size_a;
	int		size_b;
	int		quartile1;
	int		quartile2;
	int		quartile3;
	t_stack	*next2move;
	t_stack	*smallest_a;
	int		index;
	int		size;
	int		*values;
	int		*sorted;
	int		*to_push;
	int		**table;
	char	**arg_lst;
}	t_psdata;

typedef void	(*t_fun)(t_psdata *psdata);

/* main */
void		ps_init_psdata(t_psdata *psdata);
void		ps_stack_already_sorted(t_psdata *psdata);
/* parsing */
void		ps_load_stack(t_psdata *psdata, int argc, char **argv);
int			ps_atoi(t_psdata *psdata, char *str);
/* run */
void		ps_run(t_psdata *psdata);
void		ps_run_medium(t_psdata *psdata);
void		ps_run_large(t_psdata *psdata);
/* run little */
void		ps_run_small(t_psdata *psdata);
void		ps_run_two(t_psdata *psdata);
void		ps_run_three(t_psdata *psdata);
/* quartile */
void		ps_quartile(t_psdata *psdata);
void		ps_mediane(t_psdata *psdata);
/* arrays */
int			*ps_get_sorted_array(t_psdata *psdata, int *size);
int			*ps_malloc_array(t_psdata *psdata, int size);
void		ps_to_array(t_psdata *psdata);
void		ps_sort_array(int *tab, int size);
/* table*/
void		ps_init_table(t_psdata *psdata);
void		ps_build_table(t_psdata *psdata);
int			ps_table_max(int **table, int i, int j);
/* push swap */
void		ps_first_top(t_psdata *psdata);
void		ps_split_values(t_psdata *psdata);
/* to_push */
void		ps_push_to_b(t_psdata *psdata);
void		ps_compute_to_push(t_psdata *psdata);
void		ps_assemble_to_push(t_psdata *psdata, int i, int j);
/* insert back */
void		ps_insert_back(t_psdata *psdata);
void		ps_insert_back_next(t_psdata *psdata);
int			ps_calculate_min_steps(t_psdata *psdata, t_stack *tmp, int index);
int			ps_get_insert_index(t_psdata *psdata, int nb);
/* insert back strat */
void		ps_insert_back_strat_zero(t_psdata *psdata);
void		ps_insert_back_strat_one(t_psdata *psdata);
void		ps_insert_back_strat_two(t_psdata *psdata);
void		ps_insert_back_strat_three(t_psdata *psdata);
/* stack */
void		ps_stack_add_back(t_psdata *psdata, t_stack **stack, int nb);
t_stack		*ps_stack_new(t_psdata *psdata, int nb);
t_stack		*ps_stack_last(t_stack *stack);
t_stack		*ps_stack_next(t_stack *tmp, t_stack *stack);
int			ps_stack_size(t_stack *stack);
/* min max */
void		swap(int *a, int *b);
int			ps_max(int a, int b);
int			ps_min_strat(int *tab, int size);
t_stack		*ps_get_insert_floor(t_psdata *psdata, int nb);
void		ps_set_smallest_a(t_psdata *psdata);
/* ops swap */
void		ps_ops_sa(t_psdata *psdata);
void		ps_ops_sb(t_psdata *psdata);
void		ps_ops_ss(t_psdata *psdata);
/* ops push */
void		ps_ops_pa(t_psdata *psdata);
void		ps_ops_pb(t_psdata *psdata);
/* ops rotate */
void		ps_ops_ra(t_psdata *psdata);
void		ps_ops_rb(t_psdata *psdata);
void		ps_ops_rr(t_psdata *psdata);
/* ops reverse */
void		ps_ops_rra(t_psdata *psdata);
void		ps_ops_rrb(t_psdata *psdata);
void		ps_ops_rrr(t_psdata *psdata);
/* exit */
void		ps_quit(t_psdata *psdata, int error);
void		ps_flush_arrays(t_psdata *psdata);
void		ps_clean_arg_lst(t_psdata *psdata);
void		ps_stack_clear(t_stack **stack);
/* print.c */
void		ps_print(t_psdata *psdata);
void		ps_stack_print(t_stack *stack);
#endif