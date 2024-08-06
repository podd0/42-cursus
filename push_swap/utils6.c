/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 20:10:55 by apuddu            #+#    #+#             */
/*   Updated: 2024/08/06 20:16:22 by apuddu           ###   ########.fr       */
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

t_vi	*build_vi_run_checks(int argc, char **argv)
{
	t_vi	*vec;
	int		i;

	i = 1;
	vec = vi_uninit(0);
	while (i < argc)
	{
		if (!check_alpha(argv[i]))
		{
			ft_putstr_fd("Error\n", 2);
			vi_free(vec);
			exit(1);
		}
		from_string(vec, argv[i]);
		i++;
	}
	if (!check_duplicates(vec))
	{
		ft_putstr_fd("Error\n", 2);
		vi_free(vec);
		exit(1);
	}
	return (vec);
}

t_vi	*dq_to_vi(t_deque *dq, int len)
{
	t_vi	*res;
	t_node	*ptr;

	ptr = dq->front;
	res = vi_uninit(0);
	while (len)
	{
		vi_push_back(res, ptr->value);
		ptr = ptr->next;
		len--;
	}
	return (res);
}

int	subdiv(t_vi *vec, int x, int l, int r)
{
	int	t;

	while (l < r)
	{
		while (vec->arr[l] < x)
			l++;
		while (vec->arr[r] > x)
			r--;
		t = vec->arr[l];
		vec->arr[l] = vec->arr[r];
		vec->arr[r] = t;
	}
	return (l);
}
