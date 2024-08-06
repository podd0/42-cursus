/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:19:32 by apuddu            #+#    #+#             */
/*   Updated: 2024/08/06 20:23:07 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H 1
# include "vector.h"

# define LOCAL_SWAP 1
# define N_LOCAL_SWAP 12

struct					s_node
{
	int					value;
	struct s_node		*next;
	struct s_node		*prev;
};

typedef struct s_node	t_node;

struct					s_deque
{
	t_node				*front;
	t_node				*back;
};
typedef struct s_deque	t_deque;

struct					s_ps
{
	t_deque				*a;
	t_deque				*b;
	t_vstr				*moves;
};
typedef struct s_ps		t_ps;

struct					s_rule
{
	t_vstr				*a;
	t_vstr				*b;
};

typedef struct s_rule	t_rule;

void					merge_sort(t_vi *vec);

t_node					*node_of(int val);

void					node_detach(t_node *node);
void					node_attach_after(t_node *node, t_node *prev);
void					node_attach_before(t_node *node, t_node *prev);

void					dq_push_back(t_deque *dq, t_node *v);
void					dq_push_front(t_deque *dq, t_node *v);
t_node					*dq_pop_front(t_deque *dq);
t_node					*dq_pop_back(t_deque *dq);
void					dq_free(t_deque *dq);
t_vi					*dq_to_vi(t_deque *dq, int len);
t_deque					*vi_to_deque(t_vi *vec);
t_ps					*vi_to_ps(t_vi *vec);
t_vi					*build_vi_run_checks(int argc, char **argv);
int						subdiv(t_vi *vec, int x, int l, int r);

void					rotate(t_deque *dq);
void					rev_rotate(t_deque *dq);

void					pa(t_ps *ps);
void					pb(t_ps *ps);
void					rr(t_ps *ps);
void					ra(t_ps *ps);
void					rb(t_ps *ps);
void					rra(t_ps *ps);
void					rrb(t_ps *ps);
void					rrr(t_ps *ps);
void					sa(t_ps *ps);
void					sb(t_ps *ps);

int						check_duplicates(t_vi *vec);
void					from_string(t_vi *vec, char *str);
int						check_alpha(char *s);
int						check_duplicates(t_vi *vec);

t_vstr					*consolidate(t_vstr *moves, t_rule *rules, int n_rules);
void					build_rule(char *a, char *b, t_rule *result);
t_rule					*build_rules(void);
void					consolidate_to_fixed_point(t_ps *ps);

void					split_b(t_ps *ps, int size, int x, int top);
t_deque					*copy_n(t_deque *src, int n);
int						ft_abs(int val);
int						check_sorted(t_deque *dq, int size, int rev);
void					quick_sort_b(t_ps *ps, int size, int top);
void					quick_sort_a(t_ps *ps, int size, int top);
int						get_mid(t_deque *ls, int len);
void					rrota_n(t_ps *ps, int n);
void					rrotb_n(t_ps *ps, int n);
void					split_a(t_ps *ps, int size, int x, int top);

# define N_RULES 31
#endif
