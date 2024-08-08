/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   consolidate2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 20:08:04 by apuddu            #+#    #+#             */
/*   Updated: 2024/08/07 21:55:59 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "vector.h"
#include <stdlib.h>

void	apply_rule(t_vstr *moves, t_rule *rule)
{
	int	i;

	i = 0;
	while (i < rule->a->size)
	{
		i++;
		free(vstr_back(moves));
		vstr_pop_back(moves);
	}
	i = 0;
	while (i < rule->b->size)
	{
		vstr_push_back(moves, ft_strdup(rule->b->arr[i]));
		i++;
	}
}

int	check_rules(t_vstr *moves, t_rule *rules, int n_rules)
{
	int	i;

	while (n_rules)
	{
		if (rules->a->size <= moves->size)
		{
			i = 0;
			while (1)
			{
				if (ft_strncmp(rules->a->arr[i], moves->arr[moves->size
							- rules->a->size + i], 3))
					break ;
				i++;
				if (i == rules->a->size)
				{
					apply_rule(moves, rules);
					return (1);
				}
			}
		}
		rules++;
		n_rules--;
	}
	return (0);
}

t_vstr	*consolidate(t_vstr *moves, t_rule *rules, int n_rules)
{
	int		i;
	t_vstr	*res;

	res = vstr_uninit(0);
	i = 0;
	while (i < moves->size)
	{
		vstr_push_back(res, moves->arr[i]);
		while (check_rules(res, rules, n_rules))
		{
		}
		i++;
	}
	return (res);
}

t_vstr	*from_split(char *s)
{
	t_vstr	*res;
	char	**split;
	char	**split_copy;

	res = vstr_uninit(0);
	split = ft_split(s, ' ');
	split_copy = split;
	while (*split)
	{
		vstr_push_back(res, ft_strdup(*split));
		free(*split);
		split++;
	}
	free(split_copy);
	return (res);
}

void	build_rule(char *a, char *b, t_rule *result)
{
	result->a = from_split(a);
	result->b = from_split(b);
}
