/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   consolidate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:38:26 by apuddu            #+#    #+#             */
/*   Updated: 2024/08/07 21:49:47 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "vector.h"
#include <stdlib.h>

void	build_rules2(t_rule *rules)
{
	build_rule("rr rra", "rb", rules + 16);
	build_rule("rr rrb", "ra", rules + 17);
	build_rule("rra rr", "rb", rules + 18);
	build_rule("rrb rr", "ra", rules + 19);
	build_rule("pb ra pa", "sa ra", rules + 20);
	build_rule("pb rra pa", "rra sa", rules + 21);
	build_rule("pa rb pb", "sb rb", rules + 22);
	build_rule("pa rrb pb", "rrb sb", rules + 23);
	build_rule("sa sa", "", rules + 24);
	build_rule("sb sb", "", rules + 25);
	build_rule("sa sb", "ss", rules + 26);
	build_rule("ra pb rra sa pa", "sa ra sa rra", rules + 27);
	build_rule("rb pa rrb sb pb", "sb rb sb rrb", rules + 28);
	build_rule("rb pa rrb pa", "sb pa pa", rules + 29);
	build_rule("ra pb rra pb", "sa pb pb", rules + 30);
}

t_rule	*build_rules(void)
{
	t_rule	*rules;

	rules = malloc(sizeof(t_rule) * N_RULES);
	build_rule("pa pb", "", rules);
	build_rule("pb pa", "", rules + 1);
	build_rule("ra rra", "", rules + 2);
	build_rule("rra ra", "", rules + 3);
	build_rule("rb rrb", "", rules + 4);
	build_rule("rrb rb", "", rules + 5);
	build_rule("rr rrr", "", rules + 6);
	build_rule("rrr rr", "", rules + 7);
	build_rule("ra rb", "rr", rules + 8);
	build_rule("rb ra", "rr", rules + 9);
	build_rule("rra rrb", "rrr", rules + 10);
	build_rule("rrb rra", "rrr", rules + 11);
	build_rule("rrr ra", "rrb", rules + 12);
	build_rule("rrr rb", "rra", rules + 13);
	build_rule("ra rrr", "rrb", rules + 14);
	build_rule("rb rrr", "rra", rules + 15);
	build_rules2(rules);
	return (rules);
}

void	freestr(char *str)
{
	free(str);
}

void	rules_free(t_rule *rules)
{
	int	i;

	i = 0;
	while (i < N_RULES)
	{
		vstr_map(rules[i].a, freestr);
		vstr_map(rules[i].b, freestr);
		vstr_free(rules[i].a);
		vstr_free(rules[i].b);
		i++;
	}
	free(rules);
}

void	consolidate_to_fixed_point(t_ps *ps)
{
	t_rule	*rules;
	t_vstr	*reduced;
	int		old_size;

	rules = build_rules();
	while (1)
	{
		old_size = ps->moves->size;
		reduced = consolidate(ps->moves, rules, N_RULES);
		vstr_free(ps->moves);
		ps->moves = reduced;
		if (reduced->size == old_size)
		{
			break ;
		}
	}
	rules_free(rules);
}
