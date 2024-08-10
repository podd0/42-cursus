/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:58:46 by apuddu            #+#    #+#             */
/*   Updated: 2024/08/02 17:32:46 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "vector.h"
#include <stdlib.h>

t_ps	*vi_to_ps(t_vi *vec)
{
	t_ps	*res;

	res = malloc(sizeof(t_ps));
	res->a = vi_to_deque(vec);
	res->b = malloc(sizeof(t_deque));
	res->b->back = NULL;
	res->b->front = NULL;
	res->moves = vstr_uninit(0);
	return (res);
}

void	rotate(t_deque *dq)
{
	dq_push_back(dq, dq_pop_front(dq));
}

void	rev_rotate(t_deque *dq)
{
	dq_push_front(dq, dq_pop_back(dq));
}

t_node	*node_of(int val)
{
	t_node	*res;

	res = malloc(sizeof(t_node));
	res->value = val;
	res->next = NULL;
	res->prev = NULL;
	return (res);
}

void	dq_free(t_deque *dq)
{
	while (dq->front)
	{
		free(dq_pop_front(dq));
	}
	free(dq);
}
