/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 20:12:44 by apuddu            #+#    #+#             */
/*   Updated: 2024/08/07 22:08:27 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "vector.h"
#include <stdlib.h>

void	rrr(t_ps *ps)
{
	rev_rotate(ps->b);
	rev_rotate(ps->a);
	vstr_push_back(ps->moves, "rrr");
}

void	sa(t_ps *ps)
{
	int		t;
	t_node	*front;

	front = ps->a->front;
	if (front == NULL || front->next == NULL)
		abort_free_ps(ps);
	t = front->value;
	front->value = front->next->value;
	front->next->value = t;
	vstr_push_back(ps->moves, "sa");
}

void	sb(t_ps *ps)
{
	int		t;
	t_node	*front;

	front = ps->b->front;
	if (front == NULL || front->next == NULL)
		abort_free_ps(ps);
	t = front->value;
	front->value = front->next->value;
	front->next->value = t;
	vstr_push_back(ps->moves, "sb");
}

void	ps_free(t_ps *ps)
{
	dq_free(ps->a);
	dq_free(ps->b);
	vstr_free(ps->moves);
	free(ps);
}

void	abort_free_ps(t_ps *ps)
{
	ps_free(ps);
	ft_putendl_fd("Error", 2);
	exit(1);
}
