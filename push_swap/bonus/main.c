/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:46:44 by apuddu            #+#    #+#             */
/*   Updated: 2024/08/07 21:50:42 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

void	do_op_2(char *op, t_ps *ps)
{
	if (!ft_strncmp("ss\n", op, 3))
	{
		sa(ps);
		sb(ps);
	}
	else
		abort_free_ps(ps);
}

void	do_op(char *op, t_ps *ps)
{
	if (!ft_strncmp("pa\n", op, 3))
		pa(ps);
	else if (!ft_strncmp("pb\n", op, 3))
		pb(ps);
	else if (!ft_strncmp("ra\n", op, 3))
		ra(ps);
	else if (!ft_strncmp("rb\n", op, 3))
		rb(ps);
	else if (!ft_strncmp("rr\n", op, 3))
		rr(ps);
	else if (!ft_strncmp("sa\n", op, 3))
		sa(ps);
	else if (!ft_strncmp("sb\n", op, 3))
		sb(ps);
	else if (!ft_strncmp("rra\n", op, 4))
		rra(ps);
	else if (!ft_strncmp("rrb\n", op, 4))
		rrb(ps);
	else if (!ft_strncmp("rrr\n", op, 4))
		rrr(ps);
	else
		do_op_2(op, ps);
}

int	main(int argc, char **argv)
{
	t_vi	*vec;
	t_ps	*ps;
	char	*op;
	int		size;

	if (argc >= 2)
	{
		vec = build_vi_run_checks(argc, argv);
		ps = vi_to_ps(vec);
		size = vec->size;
		vi_free(vec);
		op = get_next_line(0);
		while (op)
		{
			do_op(op, ps);
			op = get_next_line(0);
		}
		if (ps->b->front || !check_sorted(ps->a, size, 0))
			ft_printf("KO\n");
		else
			ft_printf("OK\n");
	}
}
