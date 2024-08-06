/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:19:09 by apuddu            #+#    #+#             */
/*   Updated: 2024/08/02 18:19:09 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "vector.h"
#include <stdlib.h>
#include <unistd.h>

int	vi_back(t_vi *vec)
{
	return (vec->arr[vec->size - 1]);
}
