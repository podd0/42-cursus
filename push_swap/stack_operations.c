/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:07:26 by apuddu            #+#    #+#             */
/*   Updated: 2024/08/06 20:12:27 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "vector.h"
#include <stdlib.h>

void	ra(t_ps *ps)
{
	rotate(ps->a);
	vstr_push_back(ps->moves, "ra");
}

void	rb(t_ps *ps)
{
	rotate(ps->b);
	vstr_push_back(ps->moves, "rb");
}

void	rr(t_ps *ps)
{
	rotate(ps->b);
	rotate(ps->a);
	vstr_push_back(ps->moves, "rr");
}

void	rra(t_ps *ps)
{
	rev_rotate(ps->a);
	vstr_push_back(ps->moves, "rra");
}

void	rrb(t_ps *ps)
{
	rev_rotate(ps->b);
	vstr_push_back(ps->moves, "rrb");
}
