/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 14:45:54 by apuddu            #+#    #+#             */
/*   Updated: 2024/08/10 14:46:26 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "vector.h"
#include <stdlib.h>
#include <unistd.h>

void	print_dq(t_deque *dq)
{
	t_node	*curr;

	curr = dq->front;
	while (curr)
	{
		ft_printf("%d ", curr->value);
		curr = curr->next;
	}
	ft_printf("\n");
}

void	print_ps(t_ps *ps)
{
	ft_printf("a: ");
	print_dq(ps->a);
	ft_printf("b: ");
	print_dq(ps->b);
}
