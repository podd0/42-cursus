/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 17:38:34 by apuddu            #+#    #+#             */
/*   Updated: 2024/08/06 20:06:56 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "vector.h"
#include <stdlib.h>

void	node_detach(t_node *node)
{
	if (node->next)
	{
		node->next->prev = node->prev;
	}
	if (node->prev)
	{
		node->prev->next = node->next;
	}
	node->next = NULL;
	node->prev = NULL;
}

void	node_attach_after(t_node *node, t_node *prev)
{
	if (!prev)
	{
		node->next = NULL;
		node->prev = NULL;
		return ;
	}
	node->next = prev->next;
	node->prev = prev;
	if (prev->next)
	{
		prev->next->prev = node;
	}
	prev->next = node;
}

void	node_attach_before(t_node *node, t_node *next)
{
	if (!next)
	{
		node->next = NULL;
		node->prev = NULL;
		return ;
	}
	node->next = next;
	node->prev = next->prev;
	if (node->prev)
	{
		node->prev->next = node;
	}
}
