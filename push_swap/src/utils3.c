/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 18:04:37 by apuddu            #+#    #+#             */
/*   Updated: 2024/08/10 14:38:15 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "vector.h"
#include <stdlib.h>

void	pa(t_ps *ps)
{
	if (ps->b->front == NULL)
		abort_free_ps(ps);
	dq_push_front(ps->a, dq_pop_front(ps->b));
	vstr_push_back(ps->moves, "pa");
}

void	pb(t_ps *ps)
{
	if (ps->a->front == NULL)
		abort_free_ps(ps);
	dq_push_front(ps->b, dq_pop_front(ps->a));
	vstr_push_back(ps->moves, "pb");
}

void	from_string(t_vi *vec, char *str, int *err)
{
	char	**splitted;
	char	**it;

	splitted = ft_split(str, ' ');
	it = splitted;
	while (*it)
	{
		vi_push_back(vec, ft_atoi_check(*it, err));
		free(*it);
		it++;
	}
	free(splitted);
}

int	check_alpha(char *s)
{
	while (*s)
	{
		if (!ft_isdigit(*s) && *s != ' ' && *s != '+' && *s != '-')
			return (0);
		s++;
	}
	return (1);
}

int	check_duplicates(t_vi *vec)
{
	t_vi	*copy;
	int		i;

	i = 1;
	copy = vi_copy(vec);
	merge_sort(copy);
	while (i < copy->size)
	{
		if (copy->arr[i] == copy->arr[i - 1])
		{
			vi_free(copy);
			return (0);
		}
		i++;
	}
	vi_free(copy);
	return (1);
}
