/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 04:03:31 by apuddu            #+#    #+#             */
/*   Updated: 2024/08/06 20:22:25 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "vector.h"
#include <stdlib.h>
#include <unistd.h>

void	putstr(char *str)
{
	ft_putendl_fd(str, 1);
}

int	main(int argc, char **argv)
{
	t_vi	*vec;
	t_ps	*ps;

	if (argc >= 2)
	{
		vec = build_vi_run_checks(argc, argv);
		ps = vi_to_ps(vec);
		quick_sort_a(ps, vec->size, 0);
		consolidate_to_fixed_point(ps);
		dq_free(ps->a);
		dq_free(ps->b);
		vstr_map(ps->moves, putstr);
		vstr_free(ps->moves);
		free(ps);
		vi_free(vec);
	}
}
