/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 20:10:55 by apuddu            #+#    #+#             */
/*   Updated: 2024/08/10 17:24:44 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "vector.h"
#include <stdlib.h>
#include <unistd.h>

t_vi	*build_vi_run_checks(int argc, char **argv)
{
	t_vi	*vec;
	int		i;
	int		err;

	i = 1;ù
	err = 0;
	vec = vi_uninit(0);
	while (i < argc)
	{
		if (!check_alpha(argv[i]))
		{
			ft_putstr_fd("Error\n", 2);
			vi_free(vec);
			exit(1);
		}
		from_string(vec, argv[i], &err);
		i++;
	}
	if (err || !check_duplicates(vec))
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

int	ft_atoi_check_inner(const char *s, int *err, int neg)
{
	long	num;

	num = 0;
	if (!ft_isdigit(*s))
	{
		*err = 1;
		return (0);
	}
	while (ft_isdigit(*s))
	{
		num = num * 10 + *s - '0';
		if (num > (2147483647l + neg))
			*err = 1;
		s++;
	}
	if (*s)
		*err = 1;
	if (*err)
		return (0);
	if (neg)
		return ((int)-num);
	return ((int)num);
}

int	ft_atoi_check(const char *s, int *err)
{
	int	neg;

	neg = 0;
	while (*s == ' ' || (9 <= *s && *s <= 13))
		s++;
	if (*s == '-')
	{
		s++;
		neg = 1;
	}
	else if (*s == '+')
		s++;
	return (ft_atoi_check_inner(s, err, neg));
}
