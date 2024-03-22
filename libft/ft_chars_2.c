/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chars_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:21:59 by apuddu            #+#    #+#             */
/*   Updated: 2024/03/19 20:22:01 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (ft_isalpha(c))
		return (c & (~32));
	return (c);
}

int	ft_tolower(int c)
{
	if (ft_isalpha(c))
		return (c | 32);
	return (c);
}
