/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:55:57 by apuddu            #+#    #+#             */
/*   Updated: 2024/08/05 00:20:22 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "vector.h"
#include <stdlib.h>

void	dq_push_back(t_deque *dq, t_node *v)
{
	v->prev = dq->back;
	v->next = NULL;
	if (dq->back)
		dq->back->next = v;
	dq->back = v;
	if (!dq->front)
		dq->front = v;
}

void	dq_push_front(t_deque *dq, t_node *v)
{
	v->next = dq->front;
	v->prev = NULL;
	if (dq->front)
		dq->front->prev = v;
	dq->front = v;
	if (!dq->back)
		dq->back = v;
}

t_node	*dq_pop_front(t_deque *dq)
{
	t_node	*res;

	res = dq->front;
	if (res)
	{
		dq->front = res->next;
		res->next = NULL;
		res->prev = NULL;
		if (dq->front)
		{
			dq->front->prev = NULL;
		}
		else
			dq->back = NULL;
	}
	return (res);
}

t_node	*dq_pop_back(t_deque *dq)
{
	t_node	*res;

	res = dq->back;
	if (res)
	{
		dq->back = res->prev;
		res->next = NULL;
		res->prev = NULL;
		if (dq->back)
		{
			dq->back->next = NULL;
		}
		else
			dq->front = NULL;
	}
	return (res);
}

t_deque	*vi_to_deque(t_vi *vec)
{
	t_deque	*res;
	int		i;

	i = 0;
	res = malloc(sizeof(t_deque));
	res->back = NULL;
	res->front = NULL;
	while (i < vec->size)
	{
		dq_push_back(res, malloc(sizeof(t_node)));
		res->back->value = vec->arr[i];
		i++;
	}
	return (res);
}
