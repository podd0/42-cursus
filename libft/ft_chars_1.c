/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chars_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:21:47 by apuddu            #+#    #+#             */
/*   Updated: 2024/03/19 20:21:49 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	return ('a' <= (c | 32) && (c | 32) <= 'z');
}

int	ft_isdigit(int c)
{
	return (c <= '9' && c >= '0');
}

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

int	ft_isascii(int c)
{
	return (c >= 0 && c < 128);
}
