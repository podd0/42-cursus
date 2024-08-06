/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 20:12:44 by apuddu            #+#    #+#             */
/*   Updated: 2024/08/06 20:12:47 by apuddu           ###   ########.fr       */
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
	t = front->value;
	front->value = front->next->value;
	front->next->value = t;
	vstr_push_back(ps->moves, "sb");
}
