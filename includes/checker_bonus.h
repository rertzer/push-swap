/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 18:31:34 by rertzer           #+#    #+#             */
/*   Updated: 2023/01/15 18:35:11 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "push_swap.h"

# define OPS_MAX 11

enum	e_ops {pa, pb, sa, sb, ss, ra, rb, rr, rra, rrb, rrr};

typedef struct s_ops
{
	enum e_ops		ops;
	struct s_ops	*next;
}	t_ops;

typedef struct s_ckdata
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_ops	*ops;
	char	**arg_lst;
}	t_ckdata;

typedef void	(*t_ckfun)(t_ckdata *);

/* main */
void		ck_init_data(t_ckdata *ckdata);
/* parsing */
void		ck_load_stack(t_ckdata *ckdata, int argc, char **argv);
/* stack */
void		ck_stack_add_back(t_ckdata *ckdata, t_stack **stack, int nb);
t_stack		*ck_stack_new(t_ckdata *ckdata, int nb);
t_stack		*ck_stack_last(t_stack *stack);
int			ck_stack_size(t_stack *stack);
t_stack		*ck_stack_next(t_stack *tmp, t_stack *stack);
/* ops */
void		ck_ops_add(t_ckdata *ckdata, enum e_ops ops);

/* stdin */
void		ck_get_stdin(t_ckdata *ckdata);
char		**ck_valid_lines(t_ckdata *ckdata);
enum e_ops	ck_get_ops(t_ckdata *ckdata, char *line);
/* run */
void		ck_run(t_ckdata *ckdata);
/* check */
void		ck_check(t_ckdata *ckdata);
int			ck_check_stack_a(t_ckdata *ckdata);
int			ck_check_stack_b(t_ckdata *ckdata);
/* ops swap */
void		ck_ops_sa(t_ckdata *ckdata);
void		ck_ops_sb(t_ckdata *ckdata);
void		ck_ops_ss(t_ckdata *ckdata);
/* ops push */
void		ck_ops_pa(t_ckdata *ckdata);
void		ck_ops_pb(t_ckdata *ckdata);
/* ops rotate */
void		ck_ops_ra(t_ckdata *ckdata);
void		ck_ops_rb(t_ckdata *ckdata);
void		ck_ops_rr(t_ckdata *ckdata);
/* ops reverse */
void		ck_ops_rra(t_ckdata *ckdata);
void		ck_ops_rrb(t_ckdata *ckdata);
void		ck_ops_rrr(t_ckdata *ckdata);
/* exit */
void		ck_quit(t_ckdata *ckdata, int i);
void		ck_clean_ops(t_ckdata *ckdata);
void		ck_clean_arg_lst(t_ckdata *ckdata);
#endif
