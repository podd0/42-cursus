/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_mod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:04:52 by apuddu            #+#    #+#             */
/*   Updated: 2024/08/17 13:32:15 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_isspace(int c)
{
	return (c == ' ' || (9 <= c && c <= 13));
}

int	ft_atoi_advance(char **s)
{
	long	x;
	int		neg;

	x = 0;
	neg = 0;
	while (ft_isspace(**s))
		(*s)++;
	if (**s == '-')
	{
		(*s)++;
		neg = 1;
	}
	else if ((**s) == '+')
		(*s)++;
	while (ft_isdigit(**s))
	{
		x *= 10;
		x += **s - '0';
		(*s)++;
	}
	if (neg)
		x = -x;
	return ((int)x);
}
